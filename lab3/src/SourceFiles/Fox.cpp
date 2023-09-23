#include "Fox.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Fox::Fox()
{
    deathAge = 15;
    step = 2;
    age = 0;
    stability = 0;
    x = 0;
    y = 0;
    direction = rand() % 3;
}
Fox::~Fox()
{
}
int Fox::changeAge()
{
    if (age > 15)
    {
        this->~Fox();
    }
    return age++;
}
// нужен class model
void Fox::eat()
{
}
// лишняя
void Fox::death()
{
    // cout << "death form fox";
}
void Fox::sex()
{
}
int Fox::get_x() const
{
    return x;
}
int Fox::get_y() const
{
    return y;
}
int Fox::get_stability() const
{
    return stability;
}
int Fox::get_direction() const
{
    return direction;
}
void Fox::set_food(int foodCount)
{
    if (foodCount > 0)
    {
        saturation = foodCount;
    }
}