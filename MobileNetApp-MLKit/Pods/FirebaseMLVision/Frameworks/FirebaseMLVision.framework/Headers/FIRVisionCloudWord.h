#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

@class FIRVisionCloudSymbol;
@class FIRVisionCloudTextProperty;

NS_ASSUME_NONNULL_BEGIN

/**
 * A representation of a word consisting of `VisionSymbol` objects.
 */
NS_SWIFT_NAME(VisionCloudWord)
@interface FIRVisionCloudWord : NSObject

/**
 * An array of symbols in the word.
 */
@property(nonatomic, copy, readonly, nullable) NSArray<FIRVisionCloudSymbol *> *symbols;

/**
 * A rectangle image region to which this landmark belongs to (in the view coordinate system).
 */
@property(nonatomic, readonly) CGRect frame;

/**
 * Confidence of the OCR results for the word. The value is a float, in range [0, 1].
 */
@property(nonatomic, readonly, nullable) NSNumber *confidence;

/**
 * Additional information detected for the word.
 */
@property(nonatomic, readonly, nullable) FIRVisionCloudTextProperty *textProperty;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
