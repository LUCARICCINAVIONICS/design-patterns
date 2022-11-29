#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape
{
public:
	virtual string getName() = 0;
};

class Triangle : public Shape
{
public:
	string getName() { return "Triangle"; }
};

class Square : public Shape
{
public:
	string getName() { return "Square"; }
};

class Circle : public Shape
{
public:
	string getName() { return "Circle"; }
};

enum Type{ TRIANGLE, SQUARE, CIRCLE};


// responsible for creating and returning Shape objects on demand...
class Factory
{
public:
	Shape* create(Type t)  // factory method
	{
		switch(t)
		{
			case TRIANGLE:
				return new Triangle();
			case SQUARE:
				return new Square();
			case CIRCLE:
				return new Circle();
		}
	}
};



int main()
{
	vector <Shape*> shapes;

	// Our factory is responsible for creating Shape objects on demand
	Factory f;
	
	// Lets create 3 different shape objects and assign their memory addresses to our shapes vector
	shapes.push_back(f.create(TRIANGLE));
	shapes.push_back(f.create(SQUARE));
	shapes.push_back(f.create(CIRCLE));

	// Iterate over each shape object, calling it's getName method using it's pointer
	for (Shape*& s : shapes)
		cout << s->getName() << endl;

	// cleaneup
	for (Shape*& s : shapes)
		delete s;

	shapes.clear();
	return 0;
}

