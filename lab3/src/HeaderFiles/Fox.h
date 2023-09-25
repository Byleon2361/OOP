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
    ~Fox() {}
    void Move();

private:
    int changeAge() override;
    void eat(Rabbit *rabbit); // 🍍
    void death() override;    // ☠
    Animal *sex() override;   // 🥵
public:
    // геттеры и сеттеры
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_stability() const { return stability; }
    int get_direction() const { return direction; }
    void set_food(int foodCount);
};