#pragma once
#include "Animal.h"
class Rabbit : public Animal
{
public:
    Rabbit() : Animal()
    {
        Animal::deathAge = 10;
        Animal::step = 1;
    }
    ~Rabbit() {}

private:
    int changeAge() override;
    void eat();             // 🍍
    void death() override;  // ☠
    Animal *sex() override; // 🥵
};
