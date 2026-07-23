#include "WindowsMegaDriver.h"
#include "OpenGLDriver.h"
#include <print>

Winter::MegaDrivers::Impl::Windows::Windows()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Winter",
        1280, 720,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );
    
    if (!window) {
        throw std::runtime_error(
            "Couldn't create SDL window."
        );
    }

    drivers._graphics = new Drivers::Impl::OpenGL(window);

}

Winter::Drivers::BaseGraphicsDriver*
Winter::MegaDrivers::Impl::Windows::graphics()
{
    return drivers._graphics;
}

Winter::Drivers::BaseAudioDriver* 
Winter::MegaDrivers::Impl::Windows::audio()
{
    return drivers._audio;
}

Winter::Drivers::BaseInputDriver* 
Winter::MegaDrivers::Impl::Windows::input()
{
    return drivers._input;
}

Winter::Drivers::BaseNetDriver* 
Winter::MegaDrivers::Impl::Windows::net()
{
    return drivers._net;
}

Winter::Drivers::BaseFilesystemDriver* 
Winter::MegaDrivers::Impl::Windows::fs()
{
    return drivers._fs;
}

bool Winter::MegaDrivers::Impl::Windows::shouldStop()
{
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_QUIT) return true;
    }
    return false;
}

Winter::MegaDrivers::Impl::Windows::~Windows()
{}
