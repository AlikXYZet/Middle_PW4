#include <iostream>
#include <vector>
#include <functional>

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

void printName(const Parent& parent)
{
	std::cout << "I am a " << parent.getName() << '\n';
}

int main()
{
	std::vector<std::reference_wrapper<Parent>> v;
	Parent p(9);
	Child ch(10);
	v.push_back(p);
	v.push_back(ch);

	for (int count = 0; count < v.size(); ++count)
	{
		std::cout << "I am a " << v[count].get().getName() << " with value " << v[count].get().getValue() << '\n';
	}

	return 0;
}