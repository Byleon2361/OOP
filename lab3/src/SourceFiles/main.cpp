#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include "Fox.h"
#include "Rabbit.h"
#include "Model.h"
using namespace std;
int main(int argc, char *argv[])
{   
    if (argc != 2){
        printf("The number of arguments passed must be one\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    printf("%s\n", argv[1]);
    char *str, *token;

    if (!fp){
        printf("не удалось открыть файл\n");
        return 1;
    }

    fgets(str, 123, fp);
    token = strtok(str, " ");

    srand(time(NULL));
    int n, m, AllCountSteps, countFoxes, countRabbits, x, y;
    Model model;
    n = atoi(token); token = strtok(NULL, " ");

    m = atoi(token); token = strtok(NULL, " ");
    AllCountSteps = atoi(token);
    model.set_n(n);
    model.set_m(m);
    model.set_field();

    fgets(str, 123, fp);
    token = strtok(str, " ");   
    countRabbits = atoi(token); token = strtok(NULL, " ");
    countFoxes = atoi(token);
    
    for (int i = 0; i < countRabbits; i++)
    {
        fgets(str, 123, fp);
        token = strtok(str, " "); 
        x = atoi(token); token = strtok(NULL, " ");
        y = atoi(token);
        Rabbit *rabbit = new Rabbit(x, y);
        model.set_rabbit(rabbit);
    }

    for (int i = 0; i < countFoxes; i++)
    {
        fgets(str, 123, fp);
        token = strtok(str, " "); 
        x = atoi(token); token = strtok(NULL, " ");
        y = atoi(token);
        Fox *fox = new Fox(x, y);
        model.set_fox(fox);
    }
    for (int i = 0; i < AllCountSteps; i++)
    {
        std::cout << "\x1B[2J\x1B[H"; // типа выводит "clear" в bash
        model.printModel();
        cout << "n: " << Model::n << endl;
        cout << "m: " << Model::m << endl;
        cout << "Count foxes: " << model.get_countFoxes() << endl;
        model.newStep();
        sleep(1);
    }
    return 0;
}