#include "Graphics.h"

Winter::Graphics::Image Winter::Graphics::errorImage(Winter::Math::Vector2 size)
{
	Image img;

	img.width  = (unsigned) size.x;
	img.height = (unsigned) size.y;

	img.pixels.resize(img.width * img.height);

	Color purple = { 255,0,255,255 };
	Color black = { 0,0,0,255 };

	for (unsigned y = 0; y < img.height; y++) {
		for (unsigned x = 0; x < img.width; x++) {
			img.pixels[y * img.width + x] =
				x > (img.width / 2) ?
				y > (img.height / 2) ? purple : black :
				y < (img.height / 2) ? purple : black;
		}
	}


	return img;
}