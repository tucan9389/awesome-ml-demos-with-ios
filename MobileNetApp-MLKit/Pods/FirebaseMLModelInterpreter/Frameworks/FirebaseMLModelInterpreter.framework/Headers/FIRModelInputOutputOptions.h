#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @enum ModelElementType
 * This enum specifies the type of elements in the custom model's input or output.
 */
typedef NS_ENUM(NSUInteger, FIRModelElementType) {
  /** Element type unknown/undefined. */
  FIRModelElementTypeUnknown = 0,
  /** 32-bit single precision floating point. */
  FIRModelElementTypeFloat32,
  /** 32-bit signed integer. */
  FIRModelElementTypeInt32,
  /** 8-bit unsigned integer. */
  FIRModelElementTypeUInt8,
  /** 64-bit signed integer. */
  FIRModelElementTypeInt64,
} NS_SWIFT_NAME(ModelElementType);

/**
 * Options for a custom model specifying input and output data types and dimensions.
 */
NS_SWIFT_NAME(ModelInputOutputOptions)
@interface FIRModelInputOutputOptions : NSObject

/**
 * Sets the type and dimensions for the input at a given index.
 *
 * @param index The index of the input to configure.
 * @param type The element type for the input at a given index.
 * @param dimensions The array of dimensions for the input at a given index.  Each
 * dimension should have an `NSUInteger` value.  For example, for a 2 dimensional input with 4 rows
 * and 9 columns, the corresponding dimensions should be provided as an `NSArray` containing two
 * `NSNumber`s with unsigned integer values, 4 and 9 respectively.
 * @param error The error, if any, during the operation, including
 *     `MachineLearningErrorDomainCode.InvalidArgument` when:
 *     - `type` is invalid.
 *     - `dimensions` are nil or empty.
 *     - Any of the `dimensions` is 0 (it must be positive).
 * @return Whether the operation is successful.
 */
- (BOOL)setInputFormatForIndex:(NSUInteger)index
                          type:(FIRModelElementType)type
                    dimensions:(NSArray<NSNumber *> *)dimensions
                         error:(NSError **)error
    NS_SWIFT_NAME(setInputFormat(index:type:dimensions:));

/**
 * Sets the type and dimensions for the output at a given index.
 *
 * @param index The index of the output to configure.
 * @param type The element type for the output at a given index.
 * @param dimensions The array of dimensions for the output at a given index.  Each dimension should
 * have an `NSUInteger` value.  For example, for a 2 dimensional output with 4 rows and 9 columns,
 * the corresponding dimensions should be provided as an `NSArray` containing two `NSNumber`s with
 *     unsigned integer values, 4 and 9 respectively.
 * @param error The error, if any, during the operation, including
 *     `MachineLearningErrorDomainCode.InvalidArgument` when:
 *     - `type` is invalid.
 *     - `dimensions` are nil or empty.
 *     - Any of the `dimensions` is 0 (it must be positive).
 * @return Whether the operation is successful.
 */
- (BOOL)setOutputFormatForIndex:(NSUInteger)index
                           type:(FIRModelElementType)type
                     dimensions:(NSArray<NSNumber *> *)dimensions
                          error:(NSError **)error
    NS_SWIFT_NAME(setOutputFormat(index:type:dimensions:));

@end

NS_ASSUME_NONNULL_END
