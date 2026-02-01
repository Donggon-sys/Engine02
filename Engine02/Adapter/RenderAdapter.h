//
//  RenderAdapter.h
//  Engine02
//
//  Created by Chenruyi on 2026/1/31.
//
#pragma once
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>

@class MTKView;

NS_ASSUME_NONNULL_BEGIN

@interface RenderAdapter : NSObject

-(instancetype)initWithMTKView:(MTKView *)view;
- (void)drawInMTKView:(nonnull MTKView *)view;

@end

NS_ASSUME_NONNULL_END
