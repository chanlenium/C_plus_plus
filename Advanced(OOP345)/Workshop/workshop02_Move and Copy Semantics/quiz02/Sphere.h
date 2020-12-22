// Polymorphic Ojbects - Cloning
// Sphere.h
#include "Shape.h"

class Sphere : public Shape
{
	double rad;
public:
	Sphere(double);
	double volume() const;
	Shape* clone() const;
};

