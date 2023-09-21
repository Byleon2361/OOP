#include "Fox.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Fox::Fox()
{
    deathAge = 15;
    step = 2;
    age = 0;
    stability = 0;
    x = 0;
    y = 0;
    int direction = rand() % 3;
}
int Fox::change(int d)
{
}
int Fox::changeAge()
{
}
int Fox::changeDirection()
{
}
void Fox::eat()
{
}
void Fox::death()
{
}
void Fox::sex()
{
}