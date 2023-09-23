#include "Rabbit.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Rabbit::~Rabbit()
{
}
void Rabbit::change(int d)
{
    switch(direction)
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
void Rabbit::changeDirection()
{
    if ((rand()%100) < (100 - stability))
    {
        direction++;
        if(direction == 3)
            direction = 0;
    }
}
int Rabbit::changeAge()
{
    if (age > 10)
    {
        sex();
        this->~Rabbit();
    }
    return age++;
}
int Rabbit::get_x() const
{
    return x;
}
int Rabbit::get_y() const
{
    return y;
}
int Rabbit::get_stability() const
{
    return stability;
}
int Rabbit::get_direction() const
{
    return direction;
}
/*//нахуй
void Rabbit::eat()
{
}
*/
void Rabbit::death()
{
    this->~Rabbit();
}
void Rabbit::sex()
{

}