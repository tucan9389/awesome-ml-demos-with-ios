# mot-ios-tensorflow

Tensorflow에서 만든 모델을 iOS에서 사용해봅니다. 

## iOS를 위한 ML 프레임워크

- [Core ML](https://developer.apple.com/documentation/coreml)
- [MLKit](https://developers.google.com/ml-kit/)
- [Tensorflow Lite](https://www.tensorflow.org/mobile/tflite/)
- [Tensorflow Mobile](https://www.tensorflow.org/mobile/)
- etc.

### Core ML을 이용할 때의 모델 흐름도

![iOS ë¨¸ì ë¬ë íë¡ì¸ì¤.png](https://github.com/MachineLearningOfThings/mot-ios-tensorflow/blob/master/Resource/iOS%20%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D%20%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4.png?raw=true)

전체적인 흐름은 대부분의 ML 프레임워크가 비슷하게 사용됩니다. 각자 프레임워크에 **호환되는 모델 포멧**이 있으며, Tensorflow에서 만들어진 모델 포멧으로부터 **변환**시키는 작업이 필요합니다. 

호환되는 모델을 준비했다면, ML 프레임워크를 사용하여 추론을 실행합니다. 추론을 실행하기 전/후에 **전처리/후처리**를 해줘야하며, ML 프레임워크마다 편의성의 정도가 다릅니다.

## 모델 실행 예제

### 1. MobileNet

MobileNet 모델을 실행시켜본 예제입니다.

1. [MobileNet-CoreML](https://github.com/tucan9389/MobileNetApp-CoreML)
2. [MobileNet-MLKit](https://github.com/tucan9389/MobileNetApp-MLKit)

|                    MobileNet with Core ML                    |                    MobileNet with ML Kit                     |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| ![DEMO-CoreML](https://github.com/tucan9389/MobileNetApp-CoreML/blob/master/resource/MobileNet-CoreML-DEMO.gif?raw=true) | ![DEMO-MLKit](https://github.com/tucan9389/MobileNetApp-MLKit/blob/master/resource/MobileNet-MLKit-DEMO.gif?raw=true) |

### 2. Pose Estimation

1. PoseEstimation-CoreML(준비중)
2. PoseEstimation-MLKit(준비중)



## 성능 측정 모듈

### 1. 실행시간, fsp 계산 모듈(준비중)

> PoseEstimation-CoreML에 구현되어있으나 모듈화 필요

### 2. 테스트 프로젝트(준비중)

#### 2-1. 단일 테스트

> 한 입력에대한 한 결과 출력
> 세부적인 결과 그리기
> 디버깅용 테스트?
>
> - Pose Estimation: point마다 점을 찍고 연결, 각 point마다 confidence 출력
> - ...

#### 2-2. 묶음 테스트(기획중)

> 여러 입력에대한 여러 결과를 종합적으로 분석
>
> - 평균 execution time, fps
> - 누적 execution time, fps...?
> - 총 execution time
> - rendering time
> - ...