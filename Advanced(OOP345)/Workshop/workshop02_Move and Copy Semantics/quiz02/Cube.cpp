// Polymorphic Ojbects - Cloning
// Cube.cpp
#include "Cube.h"

Cube::Cube(double l) : len(l) {};

Shape* Cube::clone() const {
	return new Cube(*this);
}

double Cube::volume() const {
	return len*len*len;
}
