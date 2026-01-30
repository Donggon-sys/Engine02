//
//  Window.cpp
//  Engine02
//
//  Created by Chenruyi on 2026/1/30.
//

#if !__has_feature(objc_arc)
    #error "This file must be compiled with ARC enabled"
#endif

#include "Window.hpp"
#include "RenderAdapter.h"

#define GLFW_INCLUDE_ONCE
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3native.h>
#include <Metal/Metal.h>
#include <MetalKit/MetalKit.h>

Window::Window() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    pWindow = glfwCreateWindow(853, 533, "window", NULL, NULL);
    if (!pWindow) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    NSWindow *nsWindow = glfwGetCocoaWindow(pWindow);
    CGRect frame = [nsWindow.contentView frame];
    MTKView *view = [[MTKView alloc] initWithFrame:frame];
    view.device = MTLCreateSystemDefaultDevice();
    view.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;
    [nsWindow.contentView addSubview:view];
    
    pRender = [[RenderAdapter alloc] initWithMTKView:view];
}

void Window::run() {
    while (!glfwWindowShouldClose(pWindow)) {
        glfwPollEvents();
    }
}

Window::~Window() {
    glfwTerminate();
}
