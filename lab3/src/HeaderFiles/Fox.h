#pragma once
#include "Animal.h"
#include "Rabbit.h"
class Fox : public Animal
{
public:
    Fox() : Animal()
    {
        Animal::deathAge = 15;
        Animal::step = 2;
    }
    Fox(int x, int y) : Fox()
    {
        this->x = x;
        this->y = y;
    }
    Fox(const Fox *&fox)
    {
        this->x = fox->x;
        this->y = fox->y;
        this->direction = fox->direction;
        this->stability = fox->stability;
        this->age = 0;
        this->deathAge = fox->deathAge;
        this->step = fox->step;
        this->saturation = 0;
    }
    ~Fox() {}
    void Move();
    void eat(); // 🍍
    int changeAge() override;
    void death() override; // ☠
    Fox *sex();            // 🥵
    int saturation;        // насыщение
public:
    // геттеры и сеттеры
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_stability() const { return stability; }
    int get_direction() const { return direction; }
    void set_food(int foodCount);
};