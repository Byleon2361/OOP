#include "Animal.h"
#include "Model.h"
#include <iostream>
using namespace std;
void Animal::change(int d)
{

    switch (d)
    {
    case 0:
        y -= step;
        if (y < 0)
            y = Model::m - 1;
        break;
    case 1:
        x += step;
        if (x >= Model::n)
            x = 0;
        break;
    case 2:
        y += step;
        if (y >= Model::m)
            y = 0;
        break;
    case 3:
        x -= step;
        if (x < 0)
            x = Model::n - 1;
        break;
    }
}
int Animal::changeDirection()
{
    if ((rand() % 100) > (100 - stability))
    {
        direction++;
        if (direction == 3)
            direction = 0;
    }
    return direction;
}