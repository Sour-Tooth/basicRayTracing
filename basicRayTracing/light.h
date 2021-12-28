#ifndef LIGHT_H
#define LIGHT_H

#include "vec3.h"

class Light {
public:
	enum class Types {
		Ambient,
		Point,
		Directional
	};

private:
	Types m_type;
	double m_intensity;

public:
	Light(Types type, double intensity) : m_type{ type }, m_intensity{ intensity } {};

	Types getType() const { return m_type; };
	double getIntensity() const { return m_intensity; };

	virtual double calculateIntensity(Vec3& normal, Vec3& point) const = 0;
};

#endif // LIGHT_H
