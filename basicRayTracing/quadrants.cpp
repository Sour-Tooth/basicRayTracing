#include "shaders.h"
#include "vec3.h"

namespace shaders {
	color_t quadrants(int x, int y) {
		// quadrants 1 -> 4 : white, red, green, blue 
		if (x > 0 && y > 0) {
			return{ 255, 255, 255 };
		}
		else if (x > 0 && y < 0) {
			return{ 255, 0, 0 };
		}
		else if (x < 0 && y < 0) {
			return { 0, 255, 0 };
		}
		else if (x < 0 && y > 0) {
			return { 0, 0, 255 };
		}
		else {
			return { 0, 0, 0 };
		}
	};
};