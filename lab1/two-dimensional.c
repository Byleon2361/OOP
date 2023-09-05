#include <stdio.h>
#include <stdlib.h>
int *genRandMatrix(int size, int maxValue)
{
}
void printMatrix(int *arr)
{
}
int main()
{
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int **matrix = genRandArray(size, maxValue);
    print(matrix);
    free(matrix);
}