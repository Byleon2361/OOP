#include "Model.h"
#include <iostream>
using namespace std;
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
        field[masF[i]->y][masF[i]->x]--;
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
        field = new int *[n];
        for (int i = 0; i < n; i++)
            field[i] = new int[m];
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