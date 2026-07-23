#include "Geometry3D.h"

#define _USE_MATH_DEFINES
#include <cmath>

Winter::Math::Matrix4x4 
Winter::Math::perspective(float fovy, Vector2 screenSize, Vector2 clips)
{

    Matrix4x4 m;

    float f = 1.0f / tanf(fovy * 0.5f * (M_PI / 180));
    
    float a = screenSize.x / screenSize.y;

    m.data[ 0] = f / a;
    m.data[ 1] = 0;
    m.data[ 2] = 0;
    m.data[ 3] = 0;

    m.data[ 4] = 0;
    m.data[ 5] = f;
    m.data[ 6] = 0;
    m.data[ 7] = 0;

    m.data[ 8] = 0;
    m.data[ 9] = 0;
    m.data[10] = (clips.x + clips.y) /  (clips.x - clips.y);
    m.data[11] = 0;

    m.data[12] = 0;
    m.data[13] = 0;
    m.data[14] = (2 * clips.x * clips.y) / (clips.x - clips.y);
    m.data[15] = 0;


    return Matrix4x4();
}
