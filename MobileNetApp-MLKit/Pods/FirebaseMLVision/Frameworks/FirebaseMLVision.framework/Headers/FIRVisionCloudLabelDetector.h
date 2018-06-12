#import <Foundation/Foundation.h>

@class FIRVisionCloudLabel;
@class FIRVisionImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * A block containing an array of labels or `nil` if there's an error.
 *
 * @param labels Array of labels detected in the image or `nil` if there was an error.
 * @param error The error or `nil`.
 */
typedef void (^FIRVisionCloudLabelDetectionCompletion)(
    NSArray<FIRVisionCloudLabel *> *_Nullable labels, NSError *_Nullable error)
    NS_SWIFT_NAME(VisionCloudLabelDetectionCompletion);

/**
 * A label detector that detects labels in an image.
 */
NS_SWIFT_NAME(VisionCloudLabelDetector)
@interface FIRVisionCloudLabelDetector : NSObject

/**
 * Detects labels in a given image.
 *
 * @param image The image to use when searching labels.
 * @param completion Handler to call back on the main queue with label detected or error.
 */
- (void)detectInImage:(FIRVisionImage *)image
           completion:(FIRVisionCloudLabelDetectionCompletion)completion;

@end

NS_ASSUME_NONNULL_END
