#ifndef CUBE_HPP_
#define CUBE_HPP_

/**
 * Created for an increased understanding of object oriented programming
 * using C++
 */

class Cube {
	
	private:
		double	length;
		double	breadth;
		double	height;
		double	density; // mass per unit volume
		
		// could be useful for dynamic allocation tests i.e. if theres
		// any objects that havent been deleted
		static int objectCount;
	
	/**
	 * A protected member is very similar to a private member but it
	 * can be accessed in derived (child) classes. A protected member
	 * cannot be accessed publicly.
	 * 
	 * This is covered in "Inheritance"
	 */
	protected:
		bool	egVariable;
		
	public:
				Cube();
				Cube(const Cube& cube); // copy constructor
				//Cube(const Cube& cube) = delete; // non copyable
				Cube(double l, double b, double h, double d);
				~Cube();
				
		void	setLength(double l);
		void	setBreadth(double b);
		void	setHeight(double h);
		void	setDensity(double d);
		
		double	getLength() const;
		double	getBreadth() const;
		double	getHeight() const;
		double	getDensity() const;
		
		double	getVolume() const;
		double	getMass() const;
		
		Cube	operator+(Cube& opCube) const;
		Cube	operator-(Cube& opCube) const;
		Cube&	operator+=(Cube& opCube);
		Cube&	operator-=(Cube& opCube);
		
		bool	operator==(Cube& opCube) const;
		bool	operator!=(Cube& opCube) const;
		
		// left to overload: <, >, <=. >=, = (copy constr?), !=, ==, <<, >>
		
		// static members cannot have a const qualifier
		static int getObjectCount() {
			return objectCount;
		}
};

#endif
