#ifndef LIGHT_AMBIENT_H
#define LIGHT_AMBIENT_H

#include "light.h"
#include "vec3.h"

class Light_Ambient : public Light {
public:
	Light_Ambient(double intensity) : Light{ Types::Ambient, intensity } {};

	double calculateIntensity(Vec3& normal, Vec3& point) const override {
		return getIntensity();
	};
};

#endif LIGHT_AMBIENT_H
