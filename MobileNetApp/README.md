# MobileNetApp for iOS

![DEMO](https://github.com/MachineLearningOfThings/mot-ios-tensorflow/blob/master/demo/MobileNetApp_test001.gif?raw=true)

## 필요환경

- Xcode 9.2+
- iOS 11.0+
- Swift 4.1

## 준비물

- Core ML용 MobileNet 모델(`MobileNet.mlmodel`)
  ☞ [애플 홈페이지](https://developer.apple.com/kr/machine-learning/)에 가서 MobileNet 다운

> MobileNet는 깊이 전반에 관해 분리 가능한 컨볼루션이 있는 간결한 아키텍처를 기반으로 경량의 심층 신경망을 구축합니다. 
> 이미지에서 나무, 동물, 음식, 교통 수단, 사람 등 1000개의 카테고리로 나타나는 주요 물체를 감지합니다.
>
> − 애플 머신러닝 홈페이지 MobileNet 설명

## 빌드 준비

### 모델 가져오기

![모델 불러오기.png](https://github.com/MachineLearningOfThings/mot-ios-tensorflow/blob/master/MobileNetApp/resource/%EB%AA%A8%EB%8D%B8%20%EB%B6%88%EB%9F%AC%EC%98%A4%EA%B8%B0.png?raw=true)

모델을 넣으셨으면 자동으로 모델 이름의 파일이 빌드경로 어딘가에 생성됩니다. 모델을 사용할때는 경로로 접근하는 것이 아니라 모델 클래스로 객체를 생성하여 접근할 수 있습니다.

## 코드 작성

### 카메라 캡쳐 기능

https://github.com/eugenebokhan/Awesome-ML의 `VideoCapture ` 클래스를 사용했습니다. `VideoCapture.swift` 파일을 가져와서 `VideoCapture` 를 사용하여 쉽게 카메라에 접근합니다.

또한 `프로젝트 > TARGETS > PROJECT > Info`에서 `Privacy - Camera Usage Description` 열을 설명과함께 추가합니다.

### Core ML 사용하기

1. 모델 객체를 생성, 완료 핸들러를 만듭니다.
2. 요청 객체를 만드는데, 파라미터로 모델 객체와 완료 핸들러를 전달합니다.
3. 요청 핸들러 객체를 만들고 비디오캡쳐 콜백 메소드에서 받아낸 이미지(이 예제에서는 `pixelBuffer`)를 전달합니다.
4. 요청 핸들러의 `.perform` 메소드를 실행하면 추론을 시작합니다.
5. 추론이 끝나면 아까 등록한 결과와함께 완료 핸들러가 호출됩니다.
6. 결과를 받아 후처리를 하여 사용자에게 출력합니다.

#### Core ML 불러오기
```swift
import CoreML
import Vision
```

#### 모델 객체 생성

```swift
let visionModel = try? VNCoreMLModel(for: MobileNet().model)
```

#### 완료 핸들러

```swift
func visionRequestDidComplete(request: VNRequest, error: Error?) {

    guard let results = request.results as? [VNClassificationObservation] else { return }
    guard let firstResult = results.first else {return}
    
    //
    //
    // 완료 후 처리 부분
    //
    //
    
    // 완료 처리 후 비디오캡쳐큐를 다시 실행
    self.semaphore.signal()
}
```

#### 요청 객체 생성
```swift
let request = VNCoreMLRequest(model: visionModel, completionHandler: visionRequestDidComplete)
```

#### 추론!

```swift
// MARK: - VideoCaptureDelegate
func videoCapture(_ capture: VideoCapture, didCaptureVideoFrame pixelBuffer: CVPixelBuffer?) {

    // 메인큐로 이동하여 추론 할 동안, 비디오캡쳐큐는 멈추기
    self.semaphore.wait()
    
    // 카메라에서 캡쳐된 화면은 pixelBuffer에 담김
    if let pixelBuffer = pixelBuffer {
        // 메인큐로 이동하여 추론 실행
        DispatchQueue.main.async {
            self.predictUsingVision(pixelBuffer: pixelBuffer)
        }
    }
}

// 추론
func predictUsingVision(pixelBuffer: CVPixelBuffer) {
    // Vision이 입력이미지를 자동으로 크기 조정
    let handler = VNImageRequestHandler(cvPixelBuffer: pixelBuffer)
    try? handler.perform([request])
}
```

