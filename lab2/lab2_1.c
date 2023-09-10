#include <stdio.h>
#include <stdlib.h>
int **genRandMatrix(int n, int maxValue)
{
    int **matrix = malloc(sizeof(int *) * n);
    int sizeNewArr;
    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(sizeof(int) * (n + 1));
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % maxValue;
        }
    }
    return matrix;
}
void printMatrix(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            printf("%d, ", arr[i][j]);
        }
        printf("%d\n", arr[i][n - 1]);
    }
}
int *fromMatrixToArr(int **matrix, int n)
{
    int size = n * n;
    int *newArr = malloc(sizeof(int) * size);

    int DownBorder = n - 1;
    int RightBorder = n - 1;
    int UpBorder = 0;
    int LeftBorder = 0;

    // Переменные счетчики используемые в расчетах
    int i = 0; // Координары строки
    int j = 0; // Координаты столбца

    for (int k = 0; k < n; k++)
    {
        for (int m = 0; m < n; m++)
        {
            if (k * n + m == (n - 1) * 4 - 1) // прошел круг, нужно срезать рамки
            {
                DownBorder--;
                RightBorder--;
                UpBorder++;
                LeftBorder++;
            }
            newArr[i * n + j] = matrix[k][m];
            if (i == UpBorder && j < RightBorder)
                j++;
            else if (j == RightBorder && i < DownBorder)
                i++;
            else if (i == DownBorder && j > LeftBorder)
                j--;
            else if (j == LeftBorder && i > UpBorder)
                i--;
        }
    }
    return newArr;
}
void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d,", arr[i * n + j]);
        }
        printf("\n");
    }
}
int main()
{
    srand(time(NULL));
    int n = 0;
    int maxValue = 100;
    puts("Введите размер квадратной матрицы");
    scanf("%d", &n);
    int **matrix = genRandMatrix(n, maxValue);
    printf("Size matrix: %d\n", n);
    printMatrix(matrix, n);

    printf("---------------------------\n");
    int *arr = fromMatrixToArr(matrix, n);
    printArr(arr, n);

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    free(arr);
}