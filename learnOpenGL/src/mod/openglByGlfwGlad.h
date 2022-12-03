#pragma once

#include "openglInit.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class openglByGlfwGlad : public openglInit
{
public:
	bool initOpengl() override;
	void run() override;

private:
	bool createWindow();
	uint16_t _winWidth = 800;
	uint16_t _winHeight = 600;
	uint16_t _viewPortMargin = 10;
	uint16_t _viewWidth;
	uint16_t _viewHeight;

	GLFWwindow* _window;
};

