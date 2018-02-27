#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

/**
 * Basic native module without support emit event, we just need NSObject<RCTBridgeModule>
 * othercase we need RCTEventEmitter<RCTBridgeModule>
 */
@interface RNCustom: RCTEventEmitter <RCTBridgeModule>

@end
  
