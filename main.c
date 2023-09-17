//
//  main.c
//  OOP_lab2.2
//
//  Created by Илья Сухаренко on 17.09.2023.
// Создать двумерный динамический массив с произвольным количеством элементов в каждой сроке. Заполнить его и распечатать построчно.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRows, maxNumElements;

    printf("Введите количество строк: ");
    scanf("%d", &numRows);

    printf("Введите максимальное количество элементов в строке: ");
    scanf("%d", &maxNumElements);

    int** array = (int**)malloc(numRows * sizeof(int*));

    srand(time(NULL));

    for (int i = 0; i < numRows; i++) {
        int numElements = rand() % maxNumElements + 1;
        
        array[i] = (int*)malloc(numElements * sizeof(int));

        
        for (int j = 0; j < numElements; j++) {
            array[i][j] = rand() % 100;
        }

        
        for (int j = 0; j < numElements; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numRows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
