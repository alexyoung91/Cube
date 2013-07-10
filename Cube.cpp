#include "Cube.hpp"

#include <iostream>

// Default constructor
Cube::Cube() {
	width = height = depth = density = 0.0;
	objectCount++;
}

/* Copy constructor - if not defined compiler makes one, only really
 * used if the class has pointer variables and some dynamic
 * memory allocations (e.g. in the normal constructor but used here to
 * demonstrate that it can be explicitiy declared
 */
Cube::Cube(const Cube& cube) {
	width = cube.width;
	height = cube.height;
	depth = cube.depth;
	density = cube.density;
	objectCount++;
}

// Parameterized constructor
Cube::Cube(double l, double b, double h, double d) {
	width = l;
	height = b;
	depth = h;
	density = d;
	objectCount++;
}

/* Using initialization lists to initalize fields
Cube::Cube(double l, double b, double h, double d):
	width(l), height(b), depth(h), density(d) {
		objectCount++;
}
*/

Cube::~Cube() {
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

bool Cube::operator<(Cube& opCube) const {
	return (this->getVolume() < opCube.getVolume()) ? true : false;
}

bool Cube::operator>(Cube& opCube) const {
	return (this->getVolume() > opCube.getVolume()) ? true : false;
}

bool Cube::operator<=(Cube& opCube) const {
	return (this->getVolume() <= opCube.getVolume()) ? true : false;
}

bool Cube::operator>=(Cube& opCube) const {
	return (this->getVolume() >= opCube.getVolume()) ? true : false;
}

bool Cube::operator==(Cube& opCube) const {
	return (this->getVolume() == opCube.getVolume()) ? true : false;
}

bool Cube::operator!=(Cube& opCube) const {
	return (this->getVolume() != opCube.getVolume()) ? true : false;
}

/* All static data is initialized to zero when the first object is
 * created if no other initialization present.
 */
int Cube::objectCount; // = 0;

std::ostream& operator <<(std::ostream& os, Cube& cube) {
	return os << "Width: " 		<< cube.getWidth() 		<< std::endl
			  << "Height: " 	<< cube.getHeight() 	<< std::endl
			  << "Depth: " 		<< cube.getDepth() 		<< std::endl
			  << "Volume: " 	<< cube.getVolume() 	<< std::endl
			  << "Density: "	<< cube.getDensity() 	<< std::endl
			  << "Mass: " 		<< cube.getMass() 		<< std::endl;
}
