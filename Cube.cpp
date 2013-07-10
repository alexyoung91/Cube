#include "Cube.hpp"

#include <iostream>

using std::cout;
using std::endl;

Cube::Cube() {
	cout << "Creating cube with default constructor." << endl;
	width = height = depth = density = 0.0;
	objectCount++;
}

// Copy constructor - if not defined compiler makes one, only really
// used if the class has pointer variables and some dynamic
// memory allocations (e.g. in the normal constructor but used here to
// demonstrate that it can be explicitiy declared
Cube::Cube(const Cube& cube) {
	cout << "Creating cube with copy constructor." << endl;
	width = cube.width;
	height = cube.height;
	depth = cube.depth;
	density = cube.density;
	objectCount++;
}

Cube::Cube(double l, double b, double h, double d) {
	cout << "Creating cube with parameterized constructor." << endl;
	width = l;
	height = b;
	depth = h;
	density = d;
	objectCount++;
}

/* Using initialization lists to initalize fields
Cube::Cube(double l, double b, double h, double d):
	width(l), height(b), depth(h), density(d) {
		cout << "Creating cube." << endl;
		objectCount++;
}
*/

Cube::~Cube() {
	cout << "Releasing cube." << endl;
	objectCount--;
}

void Cube::setWidth(double l) {
    width = l;
}

void Cube::setHeight(double b) {
    height = b;
}

void Cube::setDepth(double h) {
    depth = h;
}

void Cube::setDensity(double d) {
    density = d;
}

double Cube::getWidth() const {
	return width;
}

double Cube::getHeight() const {
	return height;
}

double Cube::getDepth() const {
	return depth;
}

double Cube::getDensity() const {
	return density;
}

double Cube::getVolume() const {
	return width * height * depth;
}

double Cube::getMass() const {
	return density * getVolume();
}

Cube Cube::operator+(Cube& opCube) const {
	Cube newCube;
	newCube.setWidth(this->width + opCube.width);
	newCube.setHeight(this->height + opCube.height);
	newCube.setDepth(this->depth + opCube.depth);
	newCube.setDensity((this->getMass() + opCube.getMass()) /
					   (this->getVolume() + opCube.getVolume()));
	return newCube;
}

Cube Cube::operator-(Cube& opCube) const {
	Cube newCube;
	newCube.setWidth(this->width - opCube.width);
	newCube.setHeight(this->height - opCube.height);
	newCube.setDepth(this->depth - opCube.depth);
	newCube.setDensity((this->getMass() - opCube.getMass()) /
					   (this->getVolume() - opCube.getVolume()));
	return newCube;
}

Cube& Cube::operator+=(Cube& opCube) {
	double oldMass = this->getMass(), oldVol = this->getVolume();
	this->setWidth(this->width + opCube.width);
	this->setHeight(this->height + opCube.height);
	this->setDepth(this->depth + opCube.depth);
	this->setDensity((oldMass + opCube.getMass()) /
					 (oldVol + opCube.getVolume()));
	return *this;
}

Cube& Cube::operator-=(Cube& opCube) {
	double oldMass = this->getMass(), oldVol = this->getVolume();
	this->setWidth(this->width - opCube.width);
	this->setHeight(this->height - opCube.height);
	this->setDepth(this->depth - opCube.depth);
	this->setDensity((oldMass - opCube.getMass()) /
					 (oldVol - opCube.getVolume()));
	return *this;
}

bool Cube::operator==(Cube& opCube) const {
	return (this->getVolume() == opCube.getVolume()) ? true : false;
}

bool Cube::operator!=(Cube& opCube) const {
	return (this->getVolume() != opCube.getVolume()) ? true : false;
}

// all static data in initialized to zero when the first object is
// created. With no other initialization present it is 0.
int Cube::objectCount; // = 0;
