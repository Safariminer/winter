#pragma once

#include "Drivers.h"

namespace Winter {

	//! Mega-drivers
	/*! Mega-drivers are platform-wide drivers that manage the choice of usage
	*   of lower level APIs. 
	*/
	namespace MegaDrivers {


		//! Driver collector
		/*! Helper structure that can store pointers to the drivers.
		* \remark This is not strictly necessary to implement a mega-driver. It
		* only serves as an aid to the implementation.
		*/
		struct DriverCollector {
			Drivers::BaseGraphicsDriver* _graphics = nullptr;
			Drivers::BaseAudioDriver*       _audio = nullptr;
			Drivers::BaseInputDriver*       _input = nullptr;
			Drivers::BaseNetDriver*           _net = nullptr;
			Drivers::BaseFilesystemDriver*     _fs = nullptr;
		};


		//! Base mega-driver class
		/*! Boilerplate class to derive to implement a mega-driver.
		*   Implement all functions to get a functional mega-driver.
		* 
		*   All functions should return a pointer to the current corresponding
		*   driver or return ``nullptr`` if the driver is absent.
		*/
		class BaseMegaDriver {
		public:
			virtual Drivers::BaseGraphicsDriver* graphics() = 0;
			virtual Drivers::BaseAudioDriver*       audio() = 0;
			virtual Drivers::BaseInputDriver*       input() = 0;
			virtual Drivers::BaseNetDriver*           net() = 0;
			virtual Drivers::BaseFilesystemDriver*     fs() = 0;
		};
	}
}