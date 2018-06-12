#import <Foundation/Foundation.h>

@class FIRVisionCloudDetectedBreak;
@class FIRVisionCloudDetectedLanguage;

NS_ASSUME_NONNULL_BEGIN

/**
 * Additional information detected on the structural component for text detection.
 */
NS_SWIFT_NAME(VisionCloudTextProperty)
@interface FIRVisionCloudTextProperty : NSObject

/**
 * Detected start or end of a text segment.
 */
@property(nonatomic, readonly, nullable) FIRVisionCloudDetectedBreak *detectedBreak;

/**
 * An array of detected languages.
 */
@property(nonatomic, copy, readonly, nullable)
    NSArray<FIRVisionCloudDetectedLanguage *> *detectedLanguages;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
