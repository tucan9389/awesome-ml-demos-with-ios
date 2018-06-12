#import <Foundation/Foundation.h>

#import "FIRVisionText.h"

@class FIRVisionImage;
@class FIRVisionText;

NS_ASSUME_NONNULL_BEGIN

/**
 * A block containing an array of texts or `nil` if there's an error.
 *
 * @param texts Array of texts detected in the image or `nil` if there was an error.
 * @param error The error or `nil`.
 */
typedef void (^FIRVisionTextDetectionCallback)(NSArray<id<FIRVisionText>> *_Nullable texts,
                                               NSError *_Nullable error)
    NS_SWIFT_NAME(VisionTextDetectionCallback);

/**
 * A text detector that detects texts in an image.
 */
NS_SWIFT_NAME(VisionTextDetector)
@interface FIRVisionTextDetector : NSObject

/**
 * Detects texts in the given image.
 *
 * @param image The image to use for detecting texts.
 * @param completion Handler to call back on the main queue with texts detected or error.
 */
- (void)detectInImage:(FIRVisionImage *)image completion:(FIRVisionTextDetectionCallback)completion;

@end

NS_ASSUME_NONNULL_END
