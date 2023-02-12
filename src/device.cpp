#include "device.h"
bool window::init()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    win = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
    if (win == nullptr)
        return false;

    return true;
}

void window::setWindow(void (*frameBufferCallBack)(GLFWwindow *window, int width, int height))
{
    glfwMakeContextCurrent(win);
    glfwSetFramebufferSizeCallback(win, frameBufferCallBack);
}

void window::processInput()
{
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(win, true);
}

void window::swapBuffers() {
    glfwSwapBuffers(win);
}
void window::pollEvents() {
    glfwPollEvents();
}

bool window::shouldClose() {
    return glfwWindowShouldClose(win);
}