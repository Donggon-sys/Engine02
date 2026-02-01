//
//  Renderer.cpp
//  Engine02
//
//  Created by Chenruyi on 2026/1/31.
//

#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer(MTK::View& view) {
    pDevice = view.device()->retain();
    pCommandQueue = pDevice->newCommandQueue();
    
    MTL::Library *library = pDevice->newDefaultLibrary();
    MTL::Function *vertexShader = library->newFunction(NS::String::string("vertexShader", NS::UTF8StringEncoding));
    MTL::Function *fragmentShader = library->newFunction(NS::String::string("fragmentShader", NS::UTF8StringEncoding));
    
    MTL::RenderPipelineDescriptor *pipelineDescriptor = MTL::RenderPipelineDescriptor::alloc()->init();
    pipelineDescriptor->setVertexFunction(vertexShader);
    pipelineDescriptor->setFragmentFunction(fragmentShader);
    pipelineDescriptor->colorAttachments()->object(0)->setPixelFormat(view.colorPixelFormat());
    pipelineDescriptor->setLabel(NS::String::string("triangle render pipeline", NS::UTF8StringEncoding));
    
    NS::Error *error = nullptr;
    trianglePSO = pDevice->newRenderPipelineState(pipelineDescriptor, &error);
    if (error) {
        std::cout << "创建渲染管线对象错误！" << std::endl;
    }
    
    // 数据初始化
    simd::float3 triangle[ ] = {
        {-0.5f, -0.5f, 0.0f},
        { 0.5f, -0.5f, 0.0f},
        { 0.0f,  0.5f, 0.0f}
    };
    pTriangleBuffer = pDevice->newBuffer(&triangle, sizeof(triangle), MTL::ResourceStorageModeShared);
    viewPortSize = simd::make_uint2(0, 0);
    
    error->release();
    pipelineDescriptor->release();
    library->release();
    vertexShader->release();
    fragmentShader->release();
    
}

Renderer::~Renderer() {
    pCommandQueue->release();
    pTriangleBuffer->release();
    trianglePSO->release();
    
    std::cout << "Render析构！" << std::endl;
}

void Renderer::draw(MTK::View *view) {
    NS::AutoreleasePool* pPool = NS::AutoreleasePool::alloc()->init();
    
    MTL::CommandBuffer *commandBuffer = pCommandQueue->commandBuffer();
    MTL::RenderPassDescriptor *renderPassDescriptor = view->currentRenderPassDescriptor();
    
    if (!renderPassDescriptor) {
        return;
    }
    
    MTL::RenderCommandEncoder *encoder = commandBuffer->renderCommandEncoder(renderPassDescriptor);
    encoder->setRenderPipelineState(trianglePSO);
    encoder->setVertexBuffer(pTriangleBuffer, NS::UInteger(0), NS::UInteger(0));
    encoder->drawPrimitives(MTL::PrimitiveTypeTriangle, NS::UInteger(0), NS::UInteger(3));
    encoder->endEncoding();
    
    commandBuffer->presentDrawable(view->currentDrawable());
    commandBuffer->commit();
    
    pPool->release();
}

void Renderer::drawableSizeWillChange(CGSize size) {
    viewPortSize.x = size.width;
    viewPortSize.y = size.height;
}
