#include "Model.h"
#include <iostream>
#include <algorithm>
using namespace std;
int Model::n = 0;
int Model::m = 0;
void Model::printModel()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            field[i][j] = 0;
        }
    }
    for (int i = 0; i < masF.size(); i++)
    {
        cout << "masF[i]->y" << masF[i]->y << endl;
        cout << "masF[i]->x" << masF[i]->x << endl;
        field[masF[i]->y][masF[i]->x]--;
    }
    for (int i = 0; i < masR.size(); i++)
    {
        cout << "masR[i]->y" << masR[i]->y << endl;
        cout << "masR[i]->x" << masR[i]->x << endl;
        field[masR[i]->y][masR[i]->x]++;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (field[i][j] == 0)
                cout << '*';
            else
                cout << field[i][j];
        }
        cout << endl;
    }
}
void Model::set_rabbit(Rabbit *rabbit)
{
    masR.push_back(rabbit);
}
void Model::set_fox(Fox *fox)
{
    masF.push_back(fox);
}
void Model::set_field()
{
    if (n > 0 && m > 0)
    {
        field = new int *[m];
        for (int i = 0; i < m; i++)
            field[i] = new int[n];
    }
}
void Model::test()
{
    cout << "Count" << masF.size() << endl;
    for (Fox *f : masF)
    {
        cout << "X: " << f->x << endl;
        cout << "Y: " << f->y << endl;
    }
}
void Model::newStep()
{
    for (Rabbit *rabbit : masR)
    {
        cout << "rabbit direction" << rabbit->direction << endl;
        rabbit->Move();
        rabbit->age++;
        if (rabbit->age == 5)
        {
            Rabbit *newRabbit = new Rabbit(*rabbit);
            masR.push_back(newRabbit);
        }

        if (rabbit->age == rabbit->deathAge)
        {
            auto indexDeadRabbit = find(masR.begin(), masR.end(), rabbit);
            masR.erase(indexDeadRabbit);
            delete rabbit;
            Rabbit *newRabbit = new Rabbit(*rabbit);
            masR.push_back(newRabbit);
        }
    }
    for (Fox *fox : masF)
    {
        fox->Move();
        fox->age++;
        for (Rabbit *rabbit : masR)
        {
            if ((fox->x == rabbit->x) && (fox->y == rabbit->y))
            {
                auto indexDeadRabbit = find(masR.begin(), masR.end(), rabbit);
                masR.erase(indexDeadRabbit);
                delete rabbit;

                fox->saturation++;
                if (fox->saturation == 2)
                {
                    Fox *newFox = new Fox(*fox);
                    masF.push_back(newFox);
                    fox->saturation = 0;
                }
            }
        }
        if (fox->age == fox->deathAge)
        {
            auto indexDeadFox = find(masF.begin(), masF.end(), fox);
            masF.erase(indexDeadFox);
            delete fox;
        }
    }
}