#include <iostream>

int add(int a, int b)
{
	return a + b;
}

int subrtact(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int main()
{
	int a;
	std::cout << "Enter a number: ";
	std::cin >> a;

	int b;
	std::cout << "Enter another number: ";
	std::cin >> b;

	int op;
	do
	{
		std::cout << "Enter an operation (0 = add, 1 = subrtact, 2 = multiply): ";
		std::cin >> op;
	} while (0 > op || op > 2);

	int result = 0;
	switch (op)
	{
	case 0: result = add(a, b); break;
	case 1: result = subrtact(a, b); break;
	case 2: result = multiply(a, b); break;
	}

	std::cout << "The answer is: " << result << std::endl;

	return 0;
}