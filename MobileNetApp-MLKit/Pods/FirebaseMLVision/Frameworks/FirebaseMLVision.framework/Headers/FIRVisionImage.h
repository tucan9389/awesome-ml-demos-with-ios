#import <CoreMedia/CoreMedia.h>
#import <UIKit/UIKit.h>

@class FIRVisionImageMetadata;

NS_ASSUME_NONNULL_BEGIN

/**
 * An image or image buffer used in vision detection, with optional metadata.
 */
NS_SWIFT_NAME(VisionImage)
@interface FIRVisionImage : NSObject

/**
 * Metadata about the image (e.g. image orientation). If metadata is not specified, the default
 * metadata values are used.
 */
@property(nonatomic, nullable) FIRVisionImageMetadata *metadata;

/**
 * Initializes a VisionImage object with the given image.
 *
 * @param image Image to use in vision detection. The given image should be rotated, so its
 *      `imageOrientation` property is set to `UIImageOrientationUp` value.
 * @return A VisionImage instance with the given image.
 */
- (instancetype)initWithImage:(UIImage *)image NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a VisionImage object with the given image buffer. To improve performance, it is
 * recommended to minimize the lifespan and number of instances of this class when initializing with
 * a `CMSampleBufferRef`.
 *
 * @param sampleBuffer Image buffer to use in vision detection.
 * @return A VisionImage instance with the given image buffer.
 */
- (instancetype)initWithBuffer:(CMSampleBufferRef)sampleBuffer NS_DESIGNATED_INITIALIZER;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
