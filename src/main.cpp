#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include "device.h"
#include "program.h"
#include "shader.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
// set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------
float vertices[] = {
    0.5f, 0.5f, 0.0f,   // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f   // top left
};
unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 3, // first Triangle
    1, 2, 3  // second Triangle
};
int main()
{
    window win("LearnOpenGL", SCR_WIDTH, SCR_HEIGHT);
    if (!win.init())
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    program prog;
    prog.compileVertexShader("../shaders/basic.vert");
    prog.compileFragmentShader("../shaders/basic.frag");

    prog.linkProgram();
    prog.freeShaders();

    prog.setVAO();
    prog.setVBO(vertices, sizeof(vertices));
    prog.setEBO(indices, sizeof(indices));
    prog.setAttribute(0, 3, GL_FLOAT, 3 * sizeof(float), 0);

    while (!win.shouldClose())
    {
        win.processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(prog.getProgramID());
        glBindVertexArray(prog.getVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        win.swapBuffers();
        win.pollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &prog.getVAO());
    glDeleteBuffers(1, &prog.getVBO());
    glDeleteBuffers(1, &prog.getEBO());
    glDeleteProgram(prog.getProgramID());

    return 0;
}
