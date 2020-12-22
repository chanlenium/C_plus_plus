// Polymorphic Ojbects - Cloning
// Sphere.cpp
#include "Sphere.h"

Sphere::Sphere(double r) : rad(r) {};

Shape* Sphere::clone() const {
	return new Sphere(*this);
}

double Sphere::volume() const {
	return 4.18879 * rad * rad * rad;
}
