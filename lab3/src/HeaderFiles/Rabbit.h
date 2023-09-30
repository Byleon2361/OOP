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
    Rabbit(const Rabbit *&rabbit)
    {
        this->x = rabbit->x;
        this->y = rabbit->y;
        this->direction = rabbit->direction;
        this->changeDir = 0;
        this->stability = rabbit->stability;
        this->age = 0;
        this->deathAge = rabbit->deathAge;
        this->step = rabbit->step;
    }
    ~Rabbit(){};
    void Move();
    int changeAge() override;
    void death() override; // ☠
    Rabbit *sex();         // 🥵

public:
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_stability() const { return stability; }
    int get_direction() const { return direction; }
};