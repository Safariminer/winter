#pragma once
#include "MegaDrivers.h"

#include <SDL3/SDL.h>

namespace Winter::MegaDrivers::Impl {
	//! Windows mega-driver implementation
	class Windows : public MegaDrivers::BaseMegaDriver {
		DriverCollector drivers;
		SDL_Window* window;
	public:

		Windows();

		Drivers::BaseGraphicsDriver* graphics();
		Drivers::BaseAudioDriver*       audio();
		Drivers::BaseInputDriver*       input();
		Drivers::BaseNetDriver*           net();
		Drivers::BaseFilesystemDriver*     fs();
		bool                       shouldStop();

		~Windows();
	};
}