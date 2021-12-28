#ifndef LIGHT_POINT_H
#define LIGHT_POINT_H

#include "light.h"
#include "vec3.h"

class Light_Point : public Light {
private:
	Vec3 m_position;

public:
	Light_Point(double intensity, Vec3 position) :
		Light{ Types::Point, intensity }, m_position{ position } {};

	double calculateIntensity(Vec3& normal, Vec3& point) const  {
		auto NdotL = dot(normal, m_position - point);
		if (NdotL > 0.0) {
			return getIntensity() * NdotL / (normal.length() * m_position.length());
		}
		else { return 0.0; };
	};
};

#endif // LIGHT_POINT_H
