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
    return age++;
}

void Rabbit::death()
{
    this->~Rabbit();
}

Rabbit *Rabbit::sex()
{
    Rabbit *newRabbit = new Rabbit(*this);
    // newRabbit = this;
    return newRabbit;
}