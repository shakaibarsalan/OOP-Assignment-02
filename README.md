# OOP Assignment 02

This repository contains solutions for various Object-Oriented Programming (OOP) tasks, demonstrating concepts like inheritance, polymorphism, encapsulation, and more in C++.

## Contents

- **Task 01:** Restaurant Employee Management (Inheritance)
- **Task 02:** Vehicle Hierarchy (Single Inheritance)
- **Task 03:** Zoo Species Hierarchy (Multi-level Inheritance)
- **Task 04:** Game Character Classes (Inheritance)
- **Task 05:** Multiple Inheritance Example (Car Features)
- **Task 06:** Virtual Inheritance (Hospital Employees)
- **Task 07:** University Staff Hierarchy
- **Task 08:** Animal Hierarchy (Lions, Tigers, Elephants)
- **Task 09:** Bank Account Management System
- **Task 10:** Airline Ticket Booking System

## How to Run

1. Clone the repository:
    ```
    git clone 
    ```
2. Open the desired `.cpp` file in your IDE or compile with:
    ```
    g++ -o program Task01.cpp
    ./program
    ```

## Major Functions

| Task    | Major Classes/Functions         | Description                                         |
|---------|-------------------------------|-----------------------------------------------------|
| Task 01 | Employee, Chef, Waiter, Manager | Models restaurant staff with inheritance            |
| Task 02 | vehicle, car, motocycle, bicycle | Demonstrates vehicle inheritance                    |
| Task 03 | specie, animals, reptile, dog, cat, snack, crocodile | Zoo animal hierarchy, multi-level inheritance       |
| Task 04 | character, warrior, mages, archer | Game character classes with special attributes      |
| Task 05 | sports, electric, hybrid, car    | Multiple inheritance for car features               |
| Task 06 | employee, doctor, nurse, technician, admin | Virtual inheritance in hospital staff              |
| Task 07 | employee, professors, staff, admin | University staff and salary calculations           |
| Task 08 | animal, lions, tigers, elephant  | Animal hierarchy and specific features              |
| Task 09 | Account, saving_account, checking_account, fixed_deposit_account | Bank account operations         |
| Task 10 | entity, flight, passengers, ticket | Airline ticket booking system                      |

## Sample Output

### Task 01 (Restaurant Employee Management)
```
<><><><><><><> Chef <><><><><><><>
ID: 123
Name: Eman
Special Dishes: Stack, Pizza
Working Hours: 5
Hourly Wage: 1500
Total Salary: 7500
Employment Since: 2002
Duties of Chef:
  1. Menu Planning
  2. Food Preparation
  3. Kitchen Management
  4. Cooking
  5. Quality Control
...
```

### Task 09 (Bank Account Management)
```
===== Welcome to the Banking System! =====

   Please choose an account type:
     1. Savings Account
     2. Checking Account
     3. Fixed Deposit Account
   Enter your choice (1-3): 1
   Enter Account Number: 12345
   Enter Initial Balance: 10000
   Enter Interest Rate: 5
   Account Number: 12345
   Balance: $10000
   Interest: 500
   Interest Rate: 5
...
```

## Author

- Muhammad Shakaib Arsalan (F2022266626)
- UMT Lahore, Pakistan

---

## 3. Extracted Output and Major Function Parts

### Example: Task 01 – Major Functions

```
class Employee {
    // id, name, working_hours, hourly_wage
    Employee(int id, string name, int working_hours, float hourly_wage);
    void employee_display();
    // ...
};

class Chef : protected Employee {
    // dish1, dish2, employment_since
    void chef_display();
    void chef_duties();
};

class Waiter : protected Employee {
    // table, employment_since
    void waiter_display();
    void waiter_duties();
};

class Manager : protected Employee {
    // emp, depart, employment_since
    void manager_display();
    void manager_duties();
};
```
**Main function usage:**
```
int main() {
    Chef c1(123, "Eman", 5, 1500, 2002, "Stack", "Pizza");
    c1.chef_display();
    // ... similarly for Waiter and Manager
}
```

### Example Output

```
<><><><><><><> Chef <><><><><><><>
ID: 123
Name: Eman
Special Dishes: Stack, Pizza
Working Hours: 5
Hourly Wage: 1500
Total Salary: 7500
Employment Since: 2002
Duties of Chef:
  1. Menu Planning
  2. Food Preparation
  3. Kitchen Management
  4. Cooking
  5. Quality Control
```
