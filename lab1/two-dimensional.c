#include <stdio.h>
#include <stdlib.h>
int **genRandMatrix(int size, int maxValue)
{
    int **matrix = malloc(sizeof(int *) * size);
    // int *newArr = malloc(sizeof(int) * (size + 1));
    int sizeNewArr;
    for (int i = 0; i < size; i++)
    {
        sizeNewArr = rand() % 10;
        matrix[i] = malloc(sizeof(int) * (sizeNewArr + 1));
        matrix[i][0] = sizeNewArr;
        for (int j = 1; j < sizeNewArr + 1; j++)
        {
            matrix[i][j] = rand() % maxValue;
        }
    }
    return matrix;
}
void printMatrix(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int size = arr[i][0];
        printf("%d: ", size);
        for (int j = 1; j < size; j++)
        {
            printf("%d, ", arr[i][j]);
        }
        printf("%d\n", arr[i][size]);
    }
}
int main()
{
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int **matrix = genRandMatrix(size, maxValue);
    printf("Size matrix: %d\n", size);
    printMatrix(matrix, size);
    free(matrix);
}