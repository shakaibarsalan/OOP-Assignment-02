#include <iostream>
using namespace std;

class employee
{
private:
    string name;
    int age;
    int id;
    string department;
    float salary;

public:
    employee(string name, int age, int id, string department, float salary);
    void work();
    void empDisplay();
    ~employee();
};

employee::employee(string name, int age, int id, string department, float salary)
{
    this->name = name;
    this->age = age;
    this->id = id;
    this->department = department;
    this->salary = salary;
}

void employee::work()
{
    cout << "  -> Employee's Working in Hospital:\n";
    cout << "  ->    1. Doctors\n   2. Nurses\n   3. Technicians\n";
}

void employee::empDisplay()
{
    cout << "  -> Name: " << name << "\n";
    cout << "  -> Age: " << age << " years\n";
    cout << "  -> Employee ID: " << id << "\n";
    cout << "  -> Salary: " << salary << "\n";
    cout << "  -> Department: " << department << "\n";
}

employee::~employee()
{
}

class doctor : virtual public employee
{
protected:
    int hours;    // Duty hours
    int patients; // Diagnosed patients per day
    string specialization;

public:
    doctor(string name, int age, int id, string department, float salary, int hours, int patients, string specialization);
    void diagnose();
    void docDisplay();
    ~doctor();
};

doctor::doctor(string name, int age, int id, string department, float salary, int hours, int patients, string specialization)
    : employee(name, age, id, department, salary)
{
    this->hours = hours;
    this->patients = patients;
    this->specialization = specialization;
}

void doctor::diagnose()
{
    cout << "  -> Doctor Diagnosing Patients.\n";
}

void doctor::docDisplay()
{
    cout << "  -> Duty Hours Per Day: " << hours << "\n";
    cout << "  -> Diagnosed Patients Per Day: " << patients << "\n";
    cout << "  -> Doctor's Specialization: " << specialization << "\n";
}

doctor::~doctor()
{
}

class nurse : virtual public employee
{
private:
    string qualification;
    string shift; // Day or Night Duty

public:
    nurse(string name, int age, int id, string department, float salary, string qualification, string shift);
    void assist();
    void nursDisplay();
    ~nurse();
};

nurse::nurse(string name, int age, int id, string department, float salary, string qualification, string shift)
    : employee(name, age, id, department, salary)
{
    this->qualification = qualification;
    this->shift = shift;
}

void nurse::assist()
{
    cout << "  -> Nurse Assisting Patients.\n";
}

void nurse::nursDisplay()
{
    cout << "  -> Qualification: " << qualification << "\n";
    cout << "  -> Duty Shift: " << shift << "\n";
}

nurse::~nurse()
{
}

class technician : virtual public employee
{
private:
    int experience; // working since
    int no_of_tec;
    float budget; // budget given to technician

public:
    technician(string name, int age, int id, string department, float salary, int experience, int no_of_tec, float budget);
    void tecDisplay();
    ~technician();
};

technician::technician(string name, int age, int id, string department, float salary, int experience, int no_of_tec, float budget)
    : employee(name, age, id, department, salary)
{
    this->experience = experience;
    this->no_of_tec = no_of_tec;
    this->budget = budget;
}

void technician::tecDisplay()
{
    cout << "  -> Working Experience: " << experience << " years\n";
    cout << "  -> No of Technicians in Hospital: " << no_of_tec << "\n";
    cout << "  -> Budget Given to Technician: " << budget << "\n";
}

technician::~technician()
{
}

class admin : public doctor, public nurse, public technician
{
private:
    int staff; // total staff members in admin

public:
    admin(string name, int age, int id, string department, float salary, int staff, int experience, int no_of_tec, float budget, string qualification, string shift);
    void role();
    void admDisplay();
    ~admin();
};

admin::admin(string name, int age, int id, string department, float salary, int staff, int experience, int no_of_tec, float budget, string qualification, string shift)
    : employee(name, age, id, department, salary),
    doctor(name, age, id, department, salary, 0, 0, ""),
    nurse(name, age, id, department, salary, "", ""),
    technician(name, age, id, department, salary, 0, 0, 0.0)
{
    this->staff = staff;
}

void admin::role()
{
    cout << "  -> Admins are able to manage all employees.\n";
}

void admin::admDisplay()
{
    cout << "  -> Admin Staff Members: " << staff << "\n";
}

admin::~admin()
{
}

int main()
{
    admin a1("Arman Tahir", 35, 1, "ICU", 5000, 10, 5, 3, 10000, "BSc Nursing", "Day Shift");
    cout << "******* DOCTOR DETAILS *******\n";
    a1.empDisplay();
    a1.docDisplay();
    a1.diagnose();
    cout << endl;

    admin a2("Umair Inayat", 40, 2, "Administration", 6000, 15, 7, 4, 12000, "MBA", "Night Shift");
    cout << "******* ADMIN DETAILS *******\n";
    a2.empDisplay();
    a2.admDisplay();
    a2.role();
    cout << endl;

    admin a3("Eman Murtaza", 25, 3, "Nursing", 3000, 2, 8, 2, 8000, "Diploma in Nursing", "Day Shift");
    cout << "******* NURSE DETAILS *******\n";
    a3.empDisplay();
    a3.nursDisplay();
    a3.assist();
    cout << endl;

    admin a4("Abdul Hadi", 30, 4, "Technician", 4000, 5, 10, 5, 15000, "Diploma in Electronics", "Night Shift");
    cout << "******* TECHNICIAN DETAILS *******\n";
    a4.empDisplay();
    a4.tecDisplay();
    a4.admDisplay();
    cout << endl;

    return 0;
}
