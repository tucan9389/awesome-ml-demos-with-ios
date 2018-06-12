#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognized text in an image.
 */
NS_SWIFT_NAME(VisionText)
@protocol FIRVisionText <NSObject>

/**
 * The rectangle that holds the discovered text relative to the detected image in the view
 * coordinate system.
 */
@property(nonatomic, readonly) CGRect frame;

/**
 * Recognized text string.
 */
@property(nonatomic, readonly) NSString *text;

/**
 * The four corner points of the text, in clockwise order starting with the top left relative
 * to the detected image in the view coordinate system. These are `CGPoint`s boxed in `NSValue`s.
 */
@property(nonatomic, readonly) NSArray<NSValue *> *cornerPoints;

@end

NS_ASSUME_NONNULL_END
