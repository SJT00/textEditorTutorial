#include "keyboard.h"
#include "../../core/editor.h"
#include <iostream>

void KeyboardHandler::CharCallback(GLFWwindow *window, unsigned int codepoint)
{
    Editor *handler = (Editor *)glfwGetWindowUserPointer(window);
    char latestChar = (char)codepoint;
    handler->textArr[0] += latestChar;
    // get char specific advance
    Character lastChar = handler->textRenderer.Characters[(char)codepoint];
    handler->cursorloc[0] += lastChar.Advance >> 6;
}

void KeyboardHandler::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Editor *handler = (Editor *)glfwGetWindowUserPointer(window);

    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        handler->SetCursorActive(true);
        if (key == GLFW_KEY_RIGHT)
        {
            handler->cursorloc[0] += Globals::fontWidth + 1;
        }
        if (key == GLFW_KEY_LEFT)
        {
            handler->cursorloc[0] -= Globals::fontWidth - 1;
        }
        if (key == GLFW_KEY_UP)
        {
            handler->cursorloc[1] += Globals::fontSize;
        }
        if (key == GLFW_KEY_DOWN)
        {
            handler->cursorloc[1] -= Globals::fontSize;
        }
    }
    else
    {
        handler->SetCursorActive(false);
    }
}