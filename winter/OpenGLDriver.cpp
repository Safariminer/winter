#include "OpenGLDriver.h"

#include <print>
#ifdef _WIN64
#include <Windows.h>
#endif
#include <gl/GL.h>

Winter::Drivers::DriverInfo Winter::Drivers::Impl::OpenGL::getDriverInfo()
{
	DriverInfo info;

	info.driverName = "Generic OpenGL";
	info.type = Drivers::DRV_GRAPHICS;

	return info;
}

Winter::Drivers::Impl::OpenGL::OpenGL(SDL_Window* w)
{
	window = w;
}

void Winter::Drivers::Impl::OpenGL::graphicsInit()
{
	glContext = SDL_GL_CreateContext(window);
	if (!glContext) {
		throw std::runtime_error(
			std::format(
				"Couldn't create GL context: {}",
				SDL_GetError()
			)
		);
	}
	glEnable(GL_DEPTH_TEST);
}

void Winter::Drivers::Impl::OpenGL::graphicsDisplay()
{
	
}

void Winter::Drivers::Impl::OpenGL::graphicsDestroy()
{}

Winter::Drivers::Impl::OpenGL::~OpenGL()
{}
