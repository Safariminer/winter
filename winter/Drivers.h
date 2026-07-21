#pragma once

#include <iostream>

namespace Winter {
	namespace Drivers {

		enum DriverType : char {
			DRV_ABSTRACT    =    0,
			DRV_GRAPHICS    =    1,
			DRV_AUDIO       =    2,
			DRV_INPUT       =    3,
			DRV_NET         =    4,
			DRV_FILESYSTEM  =    5,
			DRV_ERROR       = 0xFF
		};

		struct DriverInfo {
			std::string driverName;
			DriverType type;
		};


		class BaseDriver {
		public:
			virtual DriverInfo getDriverInfo() = 0;
		};

		class BaseGraphicsDriver : public BaseDriver {
		public:
			virtual void graphicsInit();
			virtual void graphicsDisplay();
			virtual void graphicsDestroy();
		};

		class BaseAudioDriver : public BaseDriver {
		public:
		};
		
		class BaseInputDriver : public BaseDriver {
		public:
		};

		class BaseNetDriver : public BaseDriver {
		public:
		};
		
		class BaseFilesystemDriver : public BaseDriver {

		};


	}
}