#include<iostream>
#include<cstdlib> // std::rand()
#include<cstdlib> // srand()
#include<ctime>   // time()
#include<cmath>
#include<string>

using std::endl;

//________________________________________
//######### Warrior ######################
//
class Warrior
{
    private:
        int attackMax;
        int blockMax;
    public:
        std::string name;
        int health;
        int Attack();
        int Block();
        Warrior(std::string name, int health, 
                int aMax, int bMax);
};

// Attack()
//
int Warrior::Attack()
{
    return std::rand() % this->attackMax;
}
// Block()
//
int Warrior::Block()
{
    return std::rand() % this->blockMax;
}
// Warrior()
//
Warrior::Warrior(std::string name, int health, 
                int aMax, int bMax)
{
    attackMax = aMax;
    blockMax = bMax;
    this->health = health;
    this->name = name;
}
//
//######### Warrior End ##################

//________________________________________
//######### Battle #######################
//
class Battle
{
    public:
        static void StartFight(Warrior&,Warrior&);
        static int GetAttackResult(Warrior&, Warrior&);
};

// StartFight()
void Battle::StartFight(Warrior& warrior1, Warrior& warrior2)
{
    while(1)
    {
        if(0 == Battle::GetAttackResult(warrior1, warrior2))
        {
            std::cout << "Game Over\n";
            break;
        }
        if(0 == Battle::GetAttackResult(warrior2, warrior1))
        {
            std::cout << "Game Over\n";
            break;
        }
    }
}

// GetAttackResult()
int Battle::GetAttackResult(Warrior& warrior1, Warrior& warrior2)
{
    int warrior1AttackAmt = warrior1.Attack(); 
    int warrior2BlockAmt  = warrior2.Block(); 
    int damage2WarriorB = ceil(warrior1AttackAmt - warrior2BlockAmt);
    damage2WarriorB = (damage2WarriorB < 0) ? 0 : damage2WarriorB;
    warrior2.health = (warrior2.health - damage2WarriorB) < 0 ? 0 : (warrior2.health - damage2WarriorB) ;
    // print on attack and health 
    std::cout << warrior1.name << " attacks " 
              << warrior2.name << " and deals " 
              << damage2WarriorB << " damage " << endl;
    std::cout << warrior2.name << " is down to " 
              << warrior2.health << " health " << endl;
    //
    // 0 => game over
    if(warrior2.health < 1) return 0;
    else return 1;
}

//######### Battle End ###################

int main()
{
    // time as a seed 
    srand(time(NULL));
    Warrior thor("thor", 100, 30, 15);
    Warrior hulk("hulk", 135, 25, 10);
    // fight 
    Battle::StartFight(thor,hulk);

    return 0;
}
