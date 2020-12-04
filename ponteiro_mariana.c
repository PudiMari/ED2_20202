#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int tamanho);

int main(){
	// Definindo variáveis
	int *vetor, tamanho;
	// Cria ponteiro vazio
	// Ponteiro armazena endereço de memória

	//lendo o tamanho do vetor pelo usuario
	printf("Digite o tamanho do vetor: \n");
	scanf("%d", &tamanho);

	//O ponteiro recebe o endereço de memória que foi alocado para o vetor;
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
	// Alocação dinâmica de memória
	// Reservar espaço na memoria para as casas do vetor
	aux = (int*)malloc(tamanho*sizeof(int));
	// Retorna o ponteiro que aponta para a primeira posição de memória do vetor alocado
	return aux;
}