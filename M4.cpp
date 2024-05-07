#include <iostream>

void foo(int& ref)
{
	ref = 10;
}

void foo2(int* S)
{
	*S = 11;
}

struct Something
{
	int value1 = 5;
	float value2 = 6.2;
};

struct Other
{
	Something something;
	int otherValue;
};

Other other;

int main()
{
	int Seven = 7;
	int& Ref = Seven;

	std::cout << Ref << '\n';

	Ref++;
	Seven++;

	std::cout << Seven << '\n';
	std::cout << Ref << '\n';

	const int SeventySeven = 77;
	const int& Ref2 = SeventySeven;

	int value1 = 8;
	int value2 = 20;

	std::cout << value1 << '\n';
	std::cout << value2 << '\n';

	foo(value1);
	foo2(&value2);

	std::cout << value1 << '\n';
	std::cout << value2 << '\n';

	int& ref1 = value1;
	ref1 = value2;

	std::cout << '\n';

	int& refSomething = other.something.value1;
	std::cout << other.something.value1 << '\n';
	std::cout << refSomething << '\n';
}