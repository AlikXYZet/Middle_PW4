#include <iostream>

void boo(double*& p)
{

}

struct Test1
{

};

class Test2
{

};

int main()
{
	int b = 10;
	int a = 100;
	std::cout << &b << "\n";
	std::cout << b << "\n";
	std::cout << *&b << "\n";

	int* Ptr = &b;
	Ptr = &a;
	std::cout << Ptr << "\n";
	std::cout << *Ptr << "\n";

	double testD = 0.00000001;
	double* PtrD = &testD;
	boo(PtrD);
	std::cout << PtrD << "\n";
	std::cout << *PtrD << "\n";

	int* TestI_1;
	Test2* TestI_2;
	char* TestC_1;

	std::cout << sizeof(TestI_1) << "\n";
	std::cout << sizeof(TestI_2) << "\n";
	std::cout << sizeof(TestC_1) << "\n";
}