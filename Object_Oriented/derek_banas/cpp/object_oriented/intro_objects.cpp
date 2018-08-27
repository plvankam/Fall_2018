#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<numeric>
#include<math.h>

using std::endl;

class Animal
{
    private:
        std::string name;
        double height;
        double weight;

        static int numOfAnimals;
    public:

        // SETTERS 
        // GETTERS
        //
        // name
        void SetName(const std::string& name) {this->name = name;}
        const std::string& GetName(){return name;}
        // height
        void SetHeight(const double height) {this->height = height;}
        double GetHeight(){return height;}
        // weight
        void SetWeight(const double weight) {this->weight = weight;}
        double GetWeight(){return weight;}

        // set all
        void SetAll(std::string, double, double);

        // constructor
        Animal(std::string, double, double); // decl
        Animal();                            // decl
        ~Animal();                           // decl
        static int GetNumOfAnimals() {return numOfAnimals;}
        void ToString();
};

int Animal::numOfAnimals = 0;

void Animal::SetAll(std::string name, double height, double weight)
{
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}

Animal::Animal(std::string name, double height, double weight)
{
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}

Animal::Animal()
{
    this->name = "";
    this->weight = o;
    this->height = 0;
    Animal::numOfAnimals++;
}

Animal::~Animal()
{
    std::cout << "Animal" << sthis->name
              << "destroyed." << endl;
}

void Animal::ToString()
{
    std::cout << this->name << " is " 
        << height << " cm tall and " 
        << weight << " pounds." << endl;
}

int main()
{


    return 0;
}
