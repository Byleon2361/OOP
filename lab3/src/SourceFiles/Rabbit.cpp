#include "Rabbit.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Rabbit::Rabbit()
{
    deathAge = 10;
    step = 1;
    age = 0;
    stability = 0;
    x = 0;
    y = 0;
    direction = rand() % 3;
}
void Rabbit::change(int d)
{
    switch(direction)
    {
    case 0:
        y += step;q
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