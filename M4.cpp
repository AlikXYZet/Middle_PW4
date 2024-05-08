#include <iostream>
#include <vector>

// ����� "���������"
class Vehicle
{
public:
	// ������ ����������� ������� print() � ���������� ���� std::ostream
	virtual std::ostream& print(std::ostream& out) const = 0;

	// ���������� operator<<
	friend std::ostream& operator<<(std::ostream& out, const Vehicle& p)
	{
		return p.print(out);
	}
};

// ����� "������ ���������"
class WaterVehicle : public Vehicle
{
private:
	// ����������-���� "������" (������ ������� ����������)
	float Draft;

public:

};

// ����� "�������� ���������"
class RoadVehicle : public Vehicle
{
private:
	// ����������-���� "�������� �������" (�� �� �������)
	float Clearance;

public:
	RoadVehicle(float clearance)
	{
		Clearance = clearance;
	}

	// ���������� print() ��� ������ "������� �������� ����������"
	std::ostream& print(std::ostream& out) const override
	{
		out << "Ride height: " << Clearance;
		return out;
	}
};

// ����� "������"
class Wheel
{
private:
	float Diameter;

public:
	Wheel(float diameter)
	{
		Diameter = diameter;
	}

	// ���������� operator<< ��� ������ "�������� ������"
	friend std::ostream& operator<<(std::ostream& out, const Wheel& w)
	{
		out << w.Diameter << " ";
		return out;
	}
};

// ����� "���������"
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
};

// ����� "���������"
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

	// ���������� print() ��� "����������"
	std::ostream& print(std::ostream& out) const
	{
		out << "Bicycle ";

		// ����� ������ ������� �� 2-� "�����"
		out << "Wheels: ";
		for (size_t i = 0; i < 2; i++)
		{
			out << wheels[i];
		}

		// ����� ������ "��������� ��������"
		RoadVehicle::print(out);

		return out;
	};

};

// ����� "������"
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
		out << "Car ";

		// ����� ������ "�������� ���������"
		out << "Engine: " << engine;

		// ����� ������ ������� �� 4-� "�����"
		out << "Wheels: ";
		for (size_t i = 0; i < 4; i++)
		{
			out << wheels[i];
		}

		// ����� ������ "��������� ��������"
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

	std::cout << "\n\n";

	std::vector<Vehicle*> v;

	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));

	//v.push_back(new Circle(Point(1, 2, 3), 7));

	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));

	//v.push_back(new WaterVehicle(5000));


	// TODO: ����� ��������� ������� v �����

	//std::cout << "The highest power is" << getHighestPower(v) << '\n'; // ���������� ��� �������

	// TODO: �������� ��������� ������� v �����

	return 0;
}