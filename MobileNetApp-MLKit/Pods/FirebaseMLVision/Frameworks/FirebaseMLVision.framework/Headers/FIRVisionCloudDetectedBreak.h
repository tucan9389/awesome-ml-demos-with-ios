#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @enum VisionCloudDetectedBreakType
 * An enum of detected break types.
 */
typedef NS_ENUM(NSInteger, FIRVisionCloudDetectedBreakType) {
  /**
   * Unknown break type.
   */
  FIRVisionCloudDetectedBreakTypeUnknown,
  /**
   * Line-wrapping break type.
   */
  FIRVisionCloudDetectedBreakTypeLineWrap,
  /**
   * Hyphen break type.
   */
  FIRVisionCloudDetectedBreakTypeHyphen,
  /**
   * Line break that ends a paragraph.
   */
  FIRVisionCloudDetectedBreakTypeLineBreak,
  /**
   * Space break type.
   */
  FIRVisionCloudDetectedBreakTypeSpace,
  /**
   * Sure space break type.
   */
  FIRVisionCloudDetectedBreakTypeSureSpace,
} NS_SWIFT_NAME(VisionCloudDetectedBreakType);

/**
 * Detected start or end of a structural component.
 */
NS_SWIFT_NAME(VisionCloudDetectedBreak)
@interface FIRVisionCloudDetectedBreak : NSObject

/**
 *  Indicates whether the break prepends the element. The value is a BOOL.
 */
@property(nonatomic, readonly, nullable) NSNumber *isPrefix;

/**
 *  The detected break type.
 */
@property(nonatomic, readonly) FIRVisionCloudDetectedBreakType type;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
