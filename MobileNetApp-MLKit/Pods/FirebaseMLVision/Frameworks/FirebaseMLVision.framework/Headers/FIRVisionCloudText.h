#import <Foundation/Foundation.h>

@class FIRVisionCloudPage;

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents text identified by the vision cloud text detector.
 */
NS_SWIFT_NAME(VisionCloudText)
@interface FIRVisionCloudText : NSObject

/**
 * String representaton of the text that was detected.
 */
@property(nonatomic, copy, readonly, nullable) NSString *text;

/**
 * An array of pages that were detected.
 */
@property(nonatomic, copy, readonly, nullable) NSArray<FIRVisionCloudPage *> *pages;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
