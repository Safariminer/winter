#include "SDLInputDriver.h"

Winter::Drivers::DriverInfo Winter::Drivers::Impl::SDLInput::getDriverInfo()
{
	DriverInfo info;

	info.driverName = "SDL Inputs";
	info.type = DRV_INPUT;
	
	return info;
}

Winter::Drivers::Impl::SDLInput::SDLInput(SDL_Window* w)
{
	window = w;
}

void Winter::Drivers::Impl::SDLInput::inputInit()
{}

void Winter::Drivers::Impl::SDLInput::inputUpdate()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_EVENT_QUIT) {
			close = true;
		}
	}
}

bool Winter::Drivers::Impl::SDLInput::closeRequested()
{
	return close;
}

void Winter::Drivers::Impl::SDLInput::inputDestroy()
{}

Winter::Drivers::Impl::SDLInput::~SDLInput()
{

}
