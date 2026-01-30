//
//  Renderer.hpp
//  Engine02
//
//  Created by Chenruyi on 2026/1/31.
//

#pragma once
#include <simd/simd.h>
#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>

class Renderer {
private:
    MTK::View *pView;
    
public:
    Renderer(MTK::View *view);
    ~Renderer();
};
