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
    ~Rabbit() {};
    void Move();

private:
    void change(int d) override; // d - direction
    void changeDirection() override;
    int changeAge() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵

public:
    int get_x() const {return x;}
    int get_y() const {return y;}
    int get_stability() const {return stability;}
    int get_direction() const {return direction;}
};