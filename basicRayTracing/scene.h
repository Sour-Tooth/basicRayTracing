#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "sphere.h"
#include "light.h"
#include "light_ambient.h"
#include "light_directional.h"
#include "light_point.h"

class Scene {
public:
	using sphereList_t = std::vector<Sphere>;
	using lightList_t = std::vector<std::shared_ptr<Light>>;

private:
	sphereList_t m_spheres{};
	lightList_t m_lights{};

public:
	// add constructor

	sphereList_t& getSpheres() { return m_spheres; };

	void addSphere(Sphere newSphere) { m_spheres.push_back(newSphere); };
	
	lightList_t& getLights() { return m_lights; };
	void addLight(std::shared_ptr<Light> newLight) { m_lights.push_back(newLight); };
};

#endif // !SCENE_H
