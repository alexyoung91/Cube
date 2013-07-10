#include <iostream>

#include "Cube.hpp"

using std::cout;
using std::endl;

// passing by value invokes the copy constructor, if a pointer to the
// object or an object reference were passed, the copy constuctor would
// not be called!
void displayCubeVolume(const Cube& cube) {
	cout << "Volume: " << cube.getVolume() << endl;
}

int main() {
	// 11.34g cm-3 density of lead
	Cube leadCube(0.01, 0.01, 0.01, 11340);
	cout << "Density: " << leadCube.getMass() << "kg" << endl;
	Cube secondLeadCube = leadCube;
	secondLeadCube.setLength(0.05);
	displayCubeVolume(secondLeadCube);
	cout << "Density: " << secondLeadCube.getMass() << "kg" << endl;
	cout << &leadCube << endl;
	cout << &secondLeadCube << endl;
	
	cout << Cube::getObjectCount() << endl;
	
	// Pointers to classes
	Cube* box = new Cube();
	delete box;
	
	Cube* box2;
	box2 = &leadCube;
	cout << "Density: " << box2->getMass() << "kg" << endl;
	box2->setBreadth(0.89);
	cout << "Density: " << leadCube.getMass() << "kg" << endl;
	//delete box2; // this is invalid perhaps becuase its trying
	// to delete an object that wasn't dynamically allocated
	// you can't delete pointers that havent been delcared using the
	// new keyword??
	
	Cube* box3 = new Cube(leadCube);
	cout << "Density: " << box3->getMass() << "kg" << endl;
	cout << Cube::getObjectCount() << endl;
	delete box3;
	
	cout << Cube::getObjectCount() << endl;
	
	// density 2.16 g/cm^3
	Cube graphite(0.0762, 0.0762, 0.0762, 2160);
	
	// density 3.515 g/cm^3
	Cube diamond(0.0254, 0.0254, 0.0254, 3515);
	
	Cube composite = graphite + diamond;
	cout << composite.getHeight() << ", "
		 << composite.getDensity() << endl;
	
	graphite += diamond;
	cout << graphite.getHeight() << ", "
		 << graphite.getDensity() << endl;
	
	return 0;
}

/* Note about inline functions:
 * 
 * Any change to an inline function could require all clients of the
 * function to be recompiled because compiler would need to replace all
 * the code once again otherwise it will continue with old
 * functionality.
 * 
 * A compiler doesn't have to make a function inline e.g if the function
 * body is more than one line.
 * 
 * A function definition in a class definition is an inline function
 * definition, even without the use of the inline specifier.
 */
