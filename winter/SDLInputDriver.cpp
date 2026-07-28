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
		if (e.type == SDL_EVENT_KEY_DOWN) {
			keyStatus[e.key.key] = true;
		}
		if (e.type == SDL_EVENT_KEY_UP) {
			keyStatus[e.key.key] = false;
		}
	}
}

void 
Winter::Drivers::Impl::SDLInput::setInput(std::string key, long long int val)
{
	mappings[key] = val;
}

int Winter::Drivers::Impl::SDLInput::getInput(std::string key)
{
	if (mappings.find(key) == mappings.end()) { // key is unbound
		return -1; // unbound
	}
	return mappings[key];
}

bool Winter::Drivers::Impl::SDLInput::isDown(std::string key)
{
	if (getInput(key) == -1) // if unbound
		return false;

	if (keyStatus.find(getInput(key)) == keyStatus.end()) { // not pressed yet
		keyStatus[getInput(key)] = false;
	}

	return keyStatus[getInput(key)];
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
