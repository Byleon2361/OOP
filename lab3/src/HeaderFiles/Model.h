#pragma once
#include <vector>
#include "Fox.h"
#include "Rabbit.h"
using std::vector;
class Model
{
public:
private:
    vector<Fox> masF;
    vector<Rabbit> masR;
    int **mas;
    void printModel();
};