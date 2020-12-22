#ifndef SHAPE_H
#define SHAPE_H
// Polymorphic Ojbects - Cloning
// Shape.h
class Shape {
public:
	virtual double volume() const = 0;
	virtual Shape* clone() const = 0;
};

#endif