#pragma once

#include "util/types.h"

struct GLFWwindow;

class Window
{
public:
    Window();
    ~Window();

    /* Call init on the window once GLFW has been initialized */
    void init();

    /* Getters & Setters */
    void setShouldClose(bool should_close);
    bool shouldClose() const;

    u32         getWidth() const;
    u32         getHeight() const;
    GLFWwindow* getWindow() const;

private:
    GLFWwindow* m_window;
    u32 m_width;
    u32 m_height;
};
