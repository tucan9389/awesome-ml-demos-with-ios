#import <Foundation/Foundation.h>

#import "FIRVisionCloudTextCallback.h"

@class FIRVisionImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * A document text detector that detects text in an image. This detector is optimized for
 * dense text or document images. For text detection within a normal image, see
 * `VisionCloudTextDetector`.
 */
NS_SWIFT_NAME(VisionCloudDocumentTextDetector)
@interface FIRVisionCloudDocumentTextDetector : NSObject

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
