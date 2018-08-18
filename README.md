# iOS Projects with Machine Learning Models

This challenge is that using machine learning model created from tensorflow on iOS with Core ML or ML Kit(TensorFlow Lite)

[한국어 README](https://github.com/motlabs/iOS-Proejcts-with-ML-Models/blob/master/README_kr.md)

## Machine Learning Framework for iOS

- [Core ML](https://developer.apple.com/documentation/coreml)
- [MLKit](https://developers.google.com/ml-kit/)
- etc.([Tensorflow Lite](https://www.tensorflow.org/mobile/tflite/), [Tensorflow Mobile](https://www.tensorflow.org/mobile/))

### Flow of model when using Core ML

[![flow of model when using coreml](Resource/flow_of_model_when_using_coreml.png?raw=true)](https://docs.google.com/presentation/d/1wA_PAjllpLLcFPuZcERYbQlPe1Ipb-bzIZinZg3zXkg/edit?usp=sharing)

Almost machine learning framework have been used similar flow. **Convert** my model created from TensorFlow to a **model which is compatible with mobile machine learning framework**. Each framework have compatible model format, and  

Once prepared a compatible model, you can run inference by using machine learning framework(like Core ML or ML Kit..). You need **preprocess/postprocess** before/after inference on your project.

> If you want more explanation, check [this slide(Korean)](https://docs.google.com/presentation/d/1wA_PAjllpLLcFPuZcERYbQlPe1Ipb-bzIZinZg3zXkg/edit?usp=sharing).

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
2. [FingertipEstimation-CoreML](https://github.com/tucan9389/FingertipEstimation-CoreML)

- [KeypointAnnotation](https://github.com/tucan9389/KeypointAnnotation)(preparing...)<br>
  : Annotation tool for own custom estimation dataset

#### Modules used

- `Measure.swift`
- `PoseView.swift`
- `HeatmapView.swift`

|                    PoseEstimation-CoreML                     |                  FingertipEstimation-CoreML                  |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| ![180705-poseestimation-demo.gif](https://github.com/tucan9389/PoseEstimation-CoreML/raw/master/resource/180801-poseestimation-demo.gif?raw=true) | ![fingertip_estimation_demo003](Resource/fingertip_estimation_demo003.gif) |

#### 2-1. Annotation Tool

| KeypointAnnotation(preparing...)                             |
| ------------------------------------------------------------ |
| ![annotation_ios_app_demo001](Resource/annotation_ios_app_demo001.gif) |



### 3. Text Detection & Recognition

1. [WordRecognition-CoreML-MLKit](https://github.com/tucan9389/WordRecognition-CoreML-MLKit)(preparing...)<br>
   :  Detect character, find a word what I point and then recognize the word using Core ML and ML Kit.
2. WordRecognition-MLKit(preparing...)<br>
   : Just recognize words by using MLKit's text recognition function.

| WordRecognition-CoreML-MLKit                                 | WordRecognition-MLKit |
| ------------------------------------------------------------ | --------------------- |
| ![recognition a word demo](Resource/recognition_a_word_demo002.gif) | -                     |



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
