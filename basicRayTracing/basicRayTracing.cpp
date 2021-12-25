#include <iostream>
#include <limits>

#include "config.h"
#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "hitRec.h"
#include "scene.h"

inline void writePixel(const color_t& color);
inline point3_t canvasToViewport(int x, int y);
color_t traceRay(Ray r, Scene scene);

int main() {
	// setup file
	std::cout << "P3\n" << Config::canvasWidth << ' ' << Config::canvasHeight << '\n' << Config::maxColorValue << '\n';

	Sphere redSphere{ 0.4, {0, 0, 2}, {150, 50, 50} }; // radius, center, color
	Sphere greenSphere{ 0.2, {0.2, 0.2, 1.4}, {50, 150, 50} };

	Sphere sphere1{ 1, {0, -1, 3 }, {255, 0, 0}};
	Sphere sphere2{ 1, {0, 2, 4 }, {0, 0, 225} };
	Sphere sphere3{ 1, {0, -2, 4 }, {0, 225, 0} };

	Scene scene{};
	scene.addSphere(sphere1);
	scene.addSphere(sphere2);
	scene.addSphere(sphere3);

	// scanlines. 
	auto& cw = Config::canvasWidth;
	auto& ch = Config::canvasHeight;

	for (int x{}; x < cw; ++x) {
		for (int y{}; y < ch; ++y) {
			Ray r{ Config::cameraOrigin, canvasToViewport(x, y) };
			color_t color{ traceRay(r, scene) };
			writePixel(color);
		};
	};

	return 0;
};

inline void writePixel(const color_t& color) {
	std::cout << color.getX() << ' ' << color.getY() << ' ' << color.getZ() << '\n';
};

// relative to bottomLeftCorner of viewport
point3_t inline canvasToViewport(int x, int y) {
	return Vec3 {
		x * (Config::viewportWidth / Config::canvasWidth) - (Config::viewportWidth / 2),
		y * (Config::viewportHeight / Config::canvasHeight) - (Config::viewportHeight / 2),
		Config::focalLength
	};
};

color_t traceRay(Ray r, Scene scene) {
	double closestT{ std::numeric_limits<double>::max() };
	const Sphere* closestSphere{ nullptr };

	const auto& spheres{ scene.getSpheres() };

	for (const auto& sphere : spheres) {
		const HitRec rec{ sphere.hit(r) };

		// go through all intersections with sphere and pick closest in bounds
		if (rec.doesHit) {
			for (auto& t : rec.intersections) {
				if (t > Config::clipStart && t < Config::clipEnd && t < closestT) { // t is already a ray sent out from the camera, therefor it can be compared to clip distances directly
					closestT = t;
					closestSphere = &sphere;
				};
			};
		};
	};

	if (closestSphere != nullptr) {
		return { closestSphere->getColor() };
	} else {
		return { 255, 255, 255 }; // white background
	};

	// for sphere in scene
	// if ray and sphere intersect
		// if intersection is in clipping bounds
		// t1 || t2 is closer then closestT && 
			// closestT = t1 || t2
			// closestSphere = sphere
};
