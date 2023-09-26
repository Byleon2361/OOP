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
    Rabbit(int x, int y) : Rabbit()
    {
        this->x = x;
        this->y = y;
    }
    ~Rabbit() {};
    void Move();

private:
    int changeAge() ;
    void death() ; // ☠
    Animal *sex() ;   // 🥵

public:
    int get_x() const {return x;}
    int get_y() const {return y;}
    int get_stability() const {return stability;}
    int get_direction() const {return direction;}
};