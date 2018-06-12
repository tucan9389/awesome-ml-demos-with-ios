#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Source of a custom model stored locally on the device.
 */
NS_SWIFT_NAME(LocalModelSource)
@interface FIRLocalModelSource : NSObject

/**
 * The model name.
 */
@property(nonatomic, copy, readonly) NSString *modelName;

/**
 * The file path to the custom model stored locally on the device.
 */
@property(nonatomic, copy, readonly) NSString *path;

/**
 * Creates an instance of `LocalModelSource` with a given path and name.
 *
 * @param modelName A custom local model name.  Within a same Firebase app, all custom local
 *    models should have distinct names (same for the cloud and local sources).
 * @param path An absolute path to the custom model file stored locally on the device.
 * @return A new instance of `LocalModelSource` with the given path.
 */
- (instancetype)initWithModelName:(NSString *)modelName
                             path:(NSString *)path NS_DESIGNATED_INITIALIZER;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
