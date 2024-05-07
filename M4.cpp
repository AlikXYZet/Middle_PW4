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
	Parent* p = getObject(false);
	Child* chD = dynamic_cast<Child*>(p);
	Child* chS = static_cast<Child*>(p);

	if (chD)
	{
		std::cout << "The name of the Child is: " << chD->getName() << '\n';
	}

	if (chS)
	{
		std::cout << "The name of the Child is: " << chS->getName() << '\n';
	}
	
	delete p;

	return 0;
}