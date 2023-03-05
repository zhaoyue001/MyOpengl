#include <glad/glad.h>
#include <GLFW/glfw3.h>
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
//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
};
unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 3, // first Triangle
    1, 2, 3  // second Triangle
};
#define CHECK_RESULT(ret) if(!(ret)) return -1;
int main()
{
    bool ret = true;
    window win("LearnOpenGL", SCR_WIDTH, SCR_HEIGHT);
    ret &= win.init();
    CHECK_RESULT(ret)
    
    program prog;
    ret &= prog.compileVertexShader("../../shaders/texture.vert");
    ret &= prog.compileFragmentShader("../../shaders/texture.frag");
    CHECK_RESULT(ret)

    ret &= prog.linkProgram();
    CHECK_RESULT(ret)

    prog.freeShaders();

    prog.setVAO();
    prog.setVBO(vertices, sizeof(vertices));
    prog.setEBO(indices, sizeof(indices));
    prog.setAttribute(0, 3, GL_FLOAT, 8 * sizeof(float), 0);
    prog.setAttribute(1, 3, GL_FLOAT, 8 * sizeof(float), 3 * sizeof(float));
    prog.setAttribute(2, 2, GL_FLOAT, 8 * sizeof(float), 6 * sizeof(float));
    ret &= prog.setTexture("../../resource/container.jpg");
    CHECK_RESULT(ret)

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
