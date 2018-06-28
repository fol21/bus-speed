#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <time.h>

#include <dadosOnibus.h>

typedef struct Matrix
{
    int row;
    int col;
    double** matrix;

} Matrix;

void delay(int seconds);
void matrix_constructor(Matrix* mx, int row, int col);
void populate_matrix_speed(Matrix* mx, char** linhas, int bus_count, int time);
char* topSpeedOrdemSpeed(Matrix* mx, char** ordemVector, double *topSpeed);
char** ordem_vector(int bcount);

#endif // !UTILS_H
