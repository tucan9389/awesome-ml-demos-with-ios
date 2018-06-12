#import <Foundation/Foundation.h>

#import "FIRVisionCloudTextCallback.h"

@class FIRVisionImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * A text detector that detects a text in an image. This detector is optimized for areas of
 * normal text within a larger image. For text detection within a document or dense text image, see
 * `VisionCloudDocumentTextDetector`.
 */
NS_SWIFT_NAME(VisionCloudTextDetector)
@interface FIRVisionCloudTextDetector : NSObject

/**
 * Detects text in a given image.
 *
 * @param image The image to use for detecting a text.
 * @param completion Handler to call back on the main queue with the text detected or error.
 */
- (void)detectInImage:(FIRVisionImage *)image
           completion:(FIRVisionCloudTextDetectionCompletion)completion;

@end

NS_ASSUME_NONNULL_END
