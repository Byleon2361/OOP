#include "Rabbit.h"
#include <iostream>
#include <cstdlib>
using namespace std;

viod Fox::Move()
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
    
    eturn age++;
}

void Rabbit::death()
{
    this->~Rabbit();
}

void Rabbit::sex()
{
    Rabbit *newRabbit = this;
    return newRabbit;
}