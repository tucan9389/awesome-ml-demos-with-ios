#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

@class FIRVisionCloudParagraph;
@class FIRVisionCloudTextProperty;

NS_ASSUME_NONNULL_BEGIN

/**
 * @enum VisionCloudBlockType
 * An enum of block types.
 */
typedef NS_ENUM(NSInteger, FIRVisionCloudBlockType) {
  /**
   * Unknown block type.
   */
  FIRVisionCloudBlockTypeUnknown,
  /**
   * Barcode block type.
   */
  FIRVisionCloudBlockTypeBarcode,
  /**
   * Image block type.
   */
  FIRVisionCloudBlockTypePicture,
  /**
   * Horizontal/vertical line box.
   */
  FIRVisionCloudBlockTypeRuler,
  /**
   * Table block type.
   */
  FIRVisionCloudBlockTypeTable,
  /**
   * Regular text block type.
   */
  FIRVisionCloudBlockTypeText,
} NS_SWIFT_NAME(VisionCloudBlockType);

/**
 * A block consisting of `VisionCloudParagraph` objects.
 */
NS_SWIFT_NAME(VisionCloudBlock)
@interface FIRVisionCloudBlock : NSObject

/**
 * The detected block type (text, image, etc.) for the block.
 */
@property(nonatomic, readonly) FIRVisionCloudBlockType type;

/**
 * An array of paragraphs in the block if the type is `VisionCloudBlockTypeText`.
 */
@property(nonatomic, copy, readonly, nullable) NSArray<FIRVisionCloudParagraph *> *paragraphs;

/**
 * A rectangle image region to which this landmark belongs to (in the view coordinate system).
 */
@property(nonatomic, readonly) CGRect frame;

/**
 * Confidence of the OCR results on the block. The value is a float, in range [0, 1].
 */
@property(nonatomic, readonly, nullable) NSNumber *confidence;

/**
 * Additional information detected for the block.
 */
@property(nonatomic, readonly, nullable) FIRVisionCloudTextProperty *textProperty;

/**
 * Not available
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
