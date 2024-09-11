#pragma once

#include "window.h"

class Game
{
public:
    Game();
    ~Game();

    void run();

    void keyInput(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    Window m_window;
};
