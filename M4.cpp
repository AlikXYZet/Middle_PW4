#include <iostream>
#include <string>

class Parent
{
protected:
	int m_value;

public:
	Parent(int value) : m_value(value)
	{
	}

	virtual ~Parent() {}
};

class Child : public Parent
{
protected:
	std::string m_name;

public:
	Child(int value, std::string name) : Parent(value), m_name(name)
	{
	}

	const std::string& getName() { return m_name; }
};

Parent* getObject(bool bReturnChild)
{
	if (bReturnChild)
		return new Child(1, "Banana");
	else
		return new Parent(2);
}

int main()
{
	Child banana(1, "apple");
	Parent& par = banana;
	Child& ref = dynamic_cast<Child&>(par);

	std::cout << "The name of the Child is: " << ref.getName() << '\n';

	return 0;
}