#include <iostream>

class Parent
{
public:
	virtual const char* getName() { return "Parent"; }
};

class Child : public Parent
{
public:
	virtual const char* getName() { return "Child"; }
};


int main()
{
	Child child;
	Parent& parent = child;
	std::cout << parent.Parent::getName() << std::endl;

	return 0;
}