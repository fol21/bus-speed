#include <stdio.h>
#include <unistd.h>
#include "dadosOnibus.h"


//Arquivo para testar a biblioteca dadosOnibus.h
//Esse programa pede uma linha e imprime todas as ordens de onibus circulando naquela linha

int main (void){
	char linha[8];
	float velocidade;
	double latitude;
	double longitude;
	
	Onibus* lista;
	
	printf("Digite linha a ser consultada\n");
	fflush(stdin);
	scanf("%7[^\n]",linha);


	//usleep(3*1000000);
	lista = infoLinha(linha);
	//imprimeListaOnibus(lista);
	imprimeListaOnibusApenasOrdem(lista);

	

	return 0;
			
}
