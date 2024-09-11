#include "window.h"
#include "util/log.h"

#include <GLFW/glfw3.h>

#include <cassert>

static const u32   DEFAULT_WIDTH  = 800;
static const u32   DEFAULT_HEIGHT = 600;
static const char* DEFAULT_TITLE  = "Default Title";

Window::Window() {
    m_width  = DEFAULT_WIDTH;
    m_height = DEFAULT_HEIGHT;
    m_window = nullptr;
}

Window::~Window() {
    if (m_window) {
        glfwDestroyWindow(m_window);
    }
}

void Window::init() {
    m_window = glfwCreateWindow(
        m_width,
        m_height,
        DEFAULT_TITLE,
        nullptr,
        nullptr
    );
    if (!m_window) {
        LOG_ERROR("Failed to create a GLFW window!");
        return;
    }
    assert(m_window);
    glfwMakeContextCurrent(m_window);
}

void Window::setShouldClose(bool should_close) {
    glfwSetWindowShouldClose(m_window, should_close);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_window);
}

u32 Window::getWidth() const {
    return m_width;
}

u32 Window::getHeight() const {
    return m_height;
}

GLFWwindow* Window::getWindow() const {
    return m_window;
}
