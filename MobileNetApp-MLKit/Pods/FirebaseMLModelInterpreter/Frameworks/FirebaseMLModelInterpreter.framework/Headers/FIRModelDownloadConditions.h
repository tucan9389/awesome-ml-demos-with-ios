#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Configurations for downloading conditions.
 */
NS_SWIFT_NAME(ModelDownloadConditions)
@interface FIRModelDownloadConditions : NSObject<NSCopying>

/**
 * Indicates whether WiFi is required for downloading. The default is `NO`.
 */
@property(nonatomic, readonly) BOOL isWiFiRequired;

/**
 * Indicates whether the device should be in an idle state for downloading. The default is `NO`.
 */
@property(nonatomic, readonly) BOOL isIdleRequired;

/**
 * Creates an instance of `ModelDownloadConditions` with the given configuration.
 *
 * @param isWiFiRequired Whether a device has to be connected to WiFi for downloading to start.
 * @param isIdleRequired Whether a device has to be in an idle state for downloading to start.
 * @return A new instance of `ModelDownloadConditions`.
 */
- (instancetype)initWithWiFiRequired:(BOOL)isWiFiRequired
                        idleRequired:(BOOL)isIdleRequired NS_DESIGNATED_INITIALIZER;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
