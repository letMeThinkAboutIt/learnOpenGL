#include "openglByGlfwGlad.h"


#include <iostream>

bool openglByGlfwGlad::initOpengl()
{
    if (glfwInit() != GLFW_TRUE) {
        std::cout << "glfw err" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (this->createWindow() != true) {
        return false;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << " glad err" << std::endl;
        return false;
    }

    return true;
}

void openglByGlfwGlad::run()
{
    auto framebuffer_size_callback = [](GLFWwindow* window, int width, int height)->void {
        uint16_t x = 0, y = 0, w = 0, h = 0;
        uint16_t margin = 50;
        x = y = margin;
        w = width - 2 * margin;
        h = height - 2 * margin;

        glViewport(x, y, w, h);
    };

    framebuffer_size_callback(nullptr, _winWidth, _winHeight);
    
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(_window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    glfwTerminate();
}

bool openglByGlfwGlad::createWindow()
{
    _window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(_window);

    return true;
}
