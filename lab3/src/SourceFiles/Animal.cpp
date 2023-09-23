#include "Animal.h"
#include <iostream>
using namespace std;
void Animal::change(int d)
{

    switch (d)
    {
    case 0:
        y += step;
        break;
    case 1:
        x += step;
        break;
    case 2:
        y -= step;
        break;
    case 3:
        x -= step;
        break;
    }
}
int Animal::changeDirection()
{
    if ((rand() % 100) < (100 - stability))
    {
        direction++;
        if (direction == 3)
            direction = 0;
    }
    return direction;
}