#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Options for specifying a custom model.
 */
NS_SWIFT_NAME(ModelOptions)
@interface FIRModelOptions : NSObject

/** Name of a model to be downloaded from the cloud. */
@property(nonatomic, copy, readonly, nullable) NSString *cloudModelName;

/** Name of a custom model stored locally in a file on the device. */
@property(nonatomic, copy, readonly, nullable) NSString *localModelName;

/**
 * Creates a new instance of `ModelOptions` with the given local and/or cloud model name. At least
 * one model name must be provided. If both cloud and local model names are provided, then the cloud
 * model takes priority.
 *
 * @param cloudModelName The cloud custom model name. Pass `nil` if only the provided local model
 *     name should be used.
 * @param localModelName The local custom model name. Pass `nil` if only the provided cloud
 *     model name should be used.
 * @return Custom model options instance with the given model name(s).
 */
- (instancetype)initWithCloudModelName:(nullable NSString *)cloudModelName
                        localModelName:(nullable NSString *)localModelName
    NS_DESIGNATED_INITIALIZER;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
