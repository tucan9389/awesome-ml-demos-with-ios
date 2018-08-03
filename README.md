# iOS Projects with Machine Learning Models

This challenge is that using machine learning model created from tensorflow on iOS with Core ML or ML Kit(TensorFlow Lite)

[한국어 README](https://github.com/motlabs/iOS-Proejcts-with-ML-Models/blob/master/README_kr.md)

## Machine Learning Framework for iOS

- [Core ML](https://developer.apple.com/documentation/coreml)
- [MLKit](https://developers.google.com/ml-kit/)
- etc.([Tensorflow Lite](https://www.tensorflow.org/mobile/tflite/), [Tensorflow Mobile](https://www.tensorflow.org/mobile/))

### Flow of model when using Core ML

![flow of model when using coreml](Resource/flow_of_model_when_using_coreml.png?raw=true)

전체적인 흐름은 대부분의 ML 프레임워크가 비슷하게 사용됩니다. 각자 프레임워크에 **호환되는 모델 포멧**이 있으며, Tensorflow에서 만들어진 모델 포멧으로부터 **변환**시키는 작업이 필요합니다. 

호환되는 모델을 준비했다면, ML 프레임워크를 사용하여 추론을 실행합니다. 추론을 실행하기 전/후에 **전처리/후처리**를 해줘야하며, ML 프레임워크마다 편의성의 정도가 다릅니다.

## Example projects using various machine learning model

### 1. MobileNet

Example project using MobileNet model.

1. [MobileNet-CoreML](https://github.com/tucan9389/MobileNetApp-CoreML)
2. [MobileNet-MLKit](https://github.com/tucan9389/MobileNetApp-MLKit)

|                    MobileNet with Core ML                    |                    MobileNet with ML Kit                     |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| ![DEMO-CoreML](https://github.com/tucan9389/MobileNetApp-CoreML/blob/master/resource/MobileNet-CoreML-DEMO.gif?raw=true) | ![DEMO-MLKit](https://github.com/tucan9389/MobileNetApp-MLKit/blob/master/resource/MobileNet-MLKit-DEMO.gif?raw=true) |

### 2. Pose Estimation

1. [PoseEstimation-CoreML](https://github.com/tucan9389/PoseEstimation-CoreML)
2. [PoseEstimation-MLKit](https://github.com/tucan9389/PoseEstimation-MLKit)(preparing..)

#### Modules used

- `Measure.swift`
- `PoseView.swift`
- `HeatmapView.swift`

|                    PoseEstimation-CoreML                     | PoseEstimation-MLKit |
| :----------------------------------------------------------: | :------------------: |
| ![180705-poseestimation-demo.gif](https://github.com/tucan9389/PoseEstimation-CoreML/raw/master/resource/180801-poseestimation-demo.gif?raw=true) |          -           |

### 3. Text Detection & Recognition

1. Text-Detection-And-Word-Recognition<br>
   : word recognition after detecting text



## Module of performance measurement

### 1. Inference duration, Excution duration and FPS evaluation module(preparing...)

> This function is implemented(`Measure.swift`) in [PoseEstimation-CoreML](https://github.com/tucan9389/PoseEstimation-CoreML), but need to modulization.

### 2. Evalutation Project(preparing...)

#### 2-1. Unit Test

> Show output for each input?
> Drawing detail of result?
> Test for debugging?
>
> - Pose Estimation: draw dot each point and joint, print confidence each point.
> - ...

#### 2-2. Bunch Test(planning...)

> Analyze outputs from a bunch of inputs
>
> - average of inference time and fps
> - accumulate execution time, fps...?
> - rendering time
> - total execution time
> - ...
