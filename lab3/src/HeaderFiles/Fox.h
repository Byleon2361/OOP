#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
    Fox(); // deathAge(15), step(2), age(0), stability(0), x(0), y(0), direction(rand() % 3);
    ~Fox();

private:
    int changeAge() override;
    void eat() override;   // 🍍
    void death() override; // ☠
    void sex() override;   // 🥵
public:
    // геттеры и сеттеры
    int get_x() const;
    int get_y() const;
    int get_stability() const;
    int get_direction() const;
    void set_food(int foodCount);
};