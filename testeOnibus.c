#include <stdio.h>
#include <utils.h>
#include <dadosOnibus.h>

//Arquivo para testar a biblioteca dadosOnibus.h
//Esse programa pede uma linha e imprime todas as ordens de onibus circulando naquela linha

int main (void){

	int bus_count;
	int t_sec;
	char** ordemVector;
	char linha[8];
	Matrix mx;


    printf("Digite numero de linhas a ser consultada: ");
	fflush(stdin);
	scanf("%d",&bus_count);
	printf("\n");
	fflush(stdin);


    printf("Digite o tempo de monitoramento [segundos]: ");
	fflush(stdin);
	scanf("%d",&t_sec);
	printf("\n");
	fflush(stdin);

	char linhaArray[bus_count][8];
	ordemVector = ordem_vector(bus_count, linhaArray);

	matrix_constructor(&mx, bus_count, t_sec);
	populate_matrix_speed(&mx, linhaArray, bus_count, t_sec);
	printf("\n");

	for(int i = 0 ; i < bus_count ; i++)
    {
		printf("%s: ", ordemVector[i]);
        for (int j = 0; j < t_sec; j++)
        {
            printf("%lf ", mx.matrix[i][j]);
        }
		printf("\n");
    }

	// char linha[8];
	// float velocidade;
	// double latitude;
	// double longitude;
	
	// Onibus* lista;
	
	// printf("Digite linha a ser consultada\n");
	// fflush(stdin);
	// scanf("%7[^\n]",linha);


	// lista = infoLinha(linha);
	// imprimeListaOnibusApenasOrdem(lista);

	// int i;
    // for (i = 0; i < 10; i++) {
    //     // delay of one second
    //     delay(1);
    //     printf("%d seconds have passed\n", i + 1);
    // }

	return 0;		
}
