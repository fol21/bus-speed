#include <stdio.h>
#include <stdlib.h>
#include <helpers.h>
#include <dadosOnibus.h>

//Arquivo para testar a biblioteca dadosOnibus.h
//Esse programa pede uma linha e imprime todas as ordens de onibus circulando naquela linha

int main (void){

	int bus_count;
	int t_sec;
	char** ordemVector;
	char linha[8];
	Matrix mx;
	int scan = 0;


    printf("Digite numero de onibûs a serem consultados: ");
	fflush(stdin);
	scan = scanf("%d",&bus_count);
	while (scan !=1)
	{
		printf("Escolha um numero inteiro !\n");
		while ((getchar()) != '\n'); // Limpa Input buffer
		scan = scanf("%d",&bus_count);
	}
	printf("\n");
	fflush(stdin);


    printf("Digite o tempo de monitoramento [segundos]: ");
	fflush(stdin);
	scan = scanf("%d",&t_sec);
	while (scan !=1)
	{
		printf("Escolha um numero inteiro !\n");
		while ((getchar()) != '\n');
		scan = scanf("%d",&t_sec);
	}
	printf("\n");
	fflush(stdin);
	
	
	//Popula Vetor de Ordems
	ordemVector = ordem_vector(bus_count);

	printf("\n");
	
	// Constri Matriz Ordem-Velocidades
	matrix_constructor(&mx, bus_count, t_sec);
	populate_matrix_speed(&mx, ordemVector, bus_count, t_sec);
	printf("\n");

	// Faz consultas por T segundos
	printf("[CONSULTAS]\n");
	for(int i = 0 ; i < bus_count ; i++)
    {
		printf("[%s]:[ ", ordemVector[i]);
        for (int j = 0; j < t_sec; j++)
        {
            printf("%lf km/h ", mx.matrix[i][j]);
        }
		printf("]\n");
    }

	// Informa Maior velocidade da Matriz
	printf("[TOP SPEED]\n");
	double speed = 0;
	char* o = topSpeedOrdemSpeed(&mx, ordemVector, &speed);
	char* l = ordemToLinha(o);
	printf("Linha com maior velodidade: %s -> %lf km/h \n", l ,speed);

	return 0;		
}
