#pragma once
#include "Drivers.h"
#include <SDL3/SDL.h>
#include <map>

namespace Winter::Drivers::Impl {
	class SDLInput : public BaseInputDriver {
		SDL_Window* window;
		std::map<SDL_Keycode, bool> keyStatus;
		bool close = false;
	public:
		DriverInfo getDriverInfo();

		SDLInput(SDL_Window* w);
		
		void inputInit();
		void inputUpdate();
		void setInput(std::string key, long long int val);
		int getInput(std::string key);
		bool isDown(std::string key);
		bool closeRequested();
		void inputDestroy();

		~SDLInput();
	};
}