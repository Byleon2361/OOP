#include "Rabbit.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Rabbit::Move()
{
    change(changeDirection());
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

void Rabbit::death()
{
    this->~Rabbit();
}

Animal *Rabbit::sex()
{
    Rabbit *newRabbit = this;
    return newRabbit;
}