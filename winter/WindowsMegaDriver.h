#pragma once
#include "MegaDrivers.h"



namespace Winter::MegaDrivers::Impl {
	//! Windows mega-driver implementation
	class Windows : public MegaDrivers::BaseMegaDriver {
		DriverCollector drivers;
	public:

		Windows();

		Drivers::BaseGraphicsDriver* graphics();
		Drivers::BaseAudioDriver*       audio();
		Drivers::BaseInputDriver*       input();
		Drivers::BaseNetDriver*           net();
		Drivers::BaseFilesystemDriver*     fs();

		~Windows();
	};
}