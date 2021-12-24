#include <iostream>

#include "vec3.h"

// operator overloading
Vec3 operator-(Vec3& v) {
	return Vec3{
		-v.m_x,
		-v.m_y,
		-v.m_z
	};
};

Vec3 operator+=(Vec3& v, double s) {
	return Vec3{
		v.m_x += s,
		v.m_y += s,
		v.m_z += s
	};
};

Vec3 operator-=(Vec3& v, double s) {
	return Vec3{
		v.m_x -= s,
		v.m_y -= s,
		v.m_z -= s
	};
};

Vec3 operator*=(Vec3& v, double s) {
	return Vec3{
		v.m_x *= s,
		v.m_y *= s,
		v.m_z *= s
	};
};

Vec3 operator/=(Vec3& v, double s) {
	return v *= (1 / s);
};
