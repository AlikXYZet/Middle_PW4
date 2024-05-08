#include <iostream>

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

};

// ����� "���������"
class Bicycle : public RoadVehicle
{
private:
	//Wheel wheel;
};

// ����� "������"
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