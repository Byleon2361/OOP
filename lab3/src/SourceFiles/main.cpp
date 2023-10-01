#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include "Fox.h"
#include "Rabbit.h"
#include "Model.h"
using namespace std;
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        cout << "The number of arguments passed must be one" << endl;
        return 1;
    }
    ifstream fin(argv[1]);
    char str[50], *token;

    if (!fin.is_open())
    {
        cout << "не удалось открыть файл" << endl;
        return 1;
    }
    fin.getline(str, 50);
    token = strtok(str, " ");

    srand(time(NULL));
    int n, m, AllCountSteps, countFoxes, countRabbits, x, y, direction, stability;
    Model model;

    n = atoi(token);
    token = strtok(NULL, " ");
    m = atoi(token);
    token = strtok(NULL, " ");
    AllCountSteps = atoi(token);
    model.set_n(n);
    model.set_m(m);
    model.set_field();

    fin.getline(str, 50);
    token = strtok(str, " ");
    countRabbits = atoi(token);
    token = strtok(NULL, " ");
    countFoxes = atoi(token);

    for (int i = 0; i < countRabbits; i++)
    {
        fin.getline(str, 50);
        token = strtok(str, " ");
        x = atoi(token);
        token = strtok(NULL, " ");
        y = atoi(token);
        token = strtok(NULL, " ");
        direction = atoi(token);
        token = strtok(NULL, " ");
        stability = atoi(token);
        Rabbit *rabbit = new Rabbit(x, y, direction, stability);
        model.set_rabbit(rabbit);
    }

    for (int i = 0; i < countFoxes; i++)
    {
        fin.getline(str, 50);
        token = strtok(str, " ");
        x = atoi(token);
        token = strtok(NULL, " ");
        y = atoi(token);
        token = strtok(NULL, " ");
        direction = atoi(token);
        token = strtok(NULL, " ");
        stability = atoi(token);
        Fox *fox = new Fox(x, y, direction, stability);
        model.set_fox(fox);
    }
    for (int i = 0; i < AllCountSteps; i++)
    {
        ofstream inf(argv[2]);
        std::cout << "\x1B[2J\x1B[H";
        model.printModel(inf);
        cout << "n: " << Model::n << endl;
        cout << "m: " << Model::m << endl;
        cout << "Count foxes: " << model.get_countFoxes() << endl;
        model.newStep();
        inf.close();
        sleep(1);
    }
    fin.close();
    return 0;
}