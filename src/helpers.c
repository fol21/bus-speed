#include <stdio.h>
#include <helpers.h>


void delay(int seconds)
{ 
    // Stroing start time
    // clock_t start_time = clock();
 
    // // looping till required time is not achieved
    // while (clock() < start_time + seconds*CLOCKS_PER_SEC);
    usleep(seconds*1000000);
}

void matrix_constructor(Matrix* mx, int row, int col)
{
    mx->row = row;
    mx->col = col;
    mx->matrix = (double**) malloc(row*sizeof(double*));
    for (int i=0; i<row; i++)
        mx->matrix[i] = (double*) malloc(col*sizeof(double));
}

void populate_matrix_speed(Matrix* mx, char** linhas, int bus_count, int time)
{
    for(int i = 0 ; i < time ; i++)
    {
        for (int j = 0; j < bus_count; j++)
        {
            mx->matrix[j][i] = infoLinha(linhas[j])->velocidade;
        }
        delay(1);
    }
}

char* topSpeedOrdemSpeed(Matrix* mx, char** ordemVector, double* topSpeed)
{
    int index = 0;
    *topSpeed = 0;
    double avgs[mx->row];
    for(int i= 0 ; i < mx->row ; i++)
    {
        avgs[i] = 0;
        for(int j = 0; j < mx->col;j++)
        {
            avgs[i] += mx->matrix[i][j];   
        }
        avgs[i] = avgs[i]/mx->col; // Faz a média
        if(avgs[i] > *topSpeed) // Compara as Médias
        {
            *topSpeed = avgs[i];
            index = i;
        }
    }
    return ordemVector[index];
}

char** ordem_vector(int bcount)
{
	char** ordemVector = (char**)malloc(bcount*sizeof(char*));
    char linha[8];
    Onibus* lista;

	for(int i=0; i < bcount; i++)
	{
	    printf("Digite a ordem do ônibus a ser consultado\n");
	    fflush(stdin);
	    scanf("%s",linha);
        fflush(stdin);

        lista = infoLinha(linha);
		ordemVector[i] = (char*)malloc(8*sizeof(char));
        ordemVector[i] = lista->ordem;
        
	}
    return ordemVector;
}



