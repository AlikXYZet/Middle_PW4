#include <iostream>

class Animal
{
protected:
	std::string m_name;
	Animal(std::string name) : m_name(name)
	{
	}

public:
	std::string getName() { return m_name; }
	const char* speak() { return "???"; }
};

class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name)
	{
	}

	const char* speak() { return "Meow"; }
};

class Dog : public Animal
{
public:
	Dog(std::string name) : Animal(name)
	{
	}

	const char* speak() { return "Woof"; }
};

int main()
{

	return 0;
}