#import <Foundation/Foundation.h>

@class FIRVisionImage;
@class FIRVisionLabel;

NS_ASSUME_NONNULL_BEGIN

/**
 * A callback containing an array of labels or `nil` if there's an error.
 *
 * @param labels Array of labels detected in the image or `nil` if there was an error.
 * @param error The error or `nil`.
 */
typedef void (^FIRVisionLabelDetectionCallback)(NSArray<FIRVisionLabel *> *_Nullable labels,
                                                NSError *_Nullable error)
    NS_SWIFT_NAME(VisionLabelDetectionCallback);

/**
 * A label detector that detects labels in an image.
 */
NS_SWIFT_NAME(VisionLabelDetector)
@interface FIRVisionLabelDetector : NSObject

/**
 * Detects labels in a given image.
 *
 * @param image The image to use for detecting labels.
 * @param completion Handler to call back on the main queue with labels detected or error.
 */
- (void)detectInImage:(FIRVisionImage *)image
           completion:(FIRVisionLabelDetectionCallback)completion;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
