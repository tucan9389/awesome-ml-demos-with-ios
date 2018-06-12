#import <Foundation/Foundation.h>

#import "FIRVisionText.h"

@class FIRVisionTextElement;

NS_ASSUME_NONNULL_BEGIN

/**
 * A single line of text detected in an image.
 */
NS_SWIFT_NAME(VisionTextLine)
@interface FIRVisionTextLine : NSObject <FIRVisionText>

/**
 * Text elements in this line.
 */
@property(nonatomic, readonly) NSArray<FIRVisionTextElement *> *elements;

@end

NS_ASSUME_NONNULL_END
