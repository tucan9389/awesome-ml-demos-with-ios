#import <Foundation/Foundation.h>

@class FIRModelDownloadConditions;

NS_ASSUME_NONNULL_BEGIN

/**
 * Source of a custom model stored in the cloud and downloaded to the device.
 */
NS_SWIFT_NAME(CloudModelSource)
@interface FIRCloudModelSource : NSObject

/**
 * The model name.
 */
@property(nonatomic, copy, readonly) NSString *modelName;

/**
 * Indicates whether model updates are enabled.
 */
@property(nonatomic, readonly) BOOL enableModelUpdates;

/**
 * Initial downloading conditions for the model.
 */
@property(nonatomic, readonly) FIRModelDownloadConditions *initialConditions;

/**
 * Subsequent update conditions for the model. If `nil` is passed to the initializer, the default
 * update conditions are set, but are only used if `enableModelUpdates` is `YES`.
 */
@property(nonatomic, readonly) FIRModelDownloadConditions *updateConditions;

/**
 * Creates an instance of `CloudModelSource` with the given name and the download conditions.
 *
 * @param modelName The name of the model you to load. Specify the name you assigned the model when
 *    you uploaded it to the Firebase console.  Within a same Firebase app, all custom cloud
 *    models should have distinct names.
 * @param enableModelUpdates Indicates whether model updates are enabled.
 * @param initialConditions Initial downloading conditions for the model.
 * @param updateConditions Subsequent update conditions for the model. If it is `nil` and
 *     `enableModelUpdates` is `YES`, the default download conditions are used.
 * @return A new instance of `CloudModelSource` with the given name and conditions.
 */
- (instancetype)initWithModelName:(NSString *)modelName
               enableModelUpdates:(BOOL)enableModelUpdates
                initialConditions:(FIRModelDownloadConditions *)initialConditions
                 updateConditions:(nullable FIRModelDownloadConditions *)updateConditions
    NS_DESIGNATED_INITIALIZER
    NS_SWIFT_NAME(init(modelName:enableModelUpdates:initialConditions:updateConditions:));

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
