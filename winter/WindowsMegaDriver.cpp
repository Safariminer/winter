#include "WindowsMegaDriver.h"

Winter::MegaDrivers::Impl::Windows::Windows()
{}

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

Winter::MegaDrivers::Impl::Windows::~Windows()
{}
