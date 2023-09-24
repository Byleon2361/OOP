#include <iostream>
#include "Fox.h"
#include "Rabbit.h"
#include "Model.h"
using namespace std;
int main()
{
    int n, m, countFoxes, countRabbits, x, y;
    Model model;
    cout << "Введите длину поля" << endl;
    cin >> n;

    cout << "Введите длину ширину" << endl;
    cin >> m;
    model.set_n(n);
    model.set_m(m);
    model.set_field();
    /*
    cout << "Введите количество зайцев" << endl;
    cin >> countRabbits;
    for (int i = 0; i < countRabbits; i++)
    {
        x = rand() % n;
        y = rand() % m;
        Rabbit *rabbit = new Rabbit(x,y);
        model.set_rabbit(rabbit);
    }
    */
    cout << "Введите количество лисов" << endl;
    cin >> countFoxes;
    for (int i = 0; i < countFoxes; i++)
    {
        x = rand() % n;
        y = rand() % m;
        Fox *fox = new Fox(x, y);
        model.set_fox(fox);
    }
    // model.test();
    model.printModel();
    return 0;
}