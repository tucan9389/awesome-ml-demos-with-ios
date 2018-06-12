#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

@class FIRVisionCloudTextProperty;

NS_ASSUME_NONNULL_BEGIN

/**
 * A representation of a single symbol.
 */
NS_SWIFT_NAME(VisionCloudSymbol)
@interface FIRVisionCloudSymbol : NSObject

/**
 * String representaton of the symbol.
 */
@property(nonatomic, copy, readonly, nullable) NSString *text;

/**
 * A rectangle image region to which this landmark belongs to (in the view coordinate system).
 */
@property(nonatomic, readonly) CGRect frame;

/**
 * Confidence of the OCR results for the symbol. The value is a float, in range [0, 1].
 */
@property(nonatomic, readonly, nullable) NSNumber *confidence;

/**
 * Additional information detected for the symbol.
 */
@property(nonatomic, readonly, nullable) FIRVisionCloudTextProperty *textProperty;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
