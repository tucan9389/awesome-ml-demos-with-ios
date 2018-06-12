#import <Foundation/Foundation.h>

@class FIRVisionFace;
@class FIRVisionImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * A block containing an array of faces or `nil` if there's an error.
 *
 * @param faces Array of faces detected in the image or `nil` if there was an error.
 * @param error The error or `nil`.
 */
typedef void (^FIRVisionFaceDetectionCallback)(NSArray<FIRVisionFace *> *_Nullable faces,
                                               NSError *_Nullable error)
    NS_SWIFT_NAME(VisionFaceDetectionCallback);

/**
 * A face detector that detects faces in an image.
 */
NS_SWIFT_NAME(VisionFaceDetector)
@interface FIRVisionFaceDetector : NSObject

/**
 * Detects faces in a given image.
 *
 * @param image The image to use for detecting faces.
 * @param completion Handler to call back on the main queue with faces detected or error.
 */
- (void)detectInImage:(FIRVisionImage *)image completion:(FIRVisionFaceDetectionCallback)completion;

@end

NS_ASSUME_NONNULL_END
