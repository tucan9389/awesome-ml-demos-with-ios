#import <Foundation/Foundation.h>

@class FIRVisionCloudText;

NS_ASSUME_NONNULL_BEGIN

/**
 * A block containing a text detection or error.
 *
 * @param text The text detected in the image or `nil` if there was an error.
 * @param error The error or `nil`.
 */
typedef void (^FIRVisionCloudTextDetectionCompletion)(FIRVisionCloudText* _Nullable text,
                                                      NSError* _Nullable error)
    NS_SWIFT_NAME(VisionCloudTextDetectionCompletion);

NS_ASSUME_NONNULL_END
