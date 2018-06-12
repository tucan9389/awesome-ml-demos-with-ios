#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Detected language for a structural component.
 */
NS_SWIFT_NAME(VisionCloudDetectedLanguage)
@interface FIRVisionCloudDetectedLanguage : NSObject

/**
 *  The BCP-47 language code, such as, "en-US" or "sr-Latn". For more information, see
 *  http://www.unicode.org/reports/tr35/#Unicode_locale_identifier.
 */
@property(nonatomic, copy, readonly, nullable) NSString *languageCode;

/**
 * Confidence of detected language. The value is a float, in range [0, 1].
 */
@property(nonatomic, readonly, nullable) NSNumber *confidence;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
