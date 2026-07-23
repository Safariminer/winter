#pragma once

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

		//! Perspective matrix calculations
		/*! Calculates the matrix for perspective using FOV, screen size and
		*   clipping planes.
		* 
		*   \param[in] fovy The camera's vertical field of view
		*   \param[in] screenSize The size of the render area as X and Y
		*   \param[in] clips Clipping planes, close as X, far as Y
		* 
		*/
		Matrix4x4 perspective(float fovy, Vector2 screenSize, Vector2 clips);

	}
}

