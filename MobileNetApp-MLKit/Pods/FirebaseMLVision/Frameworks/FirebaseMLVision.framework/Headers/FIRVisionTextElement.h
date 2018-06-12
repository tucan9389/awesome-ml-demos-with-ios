#import <Foundation/Foundation.h>

#import "FIRVisionText.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Describes a single element in a line of detected text. An "element" is roughly equivalent to a
 * space-separated "word" in most Latin-script languages.
 */
NS_SWIFT_NAME(VisionTextElement)
@interface FIRVisionTextElement : NSObject <FIRVisionText>
@end

NS_ASSUME_NONNULL_END
