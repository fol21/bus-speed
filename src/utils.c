#include <stdio.h>
#include <utils.h>


void delay(int seconds)
{ 
    // Stroing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + seconds*CLOCKS_PER_SEC);
}

void matrix_constructor(Matrix* mx, int row, int col)
{
    mx->row = row;
    mx->col = col;
    mx->matrix = (double**) malloc(row*sizeof(double*));
    for (int i=0; i<row; i++)
        mx->matrix[i] = (double*) malloc(col*sizeof(double));
}

char** ordem_vector(int bcount, int time)
{
	char** ordemVector = (char**)malloc(bcount*sizeof(char*));
    char linha[8];
    Onibus* lista;

	for(int i=0; i < bcount; i++)
	{
	    printf("Digite linha a ser consultada\n");
	    fflush(stdin);
	    scanf("%7[^\n]",linha);

        lista = infoLinha(linha);
		ordemVector[i] = (char*)malloc(8*sizeof(char));
        ordemVector[i] = lista->ordem;
	}
    return ordemVector;
}



