#import <Foundation/Foundation.h>

@class FIRVisionCloudBlock;
@class FIRVisionCloudTextProperty;

NS_ASSUME_NONNULL_BEGIN

/**
 * A page consisting of `VisionCloudBlock` objects.
 */
NS_SWIFT_NAME(VisionCloudPage)
@interface FIRVisionCloudPage : NSObject

/**
 * An array of blocks (text, image, etc.) on the page.
 */
@property(nonatomic, copy, readonly, nullable) NSArray<FIRVisionCloudBlock *> *blocks;

/**
 * Confidence of the OCR results on the page. The value is a float, in range [0, 1].
 */
@property(nonatomic, readonly, nullable) NSNumber *confidence;

/**
 * The page width. For PDFs, the unit is points. For images (including TIFFs) the unit is pixels.
 * The value is an int.
 */
@property(nonatomic, readonly, nullable) NSNumber *width;

/**
 * The page height. For PDFs, the unit is points. For images (including TIFFs) the unit is pixels.
 * The value is an int.
 */
@property(nonatomic, readonly, nullable) NSNumber *height;

/**
 * Additional information detected for the page.
 */
@property(nonatomic, readonly, nullable) FIRVisionCloudTextProperty *textProperty;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
