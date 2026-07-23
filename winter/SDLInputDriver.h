#pragma once
#include "Drivers.h"
#include <SDL3/SDL.h>

namespace Winter::Drivers::Impl {
	class SDLInput : public BaseInputDriver {
		SDL_Window* window;

		bool close = false;
	public:
		DriverInfo getDriverInfo();

		SDLInput(SDL_Window* w);
		
		void inputInit();
		void inputUpdate();
		bool closeRequested();
		void inputDestroy();

		~SDLInput();
	};
}