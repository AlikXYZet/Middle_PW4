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
	RoadVehicle(float clearance)
	{
		Clearance = clearance;
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Ride height: " << Clearance;
		return out;
	}
};

// Класс "Колесо"
class Wheel
{
private:
	float Diameter;

public:
	Wheel(float diameter)
	{
		Diameter = diameter;
	}

	friend std::ostream& operator<<(std::ostream& out, const Wheel& w)
	{
		out << w.Diameter << " ";
		return out;
	}
};

// Класс "Двигатель"
class Engine
{
private:
	float Power;

public:
	Engine()
	{
		Power = 0;
	}

	Engine(float inPower)
	{
		Power = inPower;
	}

	friend std::ostream& operator<<(std::ostream& out, const Engine& e)
	{
		out << e.Power << " ";
		return out;
	}
};

// Класс "Велосипед"
class Bicycle : public RoadVehicle
{
private:
	Wheel* wheels;

public:
	Bicycle(Wheel wheel_1, Wheel wheel_2, float inClearance)
		: RoadVehicle(inClearance)
	{
		wheels = new Wheel[2]{ wheel_1, wheel_2 };
	}

	std::ostream& print(std::ostream& out) const
	{
		out << "Bicycle ";
		out << "Wheels: ";
		for (size_t i = 0; i < 2; i++)
		{
			out << wheels[i];
		}

		RoadVehicle::print(out);

		return out;
	};

};

// Класс "Машина"
class Car : public RoadVehicle
{
private:
	Wheel* wheels;
	Engine engine;
public:
	Car(Engine inEngine, Wheel wheel_1, Wheel wheel_2, Wheel wheel_3, Wheel wheel_4, float inClearance)
		: RoadVehicle(inClearance)
	{
		engine = inEngine;
		wheels = new Wheel[4]{ wheel_1, wheel_2, wheel_3, wheel_4 };
	}

	std::ostream& print(std::ostream& out) const
	{
		out << "Bicycle ";
		out << "Engine: " << engine;
		out << "Wheels: ";
		for (size_t i = 0; i < 4; i++)
		{
			out << wheels[i];
		}

		RoadVehicle::print(out);

		return out;
	};
};

int main()
{
	Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
	std::cout << c << '\n';

	Bicycle t(Wheel(20), Wheel(20), 300);
	std::cout << t << '\n';

	return 0;
}