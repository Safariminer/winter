#include "OpenGLDriver.h"

#include <print>
#ifdef _WIN64
#include <Windows.h>
#endif
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Geometry3D.h"

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



float angle = 0;

void Winter::Drivers::Impl::OpenGL::graphicsDisplay()
{
	int screenWidth = 0, screenHeight = 0;

	if (!SDL_GetWindowSizeInPixels(window, &screenWidth, &screenHeight)) {
		throw std::runtime_error(
			std::format(
				"Couldn't get SDL window size : {}",
				SDL_GetError()
			)
		);
	}

	glViewport(0, 0, screenWidth, screenHeight);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/*Math::Matrix4x4 proj = Math::perspective(
		60, { (float)screenWidth, (float)screenHeight }, { 1, 100 }
	);

	glLoadMatrixf(proj.data);*/

    gluPerspective(60, (double)screenWidth / (double)screenHeight, 1, 100);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);


    angle += 0.5;

	SDL_GL_SwapWindow(window);
}

void Winter::Drivers::Impl::OpenGL::graphicsDestroy()
{}

Winter::Drivers::Impl::OpenGL::~OpenGL()
{}
