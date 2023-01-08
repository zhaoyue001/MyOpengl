#ifndef WINDOWS_H
#define WINDOWS_H
#include <glfw/glfw3.h>
#include <string>
class windows
{
public:
    windows(const std::string windowName, unsigned width, unsigned height) : windowName(windowName),
                                                                             width(width),
                                                                             height(height),
                                                                             window(nullptr) {}

    bool init();
    GLFWwindow *getWindow()
    {
        return window;
    }

    void setWindow(void (*frameBufferCallBack)(GLFWwindow *window, int width, int height));
    void processInput();

    void swapBuffers();
    void pollEvents();

    bool shouldClose();
    ~windows()
    {
        glfwTerminate();
    }

private:
    unsigned width;
    unsigned height;

    std::string windowName;
    GLFWwindow *window;
};
#endif
