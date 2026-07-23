#pragma once
#include "Drivers.h"

#include <SDL3/SDL_video.h>

namespace Winter::Drivers::Impl {
	
	class OpenGL : public BaseGraphicsDriver {
		SDL_Window* window;
		SDL_GLContext glContext;
	
	public:
		DriverInfo getDriverInfo();

		OpenGL(SDL_Window* w);
		void graphicsInit();
		void graphicsDisplay();

		size_t uploadMesh(Math::Mesh& m);

		void graphicsDestroy();
		~OpenGL();
	};

}