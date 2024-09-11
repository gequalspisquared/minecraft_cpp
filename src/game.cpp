#include "game.h"
#include "window.h"
#include "util/log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cassert>

static void framebufferSizeCallback(GLFWwindow* window, i32 width, i32 height);
static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

Game::Game() {
    /* Initialize GLFW */
    if (!glfwInit()) {
        LOG_ERROR("Failed to initialize GLFW!");
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_window.init();
    glfwSetWindowUserPointer(m_window.getWindow(), this);

    /* Initialize GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_ERROR("Failed to initialize GLAD!");
        return;
    }
    glViewport(0, 0, m_window.getWidth(), m_window.getHeight());
    glfwSetFramebufferSizeCallback(m_window.getWindow(), framebufferSizeCallback);
    glfwSetKeyCallback(m_window.getWindow(), keyCallback);
}

Game::~Game() {
    glfwTerminate();
}

void Game::run() {
    while (!m_window.shouldClose()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_window.getWindow());
        glfwPollEvents();
    }
}

void Game::keyInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE) {
        m_window.setShouldClose(true);
    }
}

/* ------------------------------------------------------------------------- */
/* Static functions                                                          */
/* ------------------------------------------------------------------------- */
static void framebufferSizeCallback(GLFWwindow* window, i32 width, i32 height) {
    glViewport(0, 0, width, height);
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));
    game->keyInput(window, key, scancode, action, mods);
}
