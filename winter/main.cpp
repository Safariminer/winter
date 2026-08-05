// STL
#include <print>
#include <filesystem>

// Engine code
#include "Drivers.h"
#include "MegaDrivers.h"
#include "../common/WinterCommon.h"

// Implementations
#include "WindowsMegaDriver.h"

#include <Windows.h>
#include <libloaderapi.h>

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


#include <fstream>
#include <string>
#include <sstream>

 // DO NOT USE THIS IMPLEMENTATION
// IT ASSUMES TRIANGULAR FACES AND DOESN'T DEAL WITH NORMALS NOR TEXCOORDS
Winter::Math::Mesh parseObj(std::string path) {
	using namespace Winter;
	Math::Mesh m;

	std::vector<Math::Vector3> vertices;

	std::ifstream in(path);
	std::string line;

	while (std::getline(in, line)) {

		if (line != "") {
			std::stringstream ss(line);
			
			std::string op; ss >> op;

			if (op == "v") {
				float x, y, z;
				ss >> x >> y >> z;

				vertices.push_back({ x * 25, y * 25, z* 25 });
			}

			if (op == "f") {
				std::string a, b, c;
				std::string a2 = "", b2 = "", c2 = "";

				ss >> a >> b >> c;

				Math::Triangle3D tri;

				for (const char& ch : a) {
					if (ch == '/') break;
					a2 += ch;
				}

				for (const char& ch : b) {
					if (ch == '/') break;
					b2 += ch;
				}

				for (const char& ch : c) {
					if (ch == '/') break;
					c2 += ch;
				}

				tri.a = vertices[std::stoi(a2) - 1];
				tri.b = vertices[std::stoi(b2) - 1];
				tri.c = vertices[std::stoi(c2) - 1];

				m.tris.push_back(tri);
			}
		}



	}
	return m;
}


int proofOfCalling() {
	std::println("Proof that the game can call the engine.");
	return 0x01020304;
}

//! Entrypoint
int main(int argc, char** argv) {
	using namespace Winter;


	MegaDrivers::BaseMegaDriver* megaDriver;

	#ifdef _DEBUG

	if (std::filesystem::exists("game.dll")) {
		std::filesystem::remove("game.dll");
		std::println("DEBUG - REMOVED PREVIOUS GAME DLL");
	}
	std::println("DEBUG - COPIED NEW GAME DLL");
	std::filesystem::copy_file("../x64/Debug/game.dll", "game.dll");

	#endif

	HMODULE gameDLL = LoadLibraryA("game.dll");

	FuncExchange fe =
		(FuncExchange)GetProcAddress(gameDLL, "exchangeFunctions");

	WinterEngineHandle eHnd = {
		.ProofOfCalling = proofOfCalling
	};

	WinterGameHandle gHnd = fe(eHnd);
	if (gHnd.ProofOfCalling() == 0x05060708) {
		std::println("Engine called game successfully.");
	}

	// We're on Windows here so we don't have many choices
	megaDriver = new MegaDrivers::Impl::Windows();

	DriverPresenceStruct driversActive = checkDrivers(megaDriver);

	if (driversActive.graphics) {
		megaDriver->graphics()->graphicsInit();

		Math::Mesh mesh = 
			parseObj("testmodels/ambientcg/3DApple002_LQ-1K-PNG.obj");
		megaDriver->graphics()->uploadMesh(mesh);


	}
	if (driversActive.input) megaDriver->input()->inputInit();


	while (!megaDriver->shouldStop()) {
		if (driversActive.input) megaDriver->input()->inputUpdate();
		if (driversActive.graphics) megaDriver->graphics()->graphicsDisplay();

	}
	
	if (driversActive.graphics) megaDriver->graphics()->graphicsDestroy();
	if (driversActive.input) megaDriver->input()->inputDestroy();


}