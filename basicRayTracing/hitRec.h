#ifndef HIT_REC_H
#define HIT_REC_H

#include <vector>

#include "sphere.h"

struct HitRec {
	bool doesHit{ false };
	std::vector<double> intersections;
};

#endif // !HIT_REC_H
