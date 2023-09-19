#include <stdio.h>
#include <stdlib.h>
int **genRandMatrix(int n, int maxValue)
{
    int **matrix = malloc(sizeof(int *) * n);
    int sizeNewArr;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(sizeof(int) * (n + 1));
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = a;
            a++;
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
    printf("---------------------------\n");
}
int *SpiralFromLeftAngle(int **matrix, int n)
{
    int size = n * n;
    int *newArr = malloc(sizeof(int) * size);

    int DownBorder = n - 1;
    int RightBorder = n - 1;
    int UpBorder = 0;
    int LeftBorder = 0;

    int i = 0; // Координары строки
    int j = 0; // Координаты столбца

    for (int k = 0; k < n; k++)
    {
        for (int m = 0; m < n; m++)
        {
            newArr[i * n + j] = matrix[k][m];
            if (i == UpBorder && j < RightBorder)
                j++;
            else if (j == RightBorder && i < DownBorder)
                i++;
            else if (i == DownBorder && j > LeftBorder)
                j--;
            else if (j == LeftBorder && i > UpBorder)
                i--;

            if ((i == UpBorder + 1) && (j == LeftBorder)) // прошел круг, нужно срезать рамки
            {
                DownBorder--;
                RightBorder--;
                UpBorder++;
                LeftBorder++;
            }
        }
    }
    return newArr;
}
int *SpiralFromCenter(int **matrix, int n)
{
    int size = n * n;
    int *newArr = malloc(sizeof(int) * size);

    int center;
    if (n % 2 == 0)
        center = n / 2 - 1;
    else
        center = n / 2;
    int DownBorder = center + 1;
    int RightBorder = center + 1;
    int UpBorder = center - 1;
    int LeftBorder = center - 1;

    int i = center; // Координары строки
    int j = center; // Координаты столбца

    for (int k = 0; k < n; k++)
    {
        for (int m = 0; m < n; m++)
        {
            newArr[i * n + j] = matrix[k][m];
            if (i == UpBorder + 1 && j < RightBorder)
                j++;
            else if (j == RightBorder && i < DownBorder)
                i++;
            else if (i == DownBorder && j > LeftBorder)
                j--;
            else if (j >= LeftBorder && i > UpBorder)
                i--;
            if ((i - 1 == UpBorder) && (j == LeftBorder)) // прошел круг, нужно увеличить рамки
            {
                DownBorder++;
                RightBorder++;
                UpBorder--;
                LeftBorder--;
            }
        }
    }
    return newArr;
}

int *LeftDiagonal(int **matrix, int n)
{
    int mi = 1, size = n * n, g = 0, key = 0, pr = 0, key2 = 0;
    int *newArr = malloc(sizeof(int) * size);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newArr[g] = matrix[i][j];

            if (!(pr < key))
            {
                if ((key2 == 0) && (key < n - 1))
                {
                    g += mi;
                    key++;
                    mi -= n - 1;
                }
                else
                {
                    if (key2 == 0)
                    {
                        mi += n - 1;
                    }
                    key2 = 1;
                    g += mi;
                    key--;
                    mi += n - 1;
                }
                pr = 0;
            }
            else
            {
                g += n - 1;
                pr++;
            }
        }
    }

    return newArr;
}

int *RightDiagonal(int **matrix, int n)
{
    int mi = -1, size = n * n, g = 4, key = 0, pr = 0, key2 = 0;
    int *newArr = malloc(sizeof(int) * size);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newArr[g] = matrix[i][j];

            if (!(pr < key))
            {
                if ((key2 == 0) && (key < n - 1))
                {
                    g += mi;
                    key++;
                    mi -= (n + 1);
                }
                else
                {
                    if (key2 == 0)
                    {
                        mi += (n + 1);
                    }
                    key2 = 1;
                    g += mi;
                    key--;
                    mi += (n + 1);
                }
                pr = 0;
            }
            else
            {
                g += (n + 1);
                pr++;
            }
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
    printf("---------------------------\n");
}

void printdi(int *arr, int n)
{
    int p = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", arr[p]);
            p++;
        }
        printf("\n");
    }
    printf("---------------------------\n");
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

    puts("SpiralFromLeftAngle\n");
    int *arr1 = SpiralFromLeftAngle(matrix, n);
    printArr(arr1, n);

    puts("SpiralFromCenter\n");
    int *arr2 = SpiralFromCenter(matrix, n);
    printArr(arr2, n);

    puts("LeftDiagonal\n");
    int *arr3 = LeftDiagonal(matrix, n);
    printArr(arr3, n);
    // printdi(arr3, n);

    puts("RightDiagonal\n");
    int *arr4 = RightDiagonal(matrix, n);
    printdi(arr4, n);

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
}