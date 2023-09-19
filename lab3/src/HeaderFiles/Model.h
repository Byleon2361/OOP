#pragma once
#include <vector>
#include "Fox.h"
#include "Rabbit.h"
using std::vector;
class Model
{
private:
    Model();
    ~Model();
    vector<Fox> masF;
    vector<Rabbit> masR;
    int **mas;
    void printModel();
};