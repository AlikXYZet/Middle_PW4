#include <iostream>
#include <string>

class Parent
{
public:
	Parent() {}

	virtual void print() const { std::cout << "Parent"; }

	friend std::ostream& operator<<(std::ostream& out, const Parent& p)
	{
		out << "Parent";
		return out;
	}
};

class Child : public Parent
{
public:
	Child() {}

	virtual void print() const override { std::cout << "Child"; }

	friend std::ostream& operator<<(std::ostream& out, const Child& p)
	{
		out << "Child";
		return out;
	}
};


int main()
{
	Child ch;
	Parent& p = ch;

	std::cout << "p is a " << p << '\n';
	std::cout << "ch is a " << ch << '\n';

	return 0;
}