#pragma once

#include <iostream>
#include "Geometry3D.h"

namespace Winter {

	//! Drivers
	/*! One platform can have many drivers for each category for compatibility.
	*/ 
	namespace Drivers {

		//! Type of a driver
		enum DriverType : char {
			//! Abstract drivers (unused)
			DRV_ABSTRACT = 0,  
			//! Graphical drivers
			DRV_GRAPHICS = 1,
			//! Audio drivers   
			DRV_AUDIO = 2,
			//! Input drivers  
			DRV_INPUT = 3,
			//! Network-related drivers  
			DRV_NET = 4,
			//! Filesystem-related drivers  
			DRV_FILESYSTEM = 5,
			//! Error type  
			DRV_ERROR = 0xFF   
		};

		//! Information of a driver
		/*! Use `(yourDriverInstance)->getDriverInfo()` to retrieve it or
		*   implement it first in your driver class.
		*/
		struct DriverInfo {
			std::string driverName;
			DriverType type;
		};

		//! Base driver class
		/*! Base driver class from which all drivers derive.
		* 
		* \warning You probably don't want to derive from this. See:
		* - BaseGraphicsDriver
		* - BaseAudioDriver
		* - BaseInputDriver
		* - BaseNetDriver
		* - BaseFilesystemDriver
		*/
		class BaseDriver {
		public:
			virtual DriverInfo getDriverInfo() = 0;
		};


		//! Base graphical driver class
		/*! Boilerplate for all drivers that deal with graphics.
		*   Implement all functions to get a working driver.
		*/
		class BaseGraphicsDriver : public BaseDriver {
		public:
			virtual void graphicsInit() = 0;
			virtual void graphicsDisplay() = 0;

			virtual size_t uploadMesh(Math::Mesh& m) = 0;
			virtual void unloadMesh(size_t mID) = 0;

			virtual void graphicsDestroy() = 0;
		};

		//! Base audio driver class
		/*! Boilerplate for all drivers that deal with audio.
		*   Implement all functions to get a working driver.
		*/
		class BaseAudioDriver : public BaseDriver {
		public:
		};
		
		//! Base input driver class
		/*! Boilerplate for all drivers that deal with input.
		*   Implement all functions to get a working driver.
		*/
		class BaseInputDriver : public BaseDriver {
		public:
			virtual void inputInit() = 0;
			virtual void inputUpdate() = 0;
			virtual bool closeRequested() = 0;
			virtual void inputDestroy() = 0;
		};

		//! Base network driver class
		/*! Boilerplate for all drivers that deal with networking.
		*   Implement all functions to get a working driver.
		*/
		class BaseNetDriver : public BaseDriver {
		public:
		};
		
		//! Base filesystem driver class
		/*! Boilerplate for all drivers that deal with files.
		*   Implement all functions to get a working driver.
		*/
		class BaseFilesystemDriver : public BaseDriver {

		};


	}
}