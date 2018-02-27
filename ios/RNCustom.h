#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif
#import <React/RCTEventEmitter.h>

/**
 * Basic native module without support emit event, we just need NSObject<RCTBridgeModule>
 * othercase we need RCTEventEmitter<RCTBridgeModule>
 */
@interface RNCustom: RCTEventEmitter <RCTBridgeModule>

@end
  
