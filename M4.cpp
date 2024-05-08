#include <iostream>
#include <string>

class Parent
{
public:
	Parent() {}

	virtual void print() const { std::cout << "Parent"; }
};

class Child : public Parent
{
public:
	Child() {}

	virtual void print() const override { std::cout << "Child"; }
};


int main()
{
	Child ch;
	Parent& p = ch;

	std::cout << "p is a ";
	p.print();
	std::cout << '\n';

	std::cout << "ch is a ";
	ch.print();
	std::cout << '\n';

	return 0;
}