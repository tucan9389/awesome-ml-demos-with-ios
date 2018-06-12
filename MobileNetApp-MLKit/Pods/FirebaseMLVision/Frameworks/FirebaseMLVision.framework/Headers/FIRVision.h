#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

@class FIRApp;
@class FIRVisionBarcodeDetector;
@class FIRVisionBarcodeDetectorOptions;
@class FIRVisionCloudDetectorOptions;
@class FIRVisionCloudDocumentTextDetector;
@class FIRVisionCloudLabelDetector;
@class FIRVisionCloudLandmarkDetector;
@class FIRVisionCloudTextDetector;
@class FIRVisionFaceDetector;
@class FIRVisionFaceDetectorOptions;
@class FIRVisionLabelDetector;
@class FIRVisionLabelDetectorOptions;
@class FIRVisionTextDetector;

NS_ASSUME_NONNULL_BEGIN

/**
 * A Firebase service that supports vision APIs on iOS.
 */
NS_SWIFT_NAME(Vision)
@interface FIRVision : NSObject

/**
 * Gets an instance of Firebase Vision service for the default Firebase app.  This method is thread
 * safe.  The default Firebase app instance must be configured before calling this method; otherwise
 * raises FIRAppNotConfigured exception.
 *
 * @return A Firebase Vision service instance, initialized with the default Firebase app.
 */
+ (instancetype)vision NS_SWIFT_NAME(vision());

/**
 * Gets an instance of Firebase Vision service for the custom Firebase app.  This method is thread
 * safe.
 *
 * @param app The custom Firebase app used for initialization.  Raises FIRAppInvalid exception if
 *     `app` is nil.
 * @return A Firebase Vision service instance, initialized with the custom Firebase app.
 */
+ (instancetype)visionForApp:(FIRApp *)app NS_SWIFT_NAME(vision(app:));

/**
 * Gets a barcode detector with the given options. The returned detector is not thread safe.
 *
 * @param options Options containing barcode detector configuration.
 * @return A barcode detector configured with the given options.
 */
- (FIRVisionBarcodeDetector *)barcodeDetectorWithOptions:(FIRVisionBarcodeDetectorOptions *)options
    NS_SWIFT_NAME(barcodeDetector(options:));

/**
 * Gets a barcode detector with the default options. The returned detector is not thread safe.
 *
 * @return A barcode detector configured with the default options.
 */
- (FIRVisionBarcodeDetector *)barcodeDetector;

/**
 * Gets a face detector with the given options.  The returned detector is not thread safe.
 *
 * @param options Options for configuring the face detector.
 * @return A face detector configured with the given options.
 */
- (FIRVisionFaceDetector *)faceDetectorWithOptions:(FIRVisionFaceDetectorOptions *)options
    NS_SWIFT_NAME(faceDetector(options:));

/**
 * Gets a face detector with the default options.  The returned detector is not thread safe.
 *
 * @return A face detector configured with the default options.
 */
- (FIRVisionFaceDetector *)faceDetector;

/**
 * Gets a label detector with the given options. The returned detector is not thread safe.
 *
 * @param options Options for configuring the label detector.
 * @return A label detector configured with the given options.
 */
- (FIRVisionLabelDetector *)labelDetectorWithOptions:(FIRVisionLabelDetectorOptions *)options
    NS_SWIFT_NAME(labelDetector(options:));

/**
 * Gets a label detector with the default options. The returned detector is not thread safe.
 *
 * @return A label detector configured with the default options.
 */
- (FIRVisionLabelDetector *)labelDetector;

/**
 * Gets a text detector.  The returned detector is not thread safe.
 *
 * @return A text detector.
 */
- (FIRVisionTextDetector *)textDetector;

/**
 * Gets an instance of cloud landmark detector with the given options.
 *
 * @param options Options for configuring the cloud landmark detector.
 * @return A cloud landmark detector configured with the given options.
 */
- (FIRVisionCloudLandmarkDetector *)cloudLandmarkDetectorWithOptions:
    (FIRVisionCloudDetectorOptions *)options
    NS_SWIFT_NAME(cloudLandmarkDetector(options:));

/**
 * Gets an instance of cloud landmark detector with default options.
 *
 * @return A cloud landmark detector configured with default options.
 */
- (FIRVisionCloudLandmarkDetector *)cloudLandmarkDetector;

/*
 * Gets an instance of cloud label detector with the given options.
 *
 * @param options Options for configuring the cloud label detector.
 * @return A cloud label detector configured with the given options.
 */
- (FIRVisionCloudLabelDetector *)cloudLabelDetectorWithOptions:
    (FIRVisionCloudDetectorOptions *)options NS_SWIFT_NAME(cloudLabelDetector(options:));

/**
 * Gets an instance of cloud label detector with default options.
 *
 * @return A cloud label detector configured with default options.
 */
- (FIRVisionCloudLabelDetector *)cloudLabelDetector;

/**
 * Gets an instance of cloud text detector with the given options.
 *
 * @param options Options for configuring the cloud text detector.
 * @return A cloud text detector configured with the given options.
 */
- (FIRVisionCloudTextDetector *)cloudTextDetectorWithOptions:
    (FIRVisionCloudDetectorOptions *)options NS_SWIFT_NAME(cloudTextDetector(options:));

/**
 * Gets an instance of cloud text detector with default options.
 *
 * @return A cloud text detector configured with default options.
 */
- (FIRVisionCloudTextDetector *)cloudTextDetector;

/**
 * Gets an instance of cloud document text detector with the given options.
 *
 * @param options Options for configuring the cloud text detector.
 * @return A cloud document text detector configured with the given options.
 */
- (FIRVisionCloudDocumentTextDetector *)cloudDocumentTextDetectorWithOptions:
    (FIRVisionCloudDetectorOptions *)options NS_SWIFT_NAME(cloudDocumentTextDetector(options:));

/**
 * Gets an instance of cloud document text detector with default options.
 *
 * @return A cloud document text detector configured with default options.
 */
- (FIRVisionCloudDocumentTextDetector *)cloudDocumentTextDetector;

@end

NS_ASSUME_NONNULL_END
