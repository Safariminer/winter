// STL
#include <print>

// Engine code
#include "Drivers.h"
#include "MegaDrivers.h"

// Implementations
#include "WindowsMegaDriver.h"


//! Terminal screen that displays presence/absence of drivers
void checkDrivers(Winter::MegaDrivers::BaseMegaDriver* megaDriver) {
	std::println("Checking drivers...");

	if (megaDriver->graphics() != nullptr) {
		std::println(
			"Graphics driver present: \"{}\" (assuming {} = 1)",
			megaDriver->graphics()->getDriverInfo().driverName,
			(int)megaDriver->graphics()->getDriverInfo().type
		);
	}
	else std::println("No graphics drivers");

	if (megaDriver->audio() != nullptr) {
		std::println(
			"Audio driver present: \"{}\" (assuming {} = 2)",
			megaDriver->audio()->getDriverInfo().driverName,
			(int)megaDriver->audio()->getDriverInfo().type
		);
	}
	else std::println("No audio drivers");


	if (megaDriver->input() != nullptr) {
		std::println(
			"Input driver present: \"{}\" (assuming {} = 3)",
			megaDriver->input()->getDriverInfo().driverName,
			(int)megaDriver->input()->getDriverInfo().type
		);
	}
	else std::println("No input drivers");

	if (megaDriver->net() != nullptr) {
		std::println(
			"Networking driver present: \"{}\" (assuming {} = 4)",
			megaDriver->net()->getDriverInfo().driverName,
			(int)megaDriver->net()->getDriverInfo().type
		);
	}
	else std::println("No networking drivers");

	if (megaDriver->fs() != nullptr) {
		std::println(
			"Filesystem driver present: \"{}\" (assuming {} = 5)",
			megaDriver->fs()->getDriverInfo().driverName,
			(int)megaDriver->fs()->getDriverInfo().type
		);
	}
	else std::println("No filesystem drivers");
}



//! Entrypoint
int main(int argc, char** argv) {
	using namespace Winter;
	MegaDrivers::BaseMegaDriver* megaDriver;



	// We're on Windows here so we don't have many choices
	megaDriver = new MegaDrivers::Impl::Windows();

	checkDrivers(megaDriver);


}