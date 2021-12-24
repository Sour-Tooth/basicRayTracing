#include <cmath>

#include "sphere.h"
#include "vec3.h"
#include "hitRec.h"


const HitRec Sphere::hit(Ray r) {
	HitRec rec{ false };

	// calc if sphere and ray hit; take closest intersection
	const auto D{ r.getDirection() };
	const auto co{ Config::cameraOrigin - m_center };

	const auto a{ dot(D, D) };
	const auto b{ 2 * dot(co, D) };
	const auto c{ dot(co, co) - m_radius * m_radius };

	const double discriminant{ b * b - 4 * a * c };
	if (discriminant < 0.0) return rec;

	// (t1, t2) are the distances down ray where intersection happens
	const double t1{ (-b + std::sqrt(discriminant)) / (2 * a) };
	const double t2{ (-b - std::sqrt(discriminant)) / (2 * a) };

	rec.doesHit = true;
	rec.intersections.push_back(t1);
	rec.intersections.push_back(t2);

	return rec;
};
