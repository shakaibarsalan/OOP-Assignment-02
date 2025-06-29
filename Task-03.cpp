#include <iostream>

using namespace std;

class specie
{
private:
    string name;
    int cage_no;
    int age;
    int weight;
    int avg_life;
public:
    specie(string name, int cage_no, int age, int weight, int avg_life);
    void specie_display();
    ~specie();
};

specie::specie(string name, int cage_no, int age, int weight, int avg_life)
{
    this->name = name;
    this->cage_no = cage_no;
    this->age = age;
    this->weight = weight;
    this->avg_life = avg_life;
}
void specie::specie_display()
{
    cout << "  -> Name: " << name << "\n";
    cout << "  -> Cage Number: " << cage_no << "\n";
    cout << "  -> Age: " << age << " years\n";
    cout << "  -> Weight: " << weight <<" kg\n";
    cout << "  -> Average Life: " << avg_life << " years\n";
}
specie::~specie()
{
}

class animals : protected specie
{
private:
    string reproduction;
    string breed;
    string colour;

public:
    animals(string name, int cage_no, int age, int weight, int avg_life, string reproduction, string breed, string colour);
    void animal_display();
    ~animals();
};

animals::animals(string name, int cage_no, int age, int weight, int avg_life, string reproduction, string breed, string colour)
    : specie(name, cage_no, age, weight, avg_life)
{
    this->reproduction = reproduction;
    this->breed = breed;
    this->colour = colour;
}
void animals ::animal_display()
{
    specie_display();
    cout << "  -> Breed: " << breed << "\n";
    cout << "  -> Colour: " << colour << "\n";
    cout << "  -> Reproduction: " << reproduction << "\n";
}
animals::~animals()
{
}

class reptile : protected specie
{
private:
    string habitat;
    float length;

public:
    reptile(string name, int cage_no, int age, int weight, int avg_life, string habitat, float length);
    void reptile_display();
    ~reptile();
};

reptile::reptile(string name, int cage_no, int age, int weight, int avg_life, string habitat, float length) 
    : specie(name, cage_no, age, weight, avg_life)
{
    this->habitat = habitat;
    this->length = length;
}
void reptile::reptile_display()
{
    specie_display();
    cout << "  -> Habitat: " << habitat << "\n";
    cout << "  -> Length: " << length << " ft.\n";
}
reptile::~reptile()
{
}

class dog : protected animals
{
private:
    string voice;
    int bite_level;

public:
    dog(string name, int cage_no, int age, int weight, int avg_life, string reproduction, string breed, string colour, string voice, int bite_level);
    void dog_dispaly();
    void print_hobbies();
    ~dog();
};

dog::dog(string name, int cage_no, int age, int weight, int avg_life, string reproduction, string breed, string colour, string voice, int bite_level)
    : animals(name, cage_no, age, weight, avg_life, reproduction, breed, colour)
{
    this->voice = voice;
    this->bite_level = bite_level;
}
void dog ::dog_dispaly()
{
    animal_display();
    cout << "  -> Voice: " << voice << "\n";
    cout << "  -> Bite Level: " << bite_level << " N\n";
    print_hobbies();
}
void dog::print_hobbies()
{
    cout << "  -> Hobbies: Playing fetch\n     Going for walks\n";
}
dog::~dog()
{
}

class cat : protected animals
{
private:
    string gender;
    string feed;

public:
    cat(string name, int cage_no, int age, int weight, int avg_life, string reproduction, string breed, string colour, string gender, string feed);
    void cat_display();
    void print_hobbies();
    ~cat();
};

cat::cat(string name, int cage_no, int age, int weight, int avg_life, string reproduction, string breed, string colour, string gender, string feed)
    : animals(name, cage_no, age, weight, avg_life, reproduction, breed, colour)
{
    this->gender = gender;
    this->feed = feed;
}
void cat::cat_display()
{
    animal_display();
    cout << "  -> Gender: " << gender << "\n";
    cout << "  -> Feed: " << feed << "\n";
    print_hobbies();
}
void cat::print_hobbies()
{
    cout << "  -> Hobbies: Playing with toys\n     Hunting\n";
}
cat::~cat()
{
}

class snack : protected reptile
{
private:
    string type;
    int calories;

public:
    snack(string name, int cage_no, int age, int weight, int avg_life, string habitat, float length, string type, int calories);
    void snack_display();
    void print_hobbies();
    ~snack();
};

snack::snack(string name, int cage_no, int age, int weight, int avg_life, string habitat, float length, string type, int calories)
    : reptile(name, cage_no, age, weight, avg_life, habitat, length)
{
    this->type = type;
    this->calories = calories;
}
void snack::snack_display()
{
    reptile_display();
    cout << "  -> Type: " << type << "\n";
    cout << "  -> Calories: " << calories << "\n";
    print_hobbies();
}
void snack::print_hobbies()
{
    cout << "  -> Hobbies: Sunbathing\n     Exploring surroundings\n";
}
snack::~snack()
{
}

class crocodile : protected reptile
{
private:
    string isAquatic;
    int numTeeth;

public:
    crocodile(string name, int cage_no, int age, int weight, int avg_life, string habitat, float length, string isAquatic, int numTeeth);
    void print_hobbies();
    void crocodile_display();
    ~crocodile();
};

crocodile::crocodile(string name, int cage_no, int age, int weight, int avg_life, string habitat, float length, string isAquatic, int numTeeth)
    : reptile(name, cage_no, age, weight, avg_life, habitat, length)
{
    this->isAquatic = isAquatic;
    this->numTeeth = numTeeth;
}
void crocodile::print_hobbies()
{
    cout << "  -> Hobbies: Swimming\n     Basking in the sun\n";
}
void crocodile ::crocodile_display()
{
    reptile_display();
    cout << "  -> Is Aquatic: " << isAquatic << "\n";
    cout << "  -> Number of Teeths: " << numTeeth << "\n";
    print_hobbies();
}
crocodile::~crocodile()
{
}

int main()
{
    cout << "*********** Dog Details ***********\n";
    dog dog1("Tommy", 1, 3, 15, 10, "Give Birth to Child", "Labrador", "Golden", "Bark", 230);
    dog1.dog_dispaly();
    cout << endl;

    cout << "*********** Cat Details ***********\n";
    cat cat1("Whiskers", 2, 5, 8, 15, "Give Birth to Child", "Siamese", "White", "Female", "Fish");
    cat1.cat_display();
    cout << endl;

    cout << "******** Crocodile Details ********\n";
    crocodile cro1("Crock", 3, 10, 500, 60, "Swamp", 6.2, "Yes", 80);
    cro1.crocodile_display();
    cout << endl;

    cout << "********** Snack Details **********\n";
    snack mySnack("Snakey", 4, 2, 2, 5, "Forest", 1.5, "Python", 100);
    mySnack.snack_display();
    cout << endl;

    return 0;
}
