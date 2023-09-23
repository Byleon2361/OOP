#pragma once
#include "Animal.h"
class Rabbit : protected Animal
{
public:
    Rabbit();
    ~Rabbit();

private:
    void change(int d) override; // d - direction
    int changeAge() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵
};