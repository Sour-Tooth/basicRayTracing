#ifndef LIGHT_DIRECTIONAL_H
#define LIGHT_DIRECTIONAL_H

#include "light.h"
#include "vec3.h"

class Light_Directional : public Light {
private:
	Vec3 m_direction;

public:
	Light_Directional(double intensity, Vec3 direction) : Light{ Types::Directional, intensity }, m_direction{ direction } {};
	
	Vec3 getDirection() const& { return m_direction; };

	double calculateIntensity(Vec3& normal, Vec3& point) const override {
		auto NdotL = dot(normal, m_direction);
		if (NdotL > 0.0) {
			return getIntensity() * NdotL / (normal.length() * m_direction.length());
		} else { return 0.0; };
	};
};

#endif LIGHT_DIRECTIONAL_H
