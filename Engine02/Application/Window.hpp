//
//  Window.hpp
//  Engine02
//
//  Created by Chenruyi on 2026/1/30.
//

#pragma once

#include <GLFW/glfw3.h>
#include <MetalKit/MetalKit.h>
#include "RenderAdapter.h"

// Window
class Window {
private:
    GLFWwindow *pWindow;
    RenderAdapter *pRender;
    MTKView *view;
    
public:
    Window();
    ~Window();
    void run();
};

// View
class View {
public:
    View() {};
    ~View() {};
    MTKView *transfer(GLFWwindow *window);
};
