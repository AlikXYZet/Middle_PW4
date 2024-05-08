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

void printName(const Parent parent)
{
	std::cout << "I am a " << parent.getName() << '\n';
}

int main()
{
	Child child(5);
	std::cout << "child Name: " << child.getName() << ";   Has value : " << child.getValue() << '\n';

	printName(child);

	Parent& ref = child;
	std::cout << "ref Name: " << ref.getName() << ";   Has value : " << ref.getValue() << '\n';

	Parent* ptr = &child;
	std::cout << "ptr Name: " << ptr->getName() << ";   Has value : " << ptr->getValue() << '\n';

	return 0;
}