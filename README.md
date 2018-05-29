# mot-ios-tensorflow

Tensorflow에서 만든 모델을 iOS에서 사용해봅니다.

## iOS를 위한 ML 프레임워크

- Core ML
- MLKit
- Tensorflow Lite
- Tensorflow Mobile
- etc.

### Core ML을 이용할 때의 모델 흐름도

![iOS 머신러닝 프로세스](https://github.com/tucan9389/mot-ios-tensorflow/blob/master/DEMO/iOS+%E1%84%86%E1%85%A5%E1%84%89%E1%85%B5%E1%86%AB%E1%84%85%E1%85%A5%E1%84%82%E1%85%B5%E1%86%BC+%E1%84%91%E1%85%B3%E1%84%85%E1%85%A9%E1%84%89%E1%85%A6%E1%84%89%E1%85%B3.png?raw=true)

전체적인 흐름은 대부분의 ML 프레임워크가 비슷하게 사용됩니다. 각자 프레임워크에 호환되는 모델 포멧이 있으며, Tensorflow에서 만들어진 모델 포멧으로부터 변환시키는 작업이 필요합니다. 

## 과제

### 1. MobileNetApp

첫번째 프로젝트는 Core ML 프레임워크를 사용하여 MobileNet 모델을 실행시켜보는 예제입니다. 

![DEMO](https://github.com/tucan9389/mot-ios-tensorflow/blob/master/DEMO/MobileNetApp_test001.gif?raw=true)

☞ [프로젝트](https://github.com/tucan9389/mot-ios-tensorflow/tree/master/MobileNetApp)