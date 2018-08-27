#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<numeric>
#include<math.h>

using std::endl;


//######################################## class
// {         ANIMAL
class Animal
{
    protected:
        std::string name;
        double height;
        double weight;
        // static count 
        static int numOfAnimals;

    public:
        // getters & setters
        // name 
        std::string getName() {return name;}
        void setName(std::string name) {this->name = name;}
        // height 
        double getHeight() {return height;}
        void setHeight(double height) {this->height = height;} 
        // weight
        double getWeight() {return weight;}
        void setWeight(double weight) {this->weight = weight;} 

        // set all
        void setAll(std::string name, double height , double weight);

        // constructor & destructor 
        Animal(std::string name, double height, double weight);
        Animal();
        ~Animal();
        static int getNumberOfAnimals() {return numOfAnimals;}
        void ToString();
};

// num of animals 
int Animal::numOfAnimals = 0;
// set all
void Animal::setAll(std::string name, double height, double weight)
{
    this->name = name;
    this->weight = weight;
    this->height = height;
}
// constructor  3 args
Animal::Animal(std::string name, double height, double weight)
{
    this->name = name;
    this->weight = weight;
    this->height = height;
    numOfAnimals++;
}
// constructor  3 args
Animal::Animal()
{
    this->name = "";
    this->weight = 0;
    this->height = 0;
    numOfAnimals++;
}
// destructor 
Animal::~Animal()
{
    std::cout << "We destroyed " << name << "." << endl;
}
// to string 
void Animal::ToString()
{
    std::cout << this->name << " is " 
        << this->height << " cm tall and " 
        << this->weight << " lbs." << endl;
}

// }         ANIMAL END 
//######################################## class end 

//######################################## class 
// {             DOG
class Dog : public Animal
{
    private:
        std::string sound = "Woof";
    public:
        void makeSound() 
        { 
            std::cout << sound ;
        }
        Dog(std::string, double, double, std::string);
        Dog() : Animal(){};
        void ToString();
};

Dog::Dog(std::string name, double height, 
         double weight, std::string sound) : Animal(name, height, weight)
{
        this->sound  = sound;
}

void Dog::ToString()
{
    std::cout << this->name 
        << " is " 
        << this->height << " cm tall and " 
        << this->weight << " lbs." 
        << " and makes the sound " 
        << sound 
        << endl;
}

// }            DOG END 
//######################################## class end

//########################################
//          main()
int main()
{

    // ANIMAL
    // fred
    Animal fred;
    fred.ToString();
    fred.setAll("fred",200,123);
    fred.ToString();
    // tom
    Animal tom("tom", 23, 34);
    tom.ToString();

    // DOG 
    // spot
    Dog spot("spot", 23, 34, "ruff");
    spot.ToString();
    std::cout << "Number of animals created: " 
              << Animal::getNumberOfAnimals()
              << endl;

    return 0;
}
