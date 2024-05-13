#include <iostream>
#include <vector>

// ����� "���������" [������������ �����]
class Vehicle
{
private:
	// ���������� "���� ������������� ��������"
	std::string TypeVehicle = "Vehicle ";

public:

	virtual ~Vehicle()
	{
		std::cout << " ~Vehicle()\n";
	}
	
	// ������ ����������� ������� print() � ���������� ���� std::ostream
	virtual std::ostream& print(std::ostream& out) const = 0;

	// ���������� operator<<
	friend std::ostream& operator<<(std::ostream& out, const Vehicle& p)
	{
		out << p.TypeVehicle && p.print(out);
		return out;
	}

	// ������ "���� ������������� ��������"
	void SetType(std::string inType)
	{
		TypeVehicle = inType;
	}
};

// ����� "������" [�������������� �����]
class Wheel
{
private:
	float Diameter;

public:
	Wheel(float inDiameter)
	{
		Diameter = inDiameter;
	}

	// ���������� operator<< ��� ������ "�������� ������"
	friend std::ostream& operator<<(std::ostream& out, const Wheel& w)
	{
		out << w.Diameter << " ";
		return out;
	}
};

// ����� "���������" [�������������� �����]
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

	// ���������� operator<< ��� ������ "�������� ���������"
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

// ����� "������ ���������"
class WaterVehicle : public Vehicle
{
private:
	// ����������-���� "������" (������ ������� ����������)
	float Draft;

public:
	WaterVehicle(float inDraft)
	{
		SetType("WaterVehicle ");
		Draft = inDraft;
	}

	~WaterVehicle()
	{
		std::cout << " ~WaterVehicle() ";
	}

	// ���������� print() ��� ������ "������ ������� ����������"
	std::ostream& print(std::ostream& out) const override
	{
		out << "Draft: " << Draft;
		return out;
	}
};

// ����� "�������� ���������"
class RoadVehicle : public Vehicle
{
private:
	// ����������-���� "�������� �������" (�� �� �������)
	float Clearance;

protected:
	std::vector<Wheel> wheels;

public:
	RoadVehicle(float inClearance)
	{
		SetType("RoadVehicle ");
		Clearance = inClearance;
	}

	~RoadVehicle()
	{
		// ���������� ������� ������� ���������� ������ ��� ����������� ���������� ������,
		// ������� �������� ��� ��� ������
		//wheels.~vector();
		std::cout << " ~RoadVehicle() ";
	}

	// ���������� print() ��� ������ "������� �������� ����������"
	std::ostream& print(std::ostream& out) const override
	{
		// ����� ������ ������� �� "�����@
		out << "Wheels: ";
		for (size_t i = 0; i < wheels.size(); i++)
		{
			out << wheels[i];
		}

		// ����� ������ "��������� ��������"
		out << "Ride height: " << Clearance;
		return out;
	}
};

// ����� "���������"
class Bicycle : public RoadVehicle
{
private:

public:
	Bicycle(Wheel wheel_1, Wheel wheel_2, float inClearance)
		: RoadVehicle(inClearance)
	{
		SetType("Bicycle ");
		wheels.push_back(wheel_1);
		wheels.push_back(wheel_2);
	}

	~Bicycle()
	{
		std::cout << " ~Bicycle() ";
	}

	// ���������� print() ��� "����������"
	std::ostream& print(std::ostream& out) const
	{
		// ����� ������ "��������� ��������"
		RoadVehicle::print(out);

		return out;
	};
};

// ����� "������"
class Car : public RoadVehicle
{
private:
	Engine engine;

public:
	Car(Engine inEngine, Wheel wheel_1, Wheel wheel_2, Wheel wheel_3, Wheel wheel_4, float inClearance)
		: RoadVehicle(inClearance)
	{
		SetType("Car ");
		engine = inEngine;
		wheels.push_back(wheel_1);
		wheels.push_back(wheel_2);
		wheels.push_back(wheel_3);
		wheels.push_back(wheel_4);
	}

	~Car()
	{
		std::cout << " ~Car() ";
	}

	// ���������� print() ��� "������"
	std::ostream& print(std::ostream& out) const
	{
		// ����� ������ "�������� ���������"
		out << "Engine: " << engine;

		// ����� ������ "��������� ��������"
		RoadVehicle::print(out);

		return out;
	};

	float GetPower()
	{
		return engine.GetPower();
	}
};

// ����� "�����" (����������) [�������������� �����]
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

	// ���������� operator<< ��� ������ "����� ���������"
	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "(" << p.x << ", " << p.y << ", " << p.z << ") ";
		return out;
	}
};

// ����� "����"
class Circle : public Vehicle, Point
{
private:
	float Diameter;

public:
	Circle(Point inPoint, float inDiameter)
		: Point(inPoint)
	{
		SetType("Circle ");
		Diameter = inDiameter;
	}

	~Circle()
	{
		std::cout << " ~Circle() ";
	}

	// ���������� print() ��� "�����"
	std::ostream& print(std::ostream& out) const
	{
		// ����� ������
		out << "Point: " << static_cast<Point>(*this);
		out << "Diameter: " << Diameter;

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

	// TODO: ����� ��������� ������� v �����
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << *v[i];
		std::cout << "\n";
	}

	// ����������� ������� ��������� ������������� �������� �������� �� ������� "v"
	std::cout << "\nThe highest power is " << getHighestPower(v) << '\n'; // ���������� ��� �������

	// TODO: �������� ��������� ������� v �����
	std::cout << "\nThe Destructors Test:\n";
	for (size_t i = 0; i < v.size(); i++)
	{
		delete v[i];
	}

	// �������� ������� (����� �����������)
	v.~vector();

	std::cout << "\n";

	return 0;
}