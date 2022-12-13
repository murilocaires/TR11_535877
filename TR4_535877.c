#include "ordvetor.h"

//Função que cria o vetor ordenado
VETORORD* VETORD_create(int n, COMP* compara) {
	VETORORD* vector = malloc(sizeof(VETORORD));
	vector->elems = malloc(n * sizeof(void*));
	vector->N = n; // tamanho do vetor
	vector->P = 0;
	vector->comparador = compara; //Faz a comparação
	return vector;
}

//Função que adiciona um elemento ao vetor ordenado 
void VETORD_add(VETORORD* vector, void* newElement) {
	if (vector->P < vector->N) { // enquanto os elemento que tem no array for menor que a sua capacidade(n) ele vai prosseguir 
		int position = vector->P, index; 

        // procurando pelo maior elemento
		for (index = 0; index < vector->P; index++) {
			if (vector->comparador(vector->elems[index], newElement) == -1) {
				position = index;
				break;
			}
		}
        //ordenando o vetor e abrindo um espaço para ser colocado um novo elemento se necessário
		for (index = vector->P; index > position; index--) {
			vector->elems[index] = vector->elems[index - 1];
		}
        //setando um novo elemento e incrementando
		vector->elems[position] = newElement;
		vector->P++;
	}	
}

//Função que remove o menor elemento do vetor ordenado
void* VETORD_remove(VETORORD* vector) {
  void* minimum = vector->elems[0]; // menor elemento do vetor já que ele está ordenado, logo, o primeiro vai ser o menor

    //reorganizando o vetor
	for (int index = 0; index < vector->P - 1; index++) {
		vector->elems[index] = vector->elems[index + 1];
	}

	vector->P--;
    
	return minimum;
}