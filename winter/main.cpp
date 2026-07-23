// STL
#include <print>

// Engine code
#include "Drivers.h"
#include "MegaDrivers.h"

// Implementations
#include "WindowsMegaDriver.h"


struct DriverPresenceStruct {
	bool graphics = false;
	bool audio = false;
	bool input = false;
	bool net = false;
	bool filesystem = false;
};

//! Terminal screen that displays presence/absence of drivers
DriverPresenceStruct checkDrivers(
	Winter::MegaDrivers::BaseMegaDriver* megaDriver
) {
	DriverPresenceStruct presence;
	std::println("Checking drivers...");

	// graphics driver
	if (megaDriver->graphics() != nullptr) {
		std::println(
			"Graphics driver present: \"{}\" (assuming {} = 1)",
			megaDriver->graphics()->getDriverInfo().driverName,
			(int)megaDriver->graphics()->getDriverInfo().type
		);
		presence.graphics = true;
	}
	else std::println("No graphics drivers");

	// audio driver
	if (megaDriver->audio() != nullptr) {
		std::println(
			"Audio driver present: \"{}\" (assuming {} = 2)",
			megaDriver->audio()->getDriverInfo().driverName,
			(int)megaDriver->audio()->getDriverInfo().type
		);
		presence.audio = true;
	}
	else std::println("No audio drivers");

	// input driver
	if (megaDriver->input() != nullptr) {
		std::println(
			"Input driver present: \"{}\" (assuming {} = 3)",
			megaDriver->input()->getDriverInfo().driverName,
			(int)megaDriver->input()->getDriverInfo().type
		);
		presence.input = true;
	}
	else std::println("No input drivers");

	// network driver
	if (megaDriver->net() != nullptr) {
		std::println(
			"Networking driver present: \"{}\" (assuming {} = 4)",
			megaDriver->net()->getDriverInfo().driverName,
			(int)megaDriver->net()->getDriverInfo().type
		);
		presence.net = true;
	}
	else std::println("No networking drivers");

	// filesystem driver
	if (megaDriver->fs() != nullptr) {
		std::println(
			"Filesystem driver present: \"{}\" (assuming {} = 5)",
			megaDriver->fs()->getDriverInfo().driverName,
			(int)megaDriver->fs()->getDriverInfo().type
		);
		presence.filesystem = true;
	}
	else std::println("No filesystem drivers");

	return presence;
}



//! Entrypoint
int main(int argc, char** argv) {
	using namespace Winter;
	MegaDrivers::BaseMegaDriver* megaDriver;



	// We're on Windows here so we don't have many choices
	megaDriver = new MegaDrivers::Impl::Windows();

	DriverPresenceStruct driversActive = checkDrivers(megaDriver);

	if (driversActive.graphics) megaDriver->graphics()->graphicsInit();



	while (!megaDriver->shouldStop()) {
		if (driversActive.graphics) megaDriver->graphics()->graphicsDisplay();

	}
	
	if (driversActive.graphics) megaDriver->graphics()->graphicsDestroy();


}