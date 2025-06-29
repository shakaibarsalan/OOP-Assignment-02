#include <iostream>

using namespace std;
class character
{
private:
    /* data */
    int age;
    int level;
    int strength;
    string name;
    string gender;

public:
    character(string name, int age, int level, int strength, string gender);
    void char_display();
    ~character();
};

character::character(string name, int age, int level, int strength, string gender)
{
    this->name = name;
    this->age = age;
    this->level = level;
    this->strength = strength;
    this->gender = gender;
}
void character ::char_display()
{
    cout << "   Player Age: " << age << "\n";
    cout << "   Strength: " << strength << " %\n";
    cout << "   Player Name: " << name << "\n";
    cout << "   Player Gender: " << gender << "\n";
    cout << "   Level of Player: " << level << "\n";
}
character::~character()
{
}

class warrior : protected character
{
private:
    /* data */
    string speciality;
    int armor;
    int battle;     // total wars
    int win_battle; // total war wins
public:
    warrior(string name, int age, int level, int strength, string gender, string speciality, int armor, int battle, int win_battle);
    void war_display();
    ~warrior();
};

warrior::warrior(string name, int age, int level, int strength, string gender, string speciality, int armor, int battle, int win_battle)
    : character(name, age, level, strength, gender)
{
    this->speciality = speciality;
    this->armor = armor;
    this->battle = battle;
    this->win_battle = win_battle;
}
void warrior ::war_display()
{
    cout << "~~~~~~~~~~~~~~~ Warrior ~~~~~~~~~~~~~~~\n";
    char_display();
    cout << "   Speciality of Warrior: " << speciality << "\n";
    cout << "   Remaning Armor: " << armor << " %\n";
    cout << "   Total no of Battle's Defeated: " << battle << "\n";
    cout << "   Win Battle's: " << win_battle << "\n";
}
warrior::~warrior()
{
}

class mages : protected character
{
private:
    /* data */
    string trick_01; // magic tick name 01
    string trick_02; // magic tick name 02
    int kills;

public:
    mages(string name, int age, int level, int strength, string gender, string trick_01, string trick_02, int kills);
    void mag_diaplay();
    ~mages();
};

mages::mages(string name, int age, int level, int strength, string gender, string trick_01, string trick_02, int kills)
    : character(name, age, level, strength, gender)
{
    this->trick_01 = trick_01;
    this->trick_02 = trick_02;
    this->kills = kills;
}
void mages::mag_diaplay()
{
    cout << "~~~~~~~~~~~~~~~ Mages ~~~~~~~~~~~~~~~\n";
    char_display();
    cout << "   Mages 1st Trick: " << trick_01 << "\n";
    cout << "   Mages 1st Trick: " << trick_02 << "\n";
    cout << "   Total No of Kills: " << kills << "\n";
}
mages::~mages()
{
}

class archer : protected character
{
private:
    /* data */
    string super_power;
    int accuracy;
    int sight;

public:
    archer(string name, int age, int level, int strength, string gender, string super_power, int accuracy, int sight);
    void arc_display();
    ~archer();
};

archer::archer(string name, int age, int level, int strength, string gender, string super_power, int accuracy, int sight)
    : character(name, age, level, strength, gender)
{
    this->super_power = super_power;
    this->accuracy = accuracy;
    this->sight = sight;
}
void archer ::arc_display()
{
    cout << "~~~~~~~~~~~~~~~ Mages ~~~~~~~~~~~~~~~\n";
    char_display();
    cout << "   Super Power of Archer: " << super_power << "\n";
    cout << "   Accuracy to through Arrow: " << accuracy << " %\n";
    cout << "   Archer able to through Arrow " << sight << " km far.\n";
}
archer::~archer()
{
}

int main()
{
    warrior w1("Arman Warrior", 25, 10, 100, "Male", "Sword Fighting", 80, 20, 15);
    w1.war_display();
    cout << endl;

    mages m1("Eman Mages", 30, 15, 80, "Female", "Fireball", "Ice Blast", 50);
    m1.mag_diaplay();
    cout << endl;

    archer a1("Umair Archer", 28, 12, 90, "Male", "Hawkeye", 95, 2);
    a1.arc_display();

    return 0;
}