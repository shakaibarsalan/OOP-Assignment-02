#include <iostream>

using namespace std;

class animal
{
private:
    /* data */
    string name;
    int age;
    string habitat;
    float weight;
    string gender;

public:
    animal(string name, int age, string habitat, float weight, string gender);
    void aniDisplay();
    ~animal();
};

animal::animal(string name, int age, string habitat, float weight, string gender)
{
    this->name = name;
    this->age = age;
    this->habitat = habitat;
    this->weight = weight;
}
void animal::aniDisplay()
{
    cout << "  -> Name of Animal: "<<name << "\n";
    cout << "  -> Age of " << name << ": " << age << "\n";
    cout << "  -> Habitat of " << name << ": " << habitat << "\n";
    cout << "  -> Weight: " << weight << "\n";
}
animal::~animal()
{
}

class lions : protected animal
{
private:
    /* data */
    string food_source;
    string feeding_frequency;

public:
    lions(string name, int age, string habitat, float weight, string gender, string food_source, string feeding_frequency);
    void lionDisplay();
    void getfun();
    ~lions();
};

lions::lions(string name, int age, string habitat, float weight, string gender, string food_source, string feeding_frequency)
    : animal(name, age, habitat, weight, gender)
{
}
void lions::lionDisplay()
{
    cout << "  -> Food Source: " << food_source << "\n";
    cout << "  -> Feeding Frequency: " << feeding_frequency << "\n";
}
void lions::getfun()
{
    aniDisplay();
}
lions::~lions()
{
}

class tigers : protected animal
{
private:
    /* data */
    string special_ability;
    int life_span;

public:
    tigers(string name, int age, string habitat, float weight, string gender, string special_ability, int life_span);
    void tigDisplay();
    void getfun();
    ~tigers();
};

tigers::tigers(string name, int age, string habitat, float weight, string gender, string special_ability, int life_span)
    : animal(name, age, habitat, weight, gender)
{
    this->special_ability = special_ability;
    this->life_span = life_span;
}
void tigers ::tigDisplay()
{
    cout << "  -> Life Span: " << life_span << "\n";
    cout << "  -> Special Abitity: " << special_ability << "\n";
}
void tigers::getfun()
{
    aniDisplay();
}
tigers::~tigers()
{
}

class elephant : protected animal
{
private:
    /* data */
    float average_weight;
    int trunk_length;

public:
    elephant(string name, int age, string habitat, float weight, string gender, float average_weight, int trunk_length);
    void eleDisplay();
    void getfun();
    ~elephant();
};

elephant::elephant(string name, int age, string habitat, float weight, string gender, float average_weight, int trunk_length)
    : animal(name, age, habitat, weight, gender)
{
    this->average_weight = average_weight;
    this->trunk_length = trunk_length;
}
void elephant::eleDisplay()
{
    cout << "  -> Average Weight: " << average_weight << "\n";
    cout << "  -> Elephant Trunk Length: " << trunk_length << "\n";
}
void elephant::getfun()
{
    aniDisplay();
}
elephant::~elephant()
{
}

int main()
{
    cout << "============ LION DETAILS ============\n";
    lions l1("Simba", 5, "Savannah", 150.5, "Male", "Zebras", "Twice a day");
    l1.getfun();
    l1.lionDisplay();
    cout << endl;

    cout << "=========== TIGER DETAILS ===========\n";
    tigers t1("Rajah", 7, "Jungle", 200.3, "Male", "Camouflage", 15);
    t1.getfun();
    t1.tigDisplay();
    cout << endl;

    cout << "========== ELEPHANT DETAILS ==========\n";
    elephant e1("Dumbo", 10, "Forest", 3000.7, "Male", 5000.2, 200);
    e1.getfun();
    e1.eleDisplay();
    cout << endl;

    return 0;
}
