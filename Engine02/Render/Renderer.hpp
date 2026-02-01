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
    MTL::Device *pDevice;
    MTL::RenderPipelineState *trianglePSO;
    MTL::Buffer *pTriangleBuffer;
    MTL::CommandQueue *pCommandQueue;
    simd::uint2 viewPortSize;
    
public:
    Renderer(MTK::View& view);
    ~Renderer();
    void draw(MTK::View *view);
    void drawableSizeWillChange(CGSize size);
};
