#include <iostream>
#include <vector>

// Класс "Транспорт"
class Vehicle
{
private:
	// Переменная "Типа транспортного средства"
	std::string TypeVehicle = "Vehicle ";

public:
	// Чистая виртуальная функция print() с параметром типа std::ostream
	virtual std::ostream& print(std::ostream& out) const = 0;

	// Перегрузка operator<<
	friend std::ostream& operator<<(std::ostream& out, const Vehicle& p)
	{
		out << p.TypeVehicle && p.print(out);
		return out;
	}

	void SetType(std::string inType)
	{
		TypeVehicle = inType;
	}
};

// Класс "Водный транспорт"
class WaterVehicle : public Vehicle
{
private:
	// Переменная-член "Осадка" (осадка водного транспорта)
	float Draft;

public:
	WaterVehicle(float inDraft)
	{
		SetType("WaterVehicle ");
		Draft = inDraft;
	}

	// Перегрузка print() для вывода "Осадка водного транспорта"
	std::ostream& print(std::ostream& out) const override
	{
		out << "Draft: " << Draft;
		return out;
	}
};

// Класс "Дорожный транспорт"
class RoadVehicle : public Vehicle
{
private:
	// Переменная-член "Дорожный просвет" (он же клиренс)
	float Clearance;

public:
	RoadVehicle(float inClearance)
	{
		SetType("RoadVehicle ");
		Clearance = inClearance;
	}

	// Перегрузка print() для вывода "Дорожно просвета транспорта"
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
	Wheel()
	{
		Diameter = 0;
	}

	Wheel(float inDiameter)
	{
		Diameter = inDiameter;
	}

	// Перегрузка operator<< для вывода "Диаметра Колеса"
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

	// Перегрузка operator<< для вывода "Мощности Двигателя"
	friend std::ostream& operator<<(std::ostream& out, const Engine& e)
	{
		out << e.Power << " ";
		return out;
	}

	float GetPower()
	{
		return Power;
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
		SetType("Bicycle ");
		wheels = new Wheel[2]{ wheel_1, wheel_2 };
	}

	~Bicycle()
	{
		if (wheels)
		{
			delete[2] wheels;
		}
	}

	// Перегрузка print() для "Велосипеда"
	std::ostream& print(std::ostream& out) const
	{
		// Вывод данных каждого из 2-х "Колес"
		out << "Wheels: ";
		for (size_t i = 0; i < 2; i++)
		{
			out << wheels[i];
		}

		// Вывод данных "Дорожного просвета"
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
		SetType("Car ");
		engine = inEngine;
		wheels = new Wheel[4]{ wheel_1, wheel_2, wheel_3, wheel_4 };
	}

	~Car()
	{
		if (wheels)
		{
			delete[4] wheels;
		}
	}

	// Перегрузка print() для "Машины"
	std::ostream& print(std::ostream& out) const
	{
		// Вывод данных "Мощности двигателя"
		out << "Engine: " << engine;

		// Вывод данных каждого из 4-х "Колес"
		out << "Wheels: ";
		for (size_t i = 0; i < 4; i++)
		{
			out << wheels[i];
		}

		// Вывод данных "Дорожного просвета"
		RoadVehicle::print(out);

		return out;
	};

	float GetPower()
	{
		return engine.GetPower();
	}
};

// Класс "Точка" (Координаты)
class Point
{
private:
	float x;
	float y;
	float z;

public:
	Point(float inX, float inY, float inZ)
	{
		x = inX;
		y = inY;
		z = inZ;
	}

	// Перегрузка operator<< для вывода "Точки координат"
	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "(" << p.x << ", " << p.y << ", " << p.z << ") ";
		return out;
	}
};

// Класс "Круг"
class Circle : public Vehicle, Point
{
private:
	Wheel wheel;

public:
	Circle(Point inPoint, float inDiameter)
		: Point(inPoint)
	{
		SetType("Circle ");
		wheel = Wheel(inDiameter);
	}

	// Перегрузка print() для "Круга"
	std::ostream& print(std::ostream& out) const
	{
		// Вывод данных
		out << "Point: " << static_cast<Point>(*this);
		out << "Wheel: " << wheel;

		return out;
	};
};

float getHighestPower(std::vector<Vehicle*> inVector)
{
	float HighestPower = 0;
	for (size_t i = 0; i < inVector.size(); i++)
	{
		if (dynamic_cast<Car*>(inVector[i]) && HighestPower < dynamic_cast<Car*>(inVector[i])->GetPower())
		{
			HighestPower = dynamic_cast<Car*>(inVector[i])->GetPower();
		}
	}

	return HighestPower;
}


int main()
{
	Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
	std::cout << c << '\n';

	Bicycle t(Wheel(20), Wheel(20), 300);
	std::cout << t << '\n';

	std::cout << "\n\n";

	std::vector<Vehicle*> v;

	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));

	v.push_back(new Circle(Point(1, 2, 3), 7));

	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));

	v.push_back(new WaterVehicle(5000));

	// TODO: Вывод элементов вектора v здесь
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << *v[i];
		std::cout << "\n";
	}

	// Реализовать функцию получения максимального значения мощности из массива "v"
	std::cout << "\nThe highest power is " << getHighestPower(v) << '\n'; // реализуйте эту функцию

	// TODO: Удаление элементов вектора v здесь
	v.clear();

	return 0;
}