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

	double getRadius() const { return m_radius; }
	point3_t getCenter() const { return m_center; }
	color_t getColor() const { return m_color; }

	HitRec hit(Ray r) const;
};

#endif // !SPHERE_H
