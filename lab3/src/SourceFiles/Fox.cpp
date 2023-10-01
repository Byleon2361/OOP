#include "Fox.h"
#include "Rabbit.h"
#include <iostream>
#include <cstdlib>

using namespace std;
void Fox::Move()
{
    change(changeDirection());
}
void Fox::set_food(int foodCount)
{
    if (foodCount > 0)
    {
        saturation = foodCount;
    }
}
