#ifndef SPHERE_H
#define SPHERE_H

#include "config.h"
#include "vec3.h"
#include "ray.h"
#include "hitRec.h"

class Sphere {
private:
	double m_radius;
	point3_t m_center;
	color_t m_color;

public:
	Sphere(double radius, point3_t center, color_t color) : m_radius{ radius }, m_center{ center }, m_color{ color } {};

	double const getRadius() { return m_radius; }
	point3_t const getCenter() { return m_center; }
	color_t const getColor() { return m_color; }

	const HitRec hit(Ray r);
};

#endif // !SPHERE_H
