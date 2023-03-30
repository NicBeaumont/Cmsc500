#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
class Organism
{
    public:
     int age;
     std::string name;
     bool isAlive;

    Organism(int a, std::string n)
    {
        age = a;
        name = n;
        isAlive = true;
    }

    ~Organism(){}

    bool operator<(const Organism& o)
    {
        return this->age < o.age;
    }
};

class Population
{
    public:
     std::vector<Organism*> popvec;
    
    Population(std::vector<Organism*> v)
    {
        popvec = v;
        std::sort(popvec.begin(),popvec.end());
    }
};

int main()
{
    std::vector<Organism*> vec;
    for(int i = 0; i<20; i++)
    {
        Organism o = Organism(std::rand()%100, "Bob");
        std::cout << o.name;
        vec.push_back(&o);
    }
    Population pop = Population(vec);
}