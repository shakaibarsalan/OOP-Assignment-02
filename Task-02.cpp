#include <iostream>

using namespace std;

class vehicle
{
private:
    int year;
    string make;
    string model;
    string color;

public:
    vehicle(int year, string make, string model, string color);
    void display();
    ~vehicle();
};

vehicle::vehicle(int year, string make, string model, string color)
{
    this->year = year;
    this->make = make;
    this->model = model;
    this->color;
}
void vehicle::display()
{
    cout << "   Make: " << make << "\n";
    cout << "   Model: " << model << "\n";
    cout << "   Lounch Year: " << year << "\n";
}
vehicle::~vehicle()
{
}

class car : protected vehicle
{
private:
    int num_door;
    string variant;
    int top_speed;
    int tank;

public:
    car(int year, string make, string model, string color, int num_door, string variant, int top_speed, int tank);
    void c_display();
    ~car();
};

car::car(int year, string make, string model, string color, int num_door, string variant, int top_speed, int tank) : vehicle(year, make, model, color)
{
    this->num_door = num_door;
    this->variant = variant;
    this->top_speed = top_speed;
    this->tank = tank;
}
void car::c_display()
{
    cout << "============= Car =============\n";
    display();
    cout << "   Top Speed: " << top_speed << "\n";
    cout << "   Number of Doos: " << num_door << "\n";
    cout << "   Varient: " << variant << "\n";
    cout << "   Tank Capacity: " << tank << " gal." << "\n";
}
car::~car()
{
}

class motocycle : protected vehicle
{
private:
    string type;
    float fuel;
    float min;

public:
    motocycle(int year, string make, string model, string color, string type, float fuel, float min);
    void m_display();
    ~motocycle();
};

motocycle::motocycle(int year, string make, string model, string color, string type, float fuel, float min) : vehicle(year, make, model, color)
{
    this->type = type;
    this->fuel = fuel;
    this->min = min;
}
void motocycle::m_display()
{
    cout << "========== MotorCycle ==========\n";
    display();
    cout << "   Type: " << type << "\n";
    cout << "   1-100 Time: " << min << " sec" << "\n";
    cout << "   Fuel Capacity: " << fuel << " liters" << "\n";
}
motocycle::~motocycle()
{
}

class bicycle : protected vehicle
{
private:
    string manufacturer;

public:
    bicycle(int year, string make, string model, string color, string manufacturer);
    void b_display();
    ~bicycle();
};

bicycle::bicycle(int year, string make, string model, string color, string manufacturer) : vehicle(year, make, model, color)
{
    this->manufacturer = manufacturer;
}
void bicycle::b_display()
{
    cout << "=========== Bi-Cycle ===========\n";
    display();
    cout << "   Manufacturer: " << manufacturer << "\n";
}
bicycle::~bicycle()
{
}

int main()
{
    car c1(2012, "Toyta", "Supra", "Blue", 2, "Sports Car", 155, 13);
    c1.c_display();
    cout << endl;

    motocycle m1(2021, "YAMAHA", "R6", "Black", "Sport Bike", 17.06, 6.08);
    m1.m_display();
    cout << endl;

    bicycle b1(2019, "Morgan U.S.A", "MOR 05", "red", "Mountain Cycle");
    b1.b_display();
    cout << endl;
    return 0;
}