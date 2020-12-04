#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int tamanho);

int main(){
	// Definindo vari�veis
	int *vetor, tamanho;
	// Cria ponteiro vazio
	// Ponteiro armazena endere�o de mem�ria

	//lendo o tamanho do vetor pelo usuario
	printf("Digite o tamanho do vetor: \n");
	scanf("%d", &tamanho);

	//O ponteiro recebe o endere�o de mem�ria que foi alocado para o vetor;
	vetor = alocaVetor(tamanho);

	int j=0;

	for(int i=0; i<tamanho; i++){
		vetor[i] = j++;
	}
	printf("Posicoes no vetor: \n");
	for(int i=0; i<tamanho; i++){
		printf("%d\n", vetor[i]);
	}

	free(vetor);
	return 0;
}
int* alocaVetor(int tamanho){
	// Cria um ponteiro auxiliar
	int *aux;
	// Aloca��o din�mica de mem�ria
	// Reservar espa�o na memoria para as casas do vetor
	aux = (int*)malloc(tamanho*sizeof(int));
	// Retorna o ponteiro que aponta para a primeira posi��o de mem�ria do vetor alocado
	return aux;
}