#pragma once

#include "Geometry.h"
#include <vector>

namespace Winter {
	namespace Graphics {
		
		struct Color {
			unsigned char r, g, b, a;
		};

		struct Image {
			std::vector<Color> pixels;
			size_t width, height;
		};

		Image errorImage(Math::Vector2 size);

	}
}