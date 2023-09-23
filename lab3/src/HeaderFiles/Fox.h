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
    ~Fox() override;

private:
    int changeAge() override;
    void eat(Rabbit *rabbit); // 🍍
    void death() override;    // ☠
    void sex() override;      // 🥵
public:
    // геттеры и сеттеры
    int get_x() const;
    int get_y() const;
    int get_stability() const;
    int get_direction() const;
    void set_food(int foodCount);
};