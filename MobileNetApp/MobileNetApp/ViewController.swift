//
//  ViewController.swift
//  MobileNetApp
//
//  Created by GwakDoyoung on 28/05/2018.
//  Copyright © 2018 GwakDoyoung. All rights reserved.
//

import UIKit
import CoreML
import Vision

class ViewController: UIViewController, VideoCaptureDelegate {
    
    // MARK: - UI 프로퍼티
    
    @IBOutlet weak var videoPreview: UIView!
    @IBOutlet weak var labelLabel: UILabel!
    @IBOutlet weak var confidenceLabel: UILabel!
    
    
    
    var coremlModel: MobileNet? = nil
    

    // MARK: - Vision 프로퍼티
    
    var request: VNCoreMLRequest!
    var visionModel: VNCoreMLModel! {
        didSet {
            request = VNCoreMLRequest(model: visionModel, completionHandler: visionRequestDidComplete)
            // NOTE: If you choose another crop/scale option, then you must also
            // change how the BoundingBox objects get scaled when they are drawn.
            // Currently they assume the full input image is used.
            request.imageCropAndScaleOption = .scaleFill
        }
    }
    
    
    // MARK: - AV 프로퍼티
    
    var videoCapture: VideoCapture!
    let semaphore = DispatchSemaphore(value: 2)
    
    
    // MARK: - 라이프사이클 메소드
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // MobileNet 클래스는 `MobileNet.mlmodel`를 프로젝트에 넣고, 빌드시키면 자동으로 생성된 랩퍼 클래스
        // MobileNet에서 만든 model: MLModel 객체로 (Vision에서 사용할) VNCoreMLModel 객체를 생성
        // Vision은 모델의 입력 크기(이미지 크기)에 따라 자동으로 조정해 줌
        visionModel = try? VNCoreMLModel(for: MobileNet().model)
        
        // 카메라 세팅
        setUpCamera()
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    // MARK: - 초기 세팅
    
    func setUpCamera() {
        videoCapture = VideoCapture()
        videoCapture.delegate = self
        videoCapture.fps = 50
        videoCapture.setUp(sessionPreset: .vga640x480) { success in
            
            if success {
                // UI에 비디오 미리보기 뷰 넣기
                if let previewLayer = self.videoCapture.previewLayer {
                    self.videoPreview.layer.addSublayer(previewLayer)
                    self.resizePreviewLayer()
                }
                
                // 초기설정이 끝나면 라이브 비디오를 시작할 수 있음
                self.videoCapture.start()
            }
        }
    }
    
    func resizePreviewLayer() {
        videoCapture.previewLayer?.frame = videoPreview.bounds
    }
    
    
    
    // MARK: - 추론하기
    
    func predictUsingVision(pixelBuffer: CVPixelBuffer) {
        
        // Vision이 입력이미지를 자동으로 크기조정을 해줄 것임.
        let handler = VNImageRequestHandler(cvPixelBuffer: pixelBuffer)
        try? handler.perform([request])
    }
    
    func visionRequestDidComplete(request: VNRequest, error: Error?) {
        guard let results = request.results as? [VNClassificationObservation] else { return }
        guard let firstResult = results.first else {return}
        
        // 메인큐에서 결과 출력
        DispatchQueue.main.async {
            self.showResults(identifier: "\(firstResult.identifier)".capitalized,
                             confidence: firstResult.confidence)
        }
    }
    
    func showResults(identifier: String, confidence: VNConfidence) {
        
        self.labelLabel.text = identifier
        self.confidenceLabel.text = "\(round(confidence * 100)) %"
        
        self.semaphore.signal()
        
    }
    
    
    // MARK: - VideoCaptureDelegate
    
    func videoCapture(_ capture: VideoCapture, didCaptureVideoFrame pixelBuffer: CVPixelBuffer?/*, timestamp: CMTime*/) {
        
        // 비디오 캡쳐 큐에서 실행된 videoCapture(::) 메소드는 멈추기
        // 추론하는 동안은 메인스레드로 이동하여 처리
        semaphore.wait()
        
        // 카메라에서 캡쳐된 화면은 pixelBuffer에 담김.
        // Vision 프레임워크에서는 이미지 대신 pixelBuffer를 바로 사용 가능
        if let pixelBuffer = pixelBuffer {
            // 추론은 메인스레드에서 실행시키며
            // 추론 결과값 출력도 메인스레드에서 처리 후,
            // 멈춘 스레드를 풀어줌(semaphore.signal())
            DispatchQueue.main.async {
                self.predictUsingVision(pixelBuffer: pixelBuffer)
            }
        }
    }


}

