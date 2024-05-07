#include <iostream>

class Parent
{
protected:
	int m_value;

public:
	Parent(int value) : m_value(value)
	{
	}

	virtual const char* getName() const { return "Parent"; }
	int getValue() { return m_value; }
};

class Child : public Parent
{
public:
	Child(int value) : Parent(value)
	{
	}

	const char* getName() const override { return "Child"; }
};


int main()
{
	Child child(5);
	std::cout << "child Name: " << child.getName() << ";   Has value : " << child.getValue() << '\n';

	Parent parent = child;
	std::cout << "parent Name: " << parent.getName() << ";   Has value : " << parent.getValue() << '\n';

	Child& ref = child;
	std::cout << "ref Name: " << ref.getName() << ";   Has value : " << ref.getValue() << '\n';

	Child* ptr = &child;
	std::cout << "ptr Name: " << ptr->getName() << ";   Has value : " << ptr->getValue() << '\n';

	return 0;
}