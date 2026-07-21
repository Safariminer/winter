#include "WindowsMegaDriver.h"

Winter::MegaDrivers::Impl::Windows::Windows()
{}

Winter::Drivers::BaseGraphicsDriver*
Winter::MegaDrivers::Impl::Windows::graphics()
{
    return nullptr;
}

Winter::Drivers::BaseAudioDriver* 
Winter::MegaDrivers::Impl::Windows::audio()
{
    return nullptr;
}

Winter::Drivers::BaseInputDriver* 
Winter::MegaDrivers::Impl::Windows::input()
{
    return nullptr;
}

Winter::Drivers::BaseNetDriver* 
Winter::MegaDrivers::Impl::Windows::net()
{
    return nullptr;
}

Winter::Drivers::BaseFilesystemDriver* 
Winter::MegaDrivers::Impl::Windows::fs()
{
    return nullptr;
}

Winter::MegaDrivers::Impl::Windows::~Windows()
{}
