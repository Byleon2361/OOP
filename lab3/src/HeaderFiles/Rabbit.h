#pragma once
#include "Animal.h"
class Rabbit : protected Animal
{
public:
    Rabbit() : Animal()
    {
        Animal::deathAge = 10;
        Animal:: step = 1;
    }
    ~Rabbit();

private:
    void change(int d) override; // d - direction
    void changeDirection() override;
    int changeAge() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵
};