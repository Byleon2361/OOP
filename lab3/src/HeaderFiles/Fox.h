#pragma once
#include "Animal.h"
class Fox : protected Animal
{
public:
    Fox();
    ~Fox();

private:
    int change(int d) override; // d - direction
    int changeAge() override;
    int changeDirection() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵
};