#include "Fox.h"
#include "Rabbit.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int Fox::changeAge()
{
    if (age > 15)
    {
        this->~Fox();
    }
    return age++;
}
// нужен class model
void Fox::eat(Rabbit *rabbit)
{
    saturation++;
    if (saturation == 2)
        sex();     //))))))))))))))))))))))()O())))))))
    delete rabbit; //((((((((
}
// лишняя
void Fox::death()
{
}
Animal *Fox::sex()
{
    this->saturation = 0;
    Fox *newFox = this;
    return newFox;
}
void Fox::set_food(int foodCount)
{
    if (foodCount > 0)
    {
        saturation = foodCount;
    }
}
