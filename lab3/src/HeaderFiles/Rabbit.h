#pragma once
#include "Animal.h"
class Rabbit : protected Animal
{
private:
    Rabbit();
    ~Rabbit();
    int change(int d) override; // d - direction
    int changeAge() override;
    int changeDirection() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵
};