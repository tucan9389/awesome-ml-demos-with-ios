#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

@class FIRVisionCloudTextProperty;
@class FIRVisionCloudWord;

NS_ASSUME_NONNULL_BEGIN

/**
 * A paragraph consisting of `VisionCloudWord` objects in a certain order.
 */
NS_SWIFT_NAME(VisionCloudParagraph)
@interface FIRVisionCloudParagraph : NSObject

/**
 * An array of words in the paragraph.
 */
@property(nonatomic, copy, readonly, nullable) NSArray<FIRVisionCloudWord *> *words;

/**
 * A rectangle image region to which this landmark belongs to (in the view coordinate system).
 */
@property(nonatomic, readonly) CGRect frame;

/**
 * Confidence of the OCR results for the paragraph. The value is a float, in range [0, 1].
 */
@property(nonatomic, readonly, nullable) NSNumber *confidence;

/**
 * Additional information detected for the paragraph.
 */
@property(nonatomic, readonly, nullable) FIRVisionCloudTextProperty *textProperty;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
