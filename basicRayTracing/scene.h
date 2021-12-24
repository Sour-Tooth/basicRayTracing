#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "sphere.h"

class Scene {
public:
	using sphereList_t = std::vector<Sphere>;

private:
	//Sphere m_sphere;
	sphereList_t m_spheres{};

public:
	// add constructor

	//Sphere const getSphere() { return m_sphere; };
	//Sphere setSphere(Sphere sphere) { m_sphere = sphere; };

	sphereList_t getSpheres() const { return m_spheres; };
	void addSphere(Sphere newSphere) { m_spheres.push_back(newSphere); };

};

#endif // !SCENE_H
