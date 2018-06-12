//
//  ViewController.swift
//  MobileNetApp-MLKit
//
//  Created by GwakDoyoung on 01/06/2018.
//  Copyright © 2018 GwakDoyoung. All rights reserved.
//

import UIKit
import Firebase

class ViewController: UIViewController, VideoCaptureDelegate {
    
    // MARK: - UI 프로퍼티
    
    @IBOutlet weak var videoPreview: UIView!
    @IBOutlet weak var labelLabel: UILabel!
    @IBOutlet weak var confidenceLabel: UILabel!
    
    
    
    var interpreter: ModelInterpreter?
    var ioOptions: ModelInputOutputOptions?
    
    // MARK: - AV 프로퍼티
    
    var videoCapture: VideoCapture!
    let semaphore = DispatchSemaphore(value: 2)
    
    
    // MARK: - 라이프사이클 메소드

    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        // 모델 로드
        guard let modelPath = Bundle.main.path(
            forResource: "mobilenet_quant_v1_224",
            ofType: "tflite"
            ) else {
                // Invalid model path
                return
        }
        let localModelSource = LocalModelSource(modelName: "mobilenet_quant_v1_224",
                                                path: modelPath)
        let registrationSuccessful = ModelManager.modelManager().register(localModelSource)
        
        
        
        
        let options = ModelOptions(
            cloudModelName: nil,
            localModelName: "mobilenet_quant_v1_224"
        )
        interpreter = ModelInterpreter(options: options)
        
        
        
        
        
        // 모델의 입력 및 출력 지정
        let ioOptions = ModelInputOutputOptions()
        do {
            try ioOptions.setInputFormat(index: 0, type: .uInt8, dimensions: [1, 224, 224, 3])
            try ioOptions.setOutputFormat(index: 0, type: .float32, dimensions: [1, 1000])
        } catch let error as NSError {
            print("Failed to set input or output format with error: \(error.localizedDescription)")
        }
        
        
        
        
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
        
        
//        let input = ModelInputs()
//        do {
//            var data: Data = Data(base64Encoded: <#T##Data#>)
//            // Store input data in `data`
//            // ...
//            try input.addInput(data)
//            // Repeat as necessary for each input index
//        } catch let error as NSError {
//            print("Failed to add input: \(error.localizedDescription)")
//        }
//        if let interpreter = self.interpreter, let ioOptions = self.ioOptions {
//            interpreter.run(inputs: input, options: ioOptions) { outputs, error in
//                guard error == nil, let outputs = outputs else { return }
//                // Process outputs
//                // ...
//            }
//        }
        
    }

    
    func showResults(identifier: String, confidence: Float) {
        
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

