#ifndef WINDOWS_H
#define WINDOWS_H
#include <GLFW/glfw3.h>
#include <string>
class window
{
public:
    window(const std::string windowName, unsigned width, unsigned height) : windowName(windowName),
                                                                             width(width),
                                                                             height(height),
                                                                             win(nullptr) {}

    bool init();
    GLFWwindow *getWindow()
    {
        return win;
    }

    void setWindow();
    void processInput();

    void swapBuffers();
    void pollEvents();

    bool shouldClose();
    ~window()
    {
        glfwTerminate();
    }

private:
    unsigned width;
    unsigned height;

    std::string windowName;
    GLFWwindow *win;
};
#endif
