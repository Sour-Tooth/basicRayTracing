#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
private:
	point3_t m_origin;
	Vec3 m_directon;

public:
	Ray(point3_t origin, Vec3 direction) : m_origin{ origin }, m_directon(direction) {};

	point3_t getOrigin() { return m_origin; }
	Vec3 getDirection() { return m_directon; }

	point3_t at(double t) { return m_origin + t * m_directon; };
};

#endif
