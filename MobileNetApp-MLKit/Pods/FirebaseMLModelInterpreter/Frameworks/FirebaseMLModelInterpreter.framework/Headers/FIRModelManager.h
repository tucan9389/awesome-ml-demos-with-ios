#import <Foundation/Foundation.h>

@class FIRApp;
@class FIRCloudModelSource;
@class FIRLocalModelSource;

NS_ASSUME_NONNULL_BEGIN

/**
 * A Firebase model manager for both local and cloud custom models.
 */
NS_SWIFT_NAME(ModelManager)
@interface FIRModelManager : NSObject

/**
 * Gets the custom model manager for the default Firebase app.  The default Firebase app instance
 * must be configured before calling this method; otherwise raises `FIRAppNotConfigured` exception.
 * The returned model manager is thread safe.  Custom models hosted in non-default Firebase apps are
 * currently not supported.
 *
 * @return A custom model manager for the default Firebase app.
 */
+ (instancetype)modelManager NS_SWIFT_NAME(modelManager());

/**
 * Registers a cloud model to be used by the custom model interpreter.  The model name is unique to
 * each custom cloud model and can only be registered once with a given instance of the
 * `ModelManager`.  The model name should be the same name used when uploading the custom model to
 * the Firebase Console.  It's OK to separately register a cloud model and a local model with the
 * same name for a given instance of the `ModelManager`.
 *
 * @param cloudModelSource The cloud model source to register.
 * @return Whether the registration is successful.  Returns NO if the given `cloudModelSource` is
 *     invalid or it has already been registered.
 */
- (BOOL)registerCloudModelSource:(FIRCloudModelSource *)cloudModelSource;

/**
 * Registers a local model to be used by the custom model interpreter.  The model name is unique to
 * each custom local model and can only be registered once with a given instance of the
 * `ModelManager`.  It's OK to separately register a cloud model and a local model with the
 * same name for a given instance of the `ModelManager`.
 *
 * @param localModelSource The local model source to register.
 * @return Whether the registration is successful.  Returns NO if the given `localModelSource` is
 *     invalid or it has already been registered.
 */
- (BOOL)registerLocalModelSource:(FIRLocalModelSource *)localModelSource;

/**
 * Gets the registered cloud model source for a given model name.  Returns nil if the model name
 * was never registered with this model manager.
 *
 * @param modelName Name of the cloud model.
 * @return The cloud model source previously registered with the given model name.  Returns nil if
 *     the model name was never registered with this model manager.
 */
- (nullable FIRCloudModelSource *)cloudModelSourceForModelName:(NSString *)modelName
    NS_SWIFT_NAME(cloudModelSource(modelName:));

/**
 * Gets the registered local model source for a given model name.  Returns nil if the model name
 * was never registered with this model manager.
 *
 * @param modelName The name of the local model.
 * @return The local model source previously registered with the given model name.  Returns nil if
 *     the model name was never registered with this model manager.
 */
- (nullable FIRLocalModelSource *)localModelSourceForModelName:(NSString *)modelName
    NS_SWIFT_NAME(localModelSource(modelName:));

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
