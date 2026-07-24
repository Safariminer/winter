#pragma once
#include "Drivers.h"

namespace Winter::Drivers::Impl {
	class StandardFilesystem : BaseFilesystemDriver {
	public:
		StandardFilesystem();

		void fsInit();

		std::optional<std::vector<char>> fsGet(std::string p);
		bool fsWrite(std::vector<char> s, std::string p);


		void fsDestroy();

		~StandardFilesystem();
	};
}