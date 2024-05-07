#include <iostream>

class Parent
{
protected:
	int m_value;

public:
	Parent(int value) : m_value(value)
	{
	}

	const char* getName() { return "Parent"; }
	int getValue() { return m_value; }
};

class Child : public Parent
{
public:
	Child(int value) : Parent(value)
	{
	}

	const char* getName() { return "Child"; }
	int getValueDoubled() { return m_value * 2; }
};


int main()
{
	Child child(5);
	std::cout << "child Name: " << child.getName() << ";   Has value : " << child.getValue() << '\n';

	Child& rChild = child;
	std::cout << "rChild Name: " << rChild.getName() << ";   Has value : " << rChild.getValue() << '\n';

	Child* pChild = &child;
	std::cout << "pChild Name: " << pChild->getName() << ";   Has value : " << pChild->getValue() << '\n';
	
	std::cout << '\n';

	Parent& rParent = child;
	Parent* pParent = &child;

	std::cout << "child Name: " << child.getName() << ";   Has value : " << child.getValue() << '\n';
	std::cout << "rParent Name: " << rParent.getName() << ";   Has value : " << rParent.getValue() << '\n';
	std::cout << "pParent Name: " << pParent->getName() << ";   Has value : " << pParent->getValue() << '\n';

	return 0;
}