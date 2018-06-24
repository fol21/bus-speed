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
void matrix_constructor(Matrix* mx, int row, int col);
char** ordem_vector(int bcount, int time);
double** bus_speed_grid(int bcount, int time);

#endif // !UTILS_H
