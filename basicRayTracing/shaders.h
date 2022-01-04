#ifndef SHADERS_H
#define SHADERS_H

#include "vec3.h"
#include "hitRec.h"

// declerations
namespace shaders {
	color_t quadrants(int x, int y);
	color_t colorByNormal(HitRec rec);
};

#endif // SHADERS_H
