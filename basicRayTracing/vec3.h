#ifndef VEC3_H
#define VEC3_H

#include <iostream>

// TODO: make this a template class
class Vec3 {
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Vec3() = default;
	Vec3(double x, double y, double z) : m_x{ x }, m_y{ y }, m_z{ z } {};

	double getX() const { return m_x; };
	double getY() const { return m_y; };
	double getZ() const { return m_z; };

	void setX(double s) { m_x = s; };
	void setY(double s) { m_y = s; };
	void setZ(double s) { m_z = s; };

	// utilty
	double length() { return sqrt(lengthSquared()); };
	double lengthSquared() { return m_x * m_x + m_y * m_y + m_z * m_z; };

	friend Vec3 operator- (Vec3&);
	friend Vec3 operator+= (Vec3& v, double s);
	friend Vec3 operator-= (Vec3& v, double s);
	friend Vec3 operator*= (Vec3& v, double s);
	friend Vec3 operator/= (Vec3& v, double s);
};

// aliases
using color_t = Vec3; // TODO: have this be a Vec3<int> template
using point3_t = Vec3;

inline std::ostream& operator<< (std::ostream& out, const Vec3& v);
inline Vec3 operator+ (const Vec3& v, const Vec3& u);
inline Vec3 operator- (const Vec3& v, const Vec3& u);
inline Vec3 operator* (const Vec3& v, const Vec3& u);

inline Vec3 operator+ (const Vec3& v, const double s);
inline Vec3 operator+ (const double s, const Vec3& v);
inline Vec3 operator- (const Vec3& v, const double s);
inline Vec3 operator* (const Vec3& v, const Vec3& u);
inline Vec3 operator* (const double s, const Vec3& v);
inline Vec3 operator/ (const Vec3& v, const double s);

inline double dot(const Vec3& v, const Vec3& u);

// TODO: have these return a this* pointer so I can chain the operations
inline std::ostream& operator<< (std::ostream& out, const Vec3& v) {
	return out << v.getX() << ' ' << v.getY() << ' ' << v.getZ();
};

inline Vec3 operator+ (const Vec3& v, const Vec3& u) {
	return Vec3{
		v.getX() + u.getX(),
		v.getY() + u.getY(),
		v.getZ() + u.getZ()
	};
};

inline Vec3 operator- (const Vec3& v, const Vec3& u) {
	return Vec3{
		v.getX() - u.getX(),
		v.getY() - u.getY(),
		v.getZ() - u.getZ()
	};
};

inline Vec3 operator* (const Vec3& v, const Vec3& u) {
	return Vec3{
		v.getX() * u.getX(),
		v.getY() * u.getY(),
		v.getZ() * u.getZ()
	};
};

inline Vec3 operator+ (const Vec3& v, const double s) {
	return Vec3{
		v.getX() + s,
		v.getY() + s,
		v.getZ() + s
	};
};

inline Vec3 operator+ (const double s, const Vec3& v) { return v + s; };

inline Vec3 operator- (const Vec3& v, const double s) {
	return Vec3{
		v.getX() - s,
		v.getY() - s,
		v.getZ() - s
	};
};

inline Vec3 operator* (const Vec3& v, const double s) {
	return Vec3{
		v.getX() * s,
		v.getY() * s,
		v.getZ() * s
	};
};

inline Vec3 operator* (const double s, const Vec3& v) { return v * s; };
inline Vec3 operator/ (const Vec3& v, const double s) { return v * (1 / s); };

/* utility */
inline double dot(const Vec3& v, const Vec3& u) {
	return(
		v.getX() * u.getX() +
		v.getY() * u.getY() +
		v.getZ() * u.getZ()
	);
};

inline Vec3 unitVector(Vec3 v) {
	return v / v.length();
};

#endif
