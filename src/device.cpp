#include <glad/glad.h>
#include "device.h"


// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}
void errorCallback(int error, const char *description) {
  fprintf(stderr, "GLFW error %d: %s\n", error, description);
}
bool window::init() {
  glfwSetErrorCallback(errorCallback);
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
  setWindow();

  // glad: load all OpenGL function pointers
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    return -1;
  }
  return true;
}

void window::setWindow() {
  glfwMakeContextCurrent(win);
  glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
}

void window::processInput() {
  if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(win, true);
}

void window::swapBuffers() { glfwSwapBuffers(win); }
void window::pollEvents() { glfwPollEvents(); }

bool window::shouldClose() { return glfwWindowShouldClose(win); }