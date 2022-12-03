#include <iostream>

#include "openglByGLfwGlad.h"

int main() {
	
	openglInit* pGlInit = new openglByGlfwGlad;
	if (pGlInit == nullptr) {
		std::cout << "new gl init err" << std::endl;
		return -1;
	}
	
	if (true != pGlInit->initOpengl()) {
		std::cout << "gl init err" << std::endl;
		return -1;
	}

	pGlInit->run();

	std::cout << "learn opengl start " << std::endl;
}