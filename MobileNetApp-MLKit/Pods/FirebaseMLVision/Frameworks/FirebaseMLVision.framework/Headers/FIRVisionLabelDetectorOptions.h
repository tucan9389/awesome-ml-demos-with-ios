#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Options for an image label detector.
 */
NS_SWIFT_NAME(VisionLabelDetectorOptions)
@interface FIRVisionLabelDetectorOptions : NSObject

/**
 * The confidence threshold for labels returned by the label detector. Features returned by the
 * label detector will have a confidence higher or equal to the confidence threshold. Default value
 * is 0.5.
 */
@property(nonatomic, readonly) float confidenceThreshold;

/**
 * Creates a new instance with the given detector options.
 *
 * @param confidenceThreshold The confidence threshold for labels returned by the label detector.
 *     Features returned by the label detector will have a confidence higher or equal to the given
 *     threshold. Values must be in range [0, 1]. If an invalid value is provided, the default
 *     threshold of 0.5 is used.
 * @return Label detector options.
 */
- (instancetype)initWithConfidenceThreshold:(float)confidenceThreshold NS_DESIGNATED_INITIALIZER;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
