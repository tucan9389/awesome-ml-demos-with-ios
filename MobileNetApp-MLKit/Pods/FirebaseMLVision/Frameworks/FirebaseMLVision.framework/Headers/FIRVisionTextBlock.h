#import <Foundation/Foundation.h>

#import "FIRVisionText.h"

@class FIRVisionTextLine;

NS_ASSUME_NONNULL_BEGIN

/**
 * Describes a text block detected in a still image frame. Its properties provide details about
 * detected text. A text block is a simple list of "lines".
 */

NS_SWIFT_NAME(VisionTextBlock)
@interface FIRVisionTextBlock : NSObject <FIRVisionText>
/**
 * The contents of the text block, broken down into individual lines.
 */
@property(nonatomic, readonly) NSArray<FIRVisionTextLine *> *lines;

@end

NS_ASSUME_NONNULL_END
