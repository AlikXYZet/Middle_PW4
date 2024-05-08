#include <iostream>
#include <vector>

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
	std::vector<Parent> v;
	v.push_back(Parent(9));
	v.push_back(Child(10));

	for (int count = 0; count < v.size(); ++count)
	{
		std::cout << "I am a " << v[count].getName() << " with value " << v[count].getValue() << '\n';
	}

	return 0;
}