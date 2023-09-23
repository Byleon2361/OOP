#pragma once
#include "Animal.h"
class Rabbit : public Animal
{
private:
    int changeAge() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵
};