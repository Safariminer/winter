#pragma once
#include "Drivers.h"
#include <SDL3/SDL.h>
#include <map>

namespace Winter::Drivers::Impl {

	//! SDL implementation of the BaseInputDriver abstract class
	class SDLInput : public BaseInputDriver {
		SDL_Window* window;
		std::map<SDL_Keycode, bool> keyStatus;
		std::map<std::string, SDL_Keycode> mappings;
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