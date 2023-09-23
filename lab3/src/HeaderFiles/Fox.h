#pragma once
#include "Animal.h"
class Fox : protected Animal
{
public:
    Fox();

private:
    void change(int d) override; // d - direction
    int changeAge() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵
};