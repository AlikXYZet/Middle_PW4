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

void report(Animal& rAnimal)
{
	std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
}

int main()
{
	Cat Filya("Filya"), Kuzya("Kuzya");
	Dog Tramp("Tramp"), Baikal("Baikal");

	Animal* animals[] = { &Filya, &Kuzya, &Tramp, &Baikal };
	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << animals[i]->getName() << " says : " << animals[i]->speak() << '\n';
	}

	return 0;
}