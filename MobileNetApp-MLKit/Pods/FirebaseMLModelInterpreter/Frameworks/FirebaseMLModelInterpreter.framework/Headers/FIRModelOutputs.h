#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Inference results of a Firebase custom model.
 */
NS_SWIFT_NAME(ModelOutputs)
@interface FIRModelOutputs : NSObject

/**
 * Returns the output for a given index.
 *
 * @param index The index of the output to get.
 * @param error The error, if any, during the operation, including
 *     `MachineLearningErrorDomainCode.InvalidArgument` when:
 *     - There is no model output with given index.
 * @return The `index`-th output.  Returns nil if there is an error.
 */
- (nullable id)outputAtIndex:(NSUInteger)index error:(NSError **)error
    NS_SWIFT_NAME(output(index:));

@end

NS_ASSUME_NONNULL_END
