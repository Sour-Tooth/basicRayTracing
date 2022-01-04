#include "shaders.h"
#include "vec3.h"
#include "hitRec.h"

namespace shaders {
	color_t colorByNormal(HitRec rec) {
		return {
			127.5 * (rec.normal.getX() + 1),
			127.5 * (rec.normal.getY() + 1),
			127.5 * (rec.normal.getZ() + 1)
		};
	};
};
