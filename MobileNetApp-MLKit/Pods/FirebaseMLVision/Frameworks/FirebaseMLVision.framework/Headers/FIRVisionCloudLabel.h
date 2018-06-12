#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * Set of label properties identified by a vision cloud detector.
 */
NS_SWIFT_NAME(VisionCloudLabel)
@interface FIRVisionCloudLabel : NSObject

/**
 * Opaque entity ID. Some IDs may be available in [Google Knowledge Graph Search API]
 * (https://developers.google.com/knowledge-graph/).
 */
@property(nonatomic, copy, readonly, nullable) NSString *entityId;

/**
 * Textual label name.
 */
@property(nonatomic, copy, readonly, nullable) NSString *label;

/**
 * Overall confidence of the result.  The value is float, in range [0, 1].
 */
@property(nonatomic, readonly, nullable) NSNumber *confidence;

@end

NS_ASSUME_NONNULL_END
