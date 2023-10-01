#pragma once
#include <vector>
#include "Fox.h"
#include "Rabbit.h"
using std::vector;
class Model
{
public:
    ~Model();
    static int n;
    static int m;
    void printModel(ofstream &inf);
    void newStep();
    void freeMemory();

private:
    vector<Fox *> masF;
    vector<Rabbit *> masR;
    int **field;

public:
    // геттеры и сеттеры
    int get_countFoxes() const { return masF.size(); }
    int get_countRabbits() const { return masR.size(); }
    void set_field();
    void set_rabbit(Rabbit *rabbit);
    void set_fox(Fox *fox);
    void set_n(int n) { this->n = n; }
    void set_m(int m) { this->m = m; }
};