#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a label for an image.
 */
NS_SWIFT_NAME(VisionLabel)
@interface FIRVisionLabel : NSObject

/**
 * The rectangle that holds the discovered label relative to the detected image in the view
 * coordinate system.
 */
@property(nonatomic, readonly) CGRect frame;

/**
 * Confidence for the label in range [0, 1].
 */
@property(nonatomic, readonly) float confidence;

/**
 * Opaque entity ID. Some IDs may be available in [Google Knowledge Graph Search API].
 * (https://developers.google.com/knowledge-graph/).
 */
@property(nonatomic, copy, readonly) NSString *entityID;

/**
 * The human readable label string in American English. For example: "Balloon".
 *
 * Note: this is not fit for display purposes, as it is not localized. Use the `entityID` and query
 * the Knowledge Graph to get a localized description of the label.
 */
@property(nonatomic, copy, readonly) NSString *label;

@end

NS_ASSUME_NONNULL_END
