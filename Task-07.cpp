#include <iostream>
using namespace std;

class employee
{
private:
    int id;
    string name;
    float salary;
    int grade;

public:
    employee(int id, string name, float salary, int grade);
    void empDisplay();
    float getsalary();
    ~employee();
};

employee::employee(int id, string name, float salary, int grade)
{
    this->name = name;
    this->id = id;
    this->salary=salary;
    this->grade = grade;
}
void employee ::empDisplay()
{
    cout << "  -> ID: " << id << "\n";
    cout << "  -> Name: " << name << "\n";
    cout << "  -> Grade: " << grade << "\n";
    cout << "  -> Salary: " << salary << "\n";
}
float employee::getsalary()
{
    return salary;
}
employee::~employee()
{
}

class professors : public employee
{
private:
    /* data */
    int total_classes; // classes in ine day
    int class_time;    // time of each class
    int extra_lecture; // extra_lecture if any
    string subject;

public:
    professors(int id, string name, float salary, int grade, int total_classes, int class_time, int extra_lecture, string subject);
    void proDisplay();
    ~professors();
};

professors::professors(int id, string name, float salary, int grade, int total_classes, int class_time, int extra_lecture, string subject) : employee(id, name, salary, grade)
{
    this->total_classes = total_classes;
    this->class_time = class_time;
    this->extra_lecture = extra_lecture;
    this->subject = subject;
}
void professors::proDisplay()
{
    cout << "  -> Subject: " << subject << "\n";
    cout << "  -> Total Class in Day: " << total_classes << "\n";
    cout << "  -> Time of Each Class: " << class_time << "\n";
    cout << "  -> Total Net Salary: " << (getsalary() + (extra_lecture * 2000)) << "\n"; // if their is any extra lecture 2000 increase per lecture
}
professors::~professors()
{
}

class staff : public employee
{
private:
    /* data */
    int num_of_cordinaters;
    int gurds;
    int swipers;

public:
    staff(int id, string name, float salary, int grade, int total_classes, int class_time, int extra_lecture, int num_of_cordinaters, int gurds, int swipers);
    void staffDisplay();
    ~staff();
};

staff::staff(int id, string name, float salary, int grade, int total_classes, int class_time, int extra_lecture, int num_of_cordinaters, int gurds, int swipers) : employee(id, name, salary, grade)
{
    this->num_of_cordinaters = num_of_cordinaters;
    this->gurds = gurds;
    this->swipers = swipers;
}
void staff::staffDisplay()
{
    cout << "  -> Total # of Cordinater: " << num_of_cordinaters << "\n";
    cout << "  -> Total # of Gurds: " << gurds << "\n";
    cout << "  -> Total # of Swipers: " << swipers << "\n";
}
staff::~staff()
{
}

class admin : public employee
{
private:
    /* data */
    int employment_years;
    string department;

public:
    admin(int id, string name, float salary, int grade, int employment_years, string department);
    void adminDisplay();
    ~admin();
};

admin::admin(int id, string name, float salary, int grade, int employment_years, string department) : employee(id, name, salary, grade)
{
    this->employment_years = employment_years;
    this->department = department;
}
void admin::adminDisplay()
{
    cout << "  -> Employeed Since: " << employment_years << "\n";
    cout << "  -> Department: " << department << "\n";
}
admin::~admin()
{
}

int main()
{
    cout << "=========== PROFESSORS DETAILS ===========\n";
    professors p1(123, "Eman Mutaza", 56000, 1, 4, 60, 2, "Mathematics");
    p1.empDisplay();
    p1.proDisplay();
    cout << endl;

    cout << "============= STAFF DETAILS =============\n";
    staff s1(456, "Ahmed", 33000, 2, 5, 40, 2, 3, 2, 4);
    s1.empDisplay();
    s1.staffDisplay();
    cout << endl;

    cout << "============= ADMIN DETAILS =============\n";
    admin a1(789, "Arman Tahir", 49000, 3, 10, "Human Resources");
    a1.empDisplay();
    a1.adminDisplay();
    cout << endl;

    return 0;
}
