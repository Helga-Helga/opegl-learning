#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <GLFW/glfw3.h>
#include <GLES3/gl3.h>

float points[] = {
    0.0f, 0.5f, 0.0f,
    0.5f, -0.5f, -0.0f,
    -0.5f, -0.5f, 0.0f
};

const char* vertex_shader =
"#version 400\n"
"in vec3 vp;"
"void main() {"
"    gl_Position = vec4(vp, 1.0);"
"}";

const char* fragment_shader =
"#version 400\n"
"out vec4 frag_colour;"
"void main() {"
"    frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
"}";

void error_callback(int error, const char* description)
{
    std::cout << "Error: " << description << std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main()
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        std::cout << "GLFW library initialization failed" << std::endl;;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Simple Triangle", NULL, NULL);
    if (window == nullptr)
    {
        std::cout << "Window or OpenGL context creation failed." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    GLuint points_vbo = 0; // vertex buffer object
    glGenBuffers(1, &points_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

    GLuint vao = 0; // vertex array object
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0); // single vertex buffer, it will be attriute location 0
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    // Define layout of the first vertex buffer (with attribute location 0),
    // make vec3 from every 3 floats in the buffer.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    // Combine compiled shaders in to a signle, executable GPU shader program.
    GLuint shader_program = glCreateProgram();
    glAttachShader(shader_program, vs);
    glAttachShader(shader_program, fs);
    glLinkProgram(shader_program);

    while (glfwWindowShouldClose(window) == 0)
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        // Clear the drawing surface.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set the shader program to use for all further drawing.
        glUseProgram(shader_program);
        // Set VAO as the input variables that should be used for all further drawing.
        glBindVertexArray(vao);
        // Draw in triangles mode (1 triangle for every 3 points).
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // GLFW windows by default use double buffering.
        // That means that each window has two rendering buffers: a front buffer and a back buffer.
        // The front buffer is the one being displayed and the back buffer the one you render to.
        // When the entire frame has been rendered, the buffers need to be swapped with one another,
        // so the back buffer becomes the front buffer and vice versa.
        glfwSwapBuffers(window);

        // Process events.
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    // Destory any remaining windows and release resources allocated by GLFW.
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
