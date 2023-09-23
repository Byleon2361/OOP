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
    ~Rabbit() override;

private:
    int changeAge() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵
};