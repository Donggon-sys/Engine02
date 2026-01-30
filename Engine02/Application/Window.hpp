//
//  Window.hpp
//  Engine02
//
//  Created by Chenruyi on 2026/1/30.
//

#pragma once

#include <GLFW/glfw3.h>
#include "RenderAdapter.h"

class Window {
private:
    GLFWwindow *pWindow;
    RenderAdapter *_render;
    
public:
    Window();
    ~Window();
    void run();
};
