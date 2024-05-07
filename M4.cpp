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
	int getValue() { return m_value * 2; }
};


int main()
{

}