#pragma once
#include "Drivers.h"

#include <SDL3/SDL_video.h>

namespace Winter::Drivers::Impl {
	
	class OpenGL : public BaseGraphicsDriver {
		SDL_Window* window;
		SDL_GLContext glContext;
		std::vector<Math::Mesh> meshes;
		std::vector<int> unusedMeshIDs;

		void drawMeshes();

	public:
		DriverInfo getDriverInfo();

		OpenGL(SDL_Window* w);
		void graphicsInit();
		void graphicsDisplay();

		size_t uploadMesh(Math::Mesh& m);
		void unloadMesh(size_t mID);
		void graphicsDestroy();
		~OpenGL();
	};

}