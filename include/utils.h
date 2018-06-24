#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dadosOnibus.h>

typedef struct Matrix
{
    int row;
    int col;
    double** matrix;

} Matrix;

void delay(int seconds);


#endif // !UTILS_H
