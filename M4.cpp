#include <iostream>

// Класс "Транспорт"
class Vehicle
{
public:
	// Чистая виртуальная функция print() с параметром типа std::ostream
	virtual std::ostream& print(std::ostream& out) = 0;

	// Перегрузка operator<<
	friend std::ostream& operator<<(std::ostream& out, const Vehicle& p)
	{
		out << "Vehicle";
		return out;
	}
};

int main()
{
	//Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
	//std::cout << c << '\n';

	//Bicycle t(Wheel(20), Wheel(20), 300);
	//std::cout << t << '\n';

	return 0;
}