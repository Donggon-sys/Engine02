//
//  RenderAdapter.m
//  Engine02
//
//  Created by Chenruyi on 2026/1/31.
//

#import "RenderAdapter.h"
#include "Renderer.hpp"

//MARK: - Metal-cpp的实现
#define NS_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTK_PRIVATE_IMPLEMENTATION

#include <Foundation/Foundation.hpp>
#include <QuartzCore/QuartzCore.hpp>
#include <Metal/Metal.hpp>

@interface RenderAdapter () {
    Renderer *_pRender;
    MTL::Device *_pDevice;
}

@end

@implementation RenderAdapter

- (instancetype)initWithMTKView:(MTKView *)view {
    if (self = [super init]) {
        _pRender = new Renderer((__bridge MTK::View *)view);
    }
    return self;
}

@end
