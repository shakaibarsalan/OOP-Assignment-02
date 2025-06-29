#include <iostream>

using namespace std;

class Employee
{
private:
    int id;
    string name;
    int working_hours;
    float hourly_wage;

public:
    Employee(int id, string name, int working_hours, float hourly_wage);
    void employee_display();
    string getname();
    int getWorkingHours();
    float getHourlyWage();
    ~Employee();
};
Employee::Employee(int id, string name, int working_hours, float hourly_wage)
{
    this->id = id;
    this->name = name;
    this->working_hours = working_hours;
    this->hourly_wage = hourly_wage;
}
void Employee::employee_display()
{
    cout << "ID: " << id << "\n";
    cout << "Name: " << name << "\n";
}
string Employee ::getname()
{
    return name;
}
int Employee::getWorkingHours()
{
    return working_hours;
}
float Employee::getHourlyWage()
{
    return hourly_wage;
}
Employee::~Employee() {}

class Chef : protected Employee
{
private:
    string dish1;
    string dish2;
    int employment_since;

public:
    Chef(int id, string name, int working_hours, float hourly_wage, int employment_since, string d1, string d2);
    void chef_display();
    void chef_duties();
    ~Chef();
};
Chef::Chef(int id, string name, int working_hours, float hourly_wage, int employment_since, string dish1, string dish2) : Employee(id, name, working_hours, hourly_wage)
{
    this->employment_since = employment_since;
    this->dish1 = dish1;
    this->dish2 = dish2;
}
void Chef::chef_duties()
{
    cout << "Duties of Chef:\n";
    cout << "  1. Menu Planning\n  2. Food Preparation\n  3. Kitchen Management\n  4. Cooking\n  5. Quality Control\n";
}
void Chef::chef_display()
{
    cout << "<><><><><><><> Chef <><><><><><><>\n";
    employee_display();
    cout << "Special Dishes: " << dish1 << ", " << dish2 << "\n";
    cout << "Working Hours: " << getWorkingHours() << "\n";
    cout << "Hourly Wage: " << getHourlyWage() << "\n";
    cout << "Total Salary: " << getWorkingHours() * getHourlyWage() << "\n";
    cout << "Employment Since: " << employment_since << "\n";
    chef_duties();
}
Chef::~Chef() {}

class Waiter : protected Employee
{
private:
    int table;
    int employment_since;

public:
    Waiter(int id, string name, int working_hours, float hourly_wage, int employment_since, int table);
    void waiter_display();
    void waiter_duties();
    ~Waiter();
};
Waiter::Waiter(int id, string name, int working_hours, float hourly_wage, int employment_since, int table) : Employee(id, name, working_hours, hourly_wage)
{
    this->table = table;
    this->employment_since = employment_since;
}
void Waiter::waiter_duties()
{
    cout << "Duties of Waiter:\n";
    cout << "  1. Taking orders\n  2. Serving food and beverages\n  3. Assisting customers\n";
}
void Waiter::waiter_display()
{
    cout << "<><><><><><><> Waiter <><><><><><><>\n";
    employee_display();
    cout << "Table Served by " << getname() << ": " << table << "\n";
    cout << "Working Hours: " << getWorkingHours() << "\n";
    cout << "Hourly Wage: " << getHourlyWage() << "\n";
    cout << "Total Salary: " << getWorkingHours() * getHourlyWage() << "\n";
    cout << "Employment Since: " << employment_since << "\n";
    waiter_duties();
}
Waiter::~Waiter() {}

class Manager : protected Employee
{
private:
    int emp;
    string depart;
    int employment_since;

public:
    Manager(int id, string name, int working_hours, float hourly_wage, int employment_since, int emp, string depart);
    void manager_display();
    void manager_duties();
    ~Manager();
};
Manager::Manager(int id, string name, int working_hours, float hourly_wage, int employment_since, int emp, string depart) : Employee(id, name, working_hours, hourly_wage)
{
    this->emp = emp;
    this->depart = depart;
    this->employment_since = employment_since;
}
void Manager::manager_duties()
{
    cout << "Duties of Manager:\n";
    cout << "  1. Staff supervision and training\n  2. Budget management\n  3. Customer service\n";
}
void Manager::manager_display()
{
    cout << "<><><><><><><> Manager <><><><><><><>\n";
    employee_display();
    cout << "Department: " << depart << "\n";
    cout << "Employee's Under " << getname() << ": " << emp << "\n";
    cout << "Working Hours: " << getWorkingHours() << "\n";
    cout << "Hourly Wage: " << getHourlyWage() << "\n";
    cout << "Total Salary: " << getWorkingHours() * getHourlyWage() << "\n";
    cout << "Employment Since: " << employment_since << "\n";
    manager_duties();
}
Manager::~Manager() {}

int main()
{
    Chef c1(123, "Eman", 5, 1500, 2002, "Stack", "Pizza");
    c1.chef_display();
    cout << endl;

    Waiter w1(456, "Umair", 6, 2000, 2001, 7);
    w1.waiter_display();
    cout << endl;

    Manager m1(789, "Arman", 4, 3000, 2008, 12, "Back of House");
    m1.manager_display();
    cout << endl;

    return 0;
}
