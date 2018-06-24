#include <utils.h>


void delay(int seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * seconds;
 
    // Stroing start time
    clock_t start_time = clock();
 
    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}

void matrix_constructor(Matrix* mx, int row, int col)
{
    mx->row = row;
    mx->col = col;
    mx->matrix = (double**) malloc(row*sizeof(double*));
    for (int i=0; i<row; i++)
        mx->matrix[i] = (double*) malloc(col*sizeof(double));
}


