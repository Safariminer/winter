#pragma once

#include <vector>

#include "Geometry.h"


namespace Winter {
	namespace Math {

		struct Vector3 : public Vector2 {
			float z;
		};

		struct Vector4 : public Vector3 {
			float w;
		};

		struct Matrix4x4 {
			float data[16];
		};


		struct Triangle3D {
			Vector3 a, b, c;
		};

		struct Mesh {
			std::vector<Triangle3D> tris;
			bool disabled = false;
		};

	}
}

