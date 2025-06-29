#include <iostream>
using namespace std;

class sports
{
private:
    int maxSpeed;
    int sec; // 1-100 taken time

public:
    sports(int maxSpeed, int sec) : maxSpeed(maxSpeed), sec(sec) {}
    void spoDisplay();
    ~sports();
};

void sports::spoDisplay()
{
    cout << "  * Sports Car Max Speed: " << maxSpeed << " km/h" << endl;
    cout << "  * Sports Car 0-100 km/h Time: " << sec << " seconds" << endl;
}

sports::~sports() {}

class electric
{
private:
    int capacity; // Battery capacity
    int km;       // kilo meters cover

public:
    electric(int capacity, int km) : capacity(capacity), km(km) {}
    void eleDisplay();
    ~electric();
};

void electric::eleDisplay()
{
    cout << "  * Electric Car Battery Capacity: " << capacity << " kWh" << endl;
    cout << "  * Electric Car Range: " << km << " km" << endl;
}

electric::~electric() {}

class hybrid
{
private:
    int power; // power in herdz
    string fuelType;
    int octanNO; // fuel octan number
    int tankCapacity;
    int cylinder; // numvber of cylinders

public:
    hybrid(int power, string fuelType, int octanNO, int tankCapacity, int cylinder)
        : power(power), fuelType(fuelType), octanNO(octanNO), tankCapacity(tankCapacity), cylinder(cylinder) {}
    void hybDisplay();
    ~hybrid();
};

void hybrid::hybDisplay()
{
    cout << "  * Hybrid Car Power: " << power << " herdz" << endl;
    cout << "  * Hybrid Car Fuel Type: " << fuelType << endl;
    cout << "  * Hybrid Car Octane Number: " << octanNO << endl;
    cout << "  * Hybrid Car Tank Capacity: " << tankCapacity << " liters" << endl;
    cout << "  * Hybrid Car Number of Cylinders: " << cylinder << endl;
}

hybrid::~hybrid() {}

class car : protected sports, protected electric, protected hybrid
{
private:
    int price;
    string offRoading;
    int year;
    string make;
    string model;
    string colour;

public:
    car(int price, string offRoading, int year, string make, string model, string colour,
        int sportsMaxSpeed, int sportsSec, int electricCapacity, int electricKm,
        int hybridPower, string hybridFuelType, int hybridOctanNO, int hybridTankCapacity, int hybridCylinder)
        : sports(sportsMaxSpeed, sportsSec), electric(electricCapacity, electricKm),
          hybrid(hybridPower, hybridFuelType, hybridOctanNO, hybridTankCapacity, hybridCylinder),
          price(price), offRoading(offRoading), year(year), make(make), model(model), colour(colour) {}

    void carDisplay();
    ~car();
};

void car::carDisplay()
{
    cout << "  * Make: " << make << endl;
    cout << "  * Colour: " << colour << endl;
    cout << "  * Model: " << model << endl;
    cout << "  * Year: " << year << endl;
    cout << "  * Price: $" << price << endl;
    cout << "  * Off-Roading: " << offRoading << endl;
    spoDisplay();
    eleDisplay();
    hybDisplay();
}

car::~car() {}

int main()
{
    car car01(50000, "No", 2023, "Toyota", "Camry", "Blue", 280, 5, 75, 400, 150, "Electric", 91, 60, 4);
    cout << "<><><><><><><>< CAR 01 DETAILS ><><><><><><><>\n";
    car01.carDisplay();
    cout << endl;

    car car02(60000, "Yes", 2022, "Ford", "Mustang", "Red", 320, 4, 80, 350, 180, "Gasoline", 95, 70, 6);
    cout << "<><><><><><><>< CAR 02 DETAILS ><><><><><><><>\n";
    car02.carDisplay();
    cout << endl;

    car car03(40000, "Yes", 2021, "Tesla", "Model S", "Black", 300, 6, 100, 500, 120, "Electric", 89, 55, 4);
    cout << "<><><><><><><>< CAR 03 DETAILS ><><><><><><><>\n";
    car03.carDisplay();
    cout << endl;

    return 0;
}
