#pragma once
#include <iostream>
#include "Animal.h"
#include "Rabbit.h"
using namespace ::std;
class Fox : public Animal
{
public:
    Fox() : Animal()
    {
        Animal::deathAge = 15;
        Animal::step = 2;
        saturation = 0;
    }
    Fox(int x, int y, int direction, int stability) : Fox()
    {
        this->x = x;
        this->y = y;
        this->direction = direction;
        this->stability = stability;
    }
    Fox(const Fox *&fox)
    {
        this->x = fox->x;
        this->y = fox->y;
        this->direction = fox->direction;
        this->changeDir = 0;
        this->stability = fox->stability;
        this->age = 0;
        this->deathAge = fox->deathAge;
        this->step = fox->step;
        this->saturation = 0;
    }
    void Move();
    int saturation; // насыщение
public:
    // геттеры и сеттеры
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_stability() const { return stability; }
    int get_direction() const { return direction; }
    void set_food(int foodCount);
};