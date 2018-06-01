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

## 과제

### 1. MobileNetApp

첫번째 프로젝트는 Core ML 프레임워크를 사용하여 [MobileNet 모델](https://developer.apple.com/kr/machine-learning/)을 실행시켜보는 예제입니다. 

![DEMO](https://github.com/tucan9389/mot-ios-tensorflow/blob/master/demo/MobileNetApp_test001.gif?raw=true)

☞ [프로젝트](https://github.com/tucan9389/mot-ios-tensorflow/tree/master/MobileNetApp)
