#include <iostream>

// Класс "Транспорт"
class Vehicle
{
public:
	// Чистая виртуальная функция print() с параметром типа std::ostream
	virtual std::ostream& print(std::ostream& out) const = 0;

	// Перегрузка operator<<
	friend std::ostream& operator<<(std::ostream& out, const Vehicle& p)
	{
		return p.print(out);
	}
};

// Класс "Водный транспорт"
class WaterVehicle : public Vehicle
{
private:
	// Переменная-член "Осадка" (осадка водного транспорта)
	float Draft;

public:

};

// Класс "Дорожный транспорт"
class RoadVehicle : public Vehicle
{
private:
	// Переменная-член "Дорожный просвет" (он же клиренс)
	float Clearance;

public:

};

// Кдасс "Велосипед"
class Bicycle : public RoadVehicle
{
private:
	//Wheel wheel;
};

// Кдасс "Машина"
class Car : public RoadVehicle
{
private:
	//Wheel wheel;
	//Engine engine;
};


int main()
{
	//Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
	//std::cout << c << '\n';

	//Bicycle t(Wheel(20), Wheel(20), 300);
	//std::cout << t << '\n';

	return 0;
}