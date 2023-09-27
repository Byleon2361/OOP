#include "Fox.h"
#include "Rabbit.h"
#include <iostream>
#include <cstdlib>

using namespace std;
void Fox::Move()
{
    change(changeDirection());
}
int Fox::changeAge()
{
    return age++;
}
// нужен class model
void Fox::eat()
{
    saturation++;
    if (saturation == 2)
        sex();
}
// лишняя
void Fox::death()
{
}
Fox *Fox::sex()
{
    Fox *newFox = new Fox(*this);
    return newFox;
}
void Fox::set_food(int foodCount)
{
    if (foodCount > 0)
    {
        saturation = foodCount;
    }
}
