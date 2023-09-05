#include <stdio.h>
#include <stdlib.h>
int *genRandArray(int size, int maxValue)
{
    int *newArr = malloc(sizeof(int) * (size + 1));
    newArr[0] = size;
    for (int i = 1; i < size + 1; i++)
    {
        newArr[i] = rand() % maxValue;
    }
    return newArr;
}
void print(int *arr)
{
    int size = arr[0];
    printf("%d: ", size);
    for (int i = 1; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[size]);
}
int main()
{
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);
    print(arr);
    free(arr);
}