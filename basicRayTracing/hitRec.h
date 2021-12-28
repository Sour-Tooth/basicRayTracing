#ifndef HIT_REC_H
#define HIT_REC_H

#include <vector>

#include "sphere.h"

class Sphere;

struct HitRec {
	const Sphere* sphere{ nullptr };
	bool doesHit{ false };
	double intersectionDistance;
	Vec3 normal;
};

#endif // !HIT_REC_H
