#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <limits>

#include "vec3.h"

namespace Config {
	inline constexpr double aspectRatio{ 16.0 / 16.0 };

	inline constexpr int canvasWidth{ 400 };
	inline constexpr int canvasHeight{ static_cast<int>(canvasWidth / aspectRatio) };
	inline constexpr double viewportHeight{ 1 };
	inline constexpr double viewportWidth{ 1 }; // viewportHeight * aspectRatio
	inline const point3_t cameraOrigin{ 0, 0, 0 };
	inline constexpr double focalLength{ 1 };

	// clipping is the min/max distance down a ray from 6the camera 
	// where things are visible
	inline constexpr double clipStart{ focalLength };
	inline constexpr double clipEnd{ std::numeric_limits<int>::max() };

	inline constexpr int maxColorValue{ 255 };
};

#endif // !CONFIGURATION_H
