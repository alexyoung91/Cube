#include "Cube.hpp"

#include <iostream>

using std::cout;
using std::endl;

Cube::Cube() {
	cout << "Creating cube with default constructor." << endl;
	length = breadth = height = density = 0.0;
	objectCount++;
}

// Copy constructor - if not defined compiler makes one, only really
// used if the class has pointer variables and some dynamic
// memory allocations (e.g. in the normal constructor but used here to
// demonstrate that it can be explicitiy declared
Cube::Cube(const Cube& cube) {
	cout << "Creating cube with copy constructor." << endl;
	length = cube.length;
	breadth = cube.breadth;
	height = cube.height;
	density = cube.density;
	objectCount++;
}

Cube::Cube(double l, double b, double h, double d) {
	cout << "Creating cube with parameterized constructor." << endl;
	length = l;
	breadth = b;
	height = h;
	density = d;
	objectCount++;
}

/* Using initialization lists to initalize fields
Cube::Cube(double l, double b, double h, double d):
	length(l), breadth(b), height(h), density(d) {
		cout << "Creating cube." << endl;
		objectCount++;
}
*/

Cube::~Cube() {
	cout << "Releasing cube." << endl;
	objectCount--;
}

void Cube::setLength(double l) {
    length = l;
}

void Cube::setBreadth(double b) {
    breadth = b;
}

void Cube::setHeight(double h) {
    height = h;
}

void Cube::setDensity(double d) {
    density = d;
}

double Cube::getLength() const {
	return length;
}

double Cube::getBreadth() const {
	return breadth;
}

double Cube::getHeight() const {
	return height;
}

double Cube::getDensity() const {
	return density;
}

double Cube::getVolume() const {
	return length * breadth * height;
}

double Cube::getMass() const {
	return density * getVolume();
}

Cube Cube::operator+(Cube& opCube) const {
	Cube newCube;
	newCube.setLength(this->length + opCube.length);
	newCube.setBreadth(this->breadth + opCube.breadth);
	newCube.setHeight(this->height + opCube.height);
	newCube.setDensity((this->getMass() + opCube.getMass()) /
					   (this->getVolume() + opCube.getVolume()));
	return newCube;
}

Cube Cube::operator-(Cube& opCube) const {
	Cube newCube;
	newCube.setLength(this->length - opCube.length);
	newCube.setBreadth(this->breadth - opCube.breadth);
	newCube.setHeight(this->height - opCube.height);
	newCube.setDensity((this->getMass() - opCube.getMass()) /
					   (this->getVolume() - opCube.getVolume()));
	return newCube;
}

Cube& Cube::operator+=(Cube& opCube) {
	double oldMass = this->getMass(), oldVol = this->getVolume();
	this->setLength(this->length + opCube.length);
	this->setBreadth(this->breadth + opCube.breadth);
	this->setHeight(this->height + opCube.height);
	this->setDensity((oldMass + opCube.getMass()) /
					 (oldVol + opCube.getVolume()));
	return *this;
}

Cube& Cube::operator-=(Cube& opCube) {
	double oldMass = this->getMass(), oldVol = this->getVolume();
	this->setLength(this->length - opCube.length);
	this->setBreadth(this->breadth - opCube.breadth);
	this->setHeight(this->height - opCube.height);
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
