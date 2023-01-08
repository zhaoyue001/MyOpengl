#include "windows.h"
bool windows::init()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
    if (window == nullptr)
        return false;

    return true;
}

void windows::setWindow(void (*frameBufferCallBack)(GLFWwindow *window, int width, int height))
{
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferCallBack);
}

void windows::processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void windows::swapBuffers() {
    glfwSwapBuffers(window);
}
void windows::pollEvents() {
    glfwPollEvents();
}

bool windows::shouldClose() {
    return glfwWindowShouldClose(window);
}