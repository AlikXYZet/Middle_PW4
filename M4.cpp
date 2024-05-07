#include <iostream>

class Parent
{
public:
	virtual ~Parent()
	{
		std::cout << "Calling ~Parent()" << std::endl;
	}
};

class Child : public Parent
{
private:
	int* m_array;

public:
	Child(int length)
	{
		m_array = new int[length];
	}

	~Child()
	{
		std::cout << "Calling ~Child()" << std::endl;
		delete[] m_array;
	}
};


int main()
{
	Child* child = new Child(9);
	Parent* parent = child;
	delete parent;

	return 0;
}