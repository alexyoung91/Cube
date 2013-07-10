#ifndef CUBE_HPP_
#define CUBE_HPP_

#include <iostream>

/**
 * Created for an increased understanding of object oriented programming
 * using C++
 */

class Cube {
	
	private:
		double	width;
		double	height;
		double	depth;
		double	density;
		
		/* Could be useful for dynamic allocation tests i.e. if theres
		 * any objects that havent been deleted
		 */
		static int objectCount;
		
	public:
				Cube();
				Cube(const Cube& cube); // copy constructor
				Cube(double l, double b, double h, double d);
				~Cube();
				
		void	setWidth(double l);
		void	setHeight(double b);
		void	setDepth(double h);
		void	setDensity(double d);
		
		double	getWidth() const;
		double	getHeight() const;
		double	getDepth() const;
		double	getDensity() const;
		
		double	getVolume() const;
		double	getMass() const;
		
		// Modifying the cube
		Cube	operator +(Cube& opCube) const;
		Cube	operator -(Cube& opCube) const;
		Cube&	operator +=(Cube& opCube);
		Cube&	operator -=(Cube& opCube);
		
		// Volume comparison
		bool	operator <(Cube& opCube) const;
		bool	operator >(Cube& opCube) const;
		bool	operator <=(Cube& opCube) const;
		bool	operator >=(Cube& opCube) const;
		bool	operator ==(Cube& opCube) const;
		bool	operator !=(Cube& opCube) const;
		
		// static members cannot have a const qualifier
		static int getObjectCount() {
			return objectCount;
		}
		
		// Output cube properties
		friend std::ostream& operator <<(std::ostream& os, Cube& cube);
};

#endif
