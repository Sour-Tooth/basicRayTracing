#include <iostream>
#include <limits>

#include "config.h"
#include "scene.h"
#include "vec3.h"
#include "ray.h"

#include "sphere.h"
#include "hitRec.h"
#include "shaders.h"

inline void writePixel(const color_t& color);
inline point3_t canvasToViewport(int x, int y);
color_t traceRay(Ray r, Scene& scene);

double computeLighting(Vec3 normal, point3_t point, Scene& scene);

int main() {
	// setup file
	std::cout << "P3\n" << Config::canvasWidth << ' ' << Config::canvasHeight << '\n' << Config::maxColorValue << '\n';

	Sphere redSphere{ 0.4, {0, 0, 2}, {150, 50, 50} }; // radius, center, color
	Sphere greenSphere{ 0.2, {0.2, 0.2, 1.4}, {50, 150, 50} };

	Sphere sphere1{ 1, {0, -1, 3 }, {255, 0, 0} };
	Sphere sphere2{ 1, {2, 0, 4 }, {0, 0, 255} };
	Sphere sphere3{ 1, {-2, 0, 4 }, {0, 255, 0} };
	Sphere sphere4{ 5000, {0, -5001, 0}, {255, 255, 0} };

	Scene scene{};
	scene.addSphere(sphere1);
	scene.addSphere(sphere2);
	scene.addSphere(sphere3);
	scene.addSphere(sphere4);

	scene.addLight(std::make_shared<Light_Ambient>(0.2));
	scene.addLight(std::make_shared<Light_Point>(0.6, point3_t{ 2, 1, 0 }));
	scene.addLight(std::make_shared<Light_Directional>(0.2, Vec3{ 1, 4, 4 }));

	auto& cw = Config::canvasWidth;
	auto& ch = Config::canvasHeight;

	// TODO: PLACE CHECK TO MAKE SURE ENOUGH PIXELS ARE RENDERED
	// if ch or cw are negetive, int precicious errors will cause this to break
	// for each point on canvas, scanline and convert to coordinate system and render 
	for (int y{ ch/2 }; y > -ch/2; --y) {
		for (int x{ -cw/2 }; x < cw/2; ++x) {
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
		x * (Config::viewportWidth / Config::canvasWidth),
		y * (Config::viewportHeight / Config::canvasHeight),
		Config::focalLength
	};
};

color_t traceRay(Ray r, Scene& scene) {
	HitRec closestRec{
		.doesHit = false, 
		.intersectionDistance = std::numeric_limits<double>::max() 
	};

	const auto& spheres{ scene.getSpheres() };

	for (const auto& sphere : spheres) {
		const HitRec tempRec{ sphere.hit(r) };

		// go through all intersections with sphere and pick closest in bounds
		if (tempRec.doesHit) {
			auto& t{tempRec.intersectionDistance};

			if (t > Config::clipStart && t < Config::clipEnd && t < closestRec.intersectionDistance) { // t is already a ray sent out from the camera, therefor it can be compared to clip distances directly
				closestRec = tempRec; // add sphere to tempRec
				closestRec.sphere = &sphere;
			};
		};
	};

	if (closestRec.sphere != nullptr) {
		//return { shaders::colorByNormal(closestRec) };
		
		return { computeLighting(closestRec.normal, r.at(closestRec.intersectionDistance), scene) * 
			closestRec.sphere->getColor() 
		};
	} else {
		return { 255, 255, 255 }; // background
	};

	// for sphere in scene
	// if ray and sphere intersect
		// if intersection is in clipping bounds
		// t1 || t2 is closer then closestT && 
			// closestT = t1 || t2
			// closestSphere = sphere
};

double computeLighting(Vec3 normal, point3_t point, Scene& scene) {
	double i{ 0.0 };

	const auto lights{ scene.getLights() };
	for ( auto& light : scene.getLights()) {
		i += light->calculateIntensity(normal, point);
	};

	return i;
};
