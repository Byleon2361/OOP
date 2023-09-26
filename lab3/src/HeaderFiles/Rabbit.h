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
    Rabbit(int x, int y) : Rabbit()
    {
        this->x = x;
        this->y = y;
    }
    ~Rabbit(){};
    void Move();

private:
    int changeAge() override;
    void death() override;  // ☠
    Animal *sex() override; // 🥵

public:
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_stability() const { return stability; }
    int get_direction() const { return direction; }
};