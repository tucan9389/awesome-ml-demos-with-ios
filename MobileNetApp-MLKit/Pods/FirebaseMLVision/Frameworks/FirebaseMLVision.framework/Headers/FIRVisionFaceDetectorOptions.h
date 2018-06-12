#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @memberof VisionFaceDetectorOptions
 * Default smallest desired face size: 0.1.
 */
extern const CGFloat FIRVisionFaceDetectionMinSize NS_SWIFT_NAME(VisionFaceDetectionMinSize);

/**
 * @enum VisionFaceDetectorClassification
 * This enum specifies the classification type in face detection.
 */
typedef NS_ENUM(NSUInteger, FIRVisionFaceDetectorClassification) {
  /**
   * Face classification type indicating it performs no classification.
   */
  FIRVisionFaceDetectorClassificationNone = 1,
  /**
   * Face classification type indicating it performs all classification.
   */
  FIRVisionFaceDetectorClassificationAll,
} NS_SWIFT_NAME(VisionFaceDetectorClassification);

/**
 * @enum VisionFaceDetectorMode
 * This enum specifies a preference for accuracy vs. speed trade-offs in face detection.
 */
typedef NS_ENUM(NSUInteger, FIRVisionFaceDetectorMode) {
  /**
   * Face detection mode code indicating detect fewer faces and may be less precise in determining
   * values such as position, but will run faster.
   */
  FIRVisionFaceDetectorModeFast = 1,
  /**
   * Face detection mode code indicating detect more faces and may be more precise in determining
   * values such as position, at the cost of speed.
   */
  FIRVisionFaceDetectorModeAccurate,
} NS_SWIFT_NAME(VisionFaceDetectorMode);

/**
 * @enum VisionFaceDetectorLandmark
 * This enum specifies the landmark detection type in face detection.
 */
typedef NS_ENUM(NSUInteger, FIRVisionFaceDetectorLandmark) {
  /**
   * Face landmark detection type indicating it performs no landmark detection.
   */
  FIRVisionFaceDetectorLandmarkNone = 1,
  /**
   * Face landmark detection type indicating it performs all landmark detection.
   */
  FIRVisionFaceDetectorLandmarkAll,
} NS_SWIFT_NAME(VisionFaceDetectorLandmark);

/**
 * Options for specifying a face detector.
 */
NS_SWIFT_NAME(VisionFaceDetectorOptions)
@interface FIRVisionFaceDetectorOptions : NSObject

/**
 * Whether to run additional classifiers for characterizing attributes such as smiling. Defaults to
 * VisionFaceDetectorClassificationNone.
 */
@property(nonatomic) FIRVisionFaceDetectorClassification classificationType;

/**
 * Preference for accuracy vs. speed trade-offs in face detection.  Defaults to
 * VisionFaceDetectorModeFast.
 */
@property(nonatomic) FIRVisionFaceDetectorMode modeType;

/**
 * Whether to detect no landmarks or all landmarks in face detection. Processing time increases as
 * the number of landmarks to search for increases, so detecting all landmarks will increase the
 * overall detection time. Defaults to VisionFaceDetectorLandmarkNone.
 */
@property(nonatomic) FIRVisionFaceDetectorLandmark landmarkType;

/**
 * The smallest desired face size. The size is expressed as a proportion of the width of the head to
 * the image width. For example, if a value of 0.1 is specified, then the smallest face to search
 * for is roughly 10% of the width of the image being searched. Defaults to
 * VisionFaceDetectionMinSize.
 */
@property(nonatomic) CGFloat minFaceSize;

/**
 * Whether the face tracking feature is enabled in face detection. Defaults to NO.
 */
@property(nonatomic) BOOL isTrackingEnabled;

@end

NS_ASSUME_NONNULL_END
