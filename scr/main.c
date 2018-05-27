#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void main() {
	int x;
	no *p;
	no *T = create_node(8);

	printf("Insert dos itens\n");
	insert(&T, 3);
	insert(&T, 10);
	insert(&T, 1);
	insert(&T, 6);
	insert(&T, 14);
	insert(&T, 4);
	insert(&T, 7);
	insert(&T, 13);

	printf("%d\n", countNo(T));
	int *vet;

	printf("\n\nEntre com o valor que vai ser buscado:\n");
	scanf("%d", &x);

	p = search(&T, x);

	if(p != NULL) 
		printf("Valor encontrado: %d\n", p->value);
	else
		printf("Valor nao encontrado\n");


	printf("Em Ordem:\n");
	emOrdem(T);
	printf("\n\n");
	printf("Pre-Ordem\n");
	preOrdem(T);
	printf("\n\n");
	printf("Pos-Ordem\n");
	posOrdem(T);

	printf("\n\nAltura da arvore = %d\n\n", altura(T));

	printf("Folhas:\n");
	printFolhas(T);

	printf("Numero de Nos = %d\n", countNo(T));

	p = menorValor(&T);
	printf("Menor Valor = %d\n", p->value);
	p = maiorValor(&T);
	printf("Maior Valor = %d\n", p->value);

	printf("\n\nEntre com o valor que deseja-se saber o nivel:\n");
	scanf("%d", &x);
	x = nivelNo(&T, x);
	printf("Esta no nivel %d\n", x);
	
	
	printf("Valor a ser removido:\n");
	scanf("%d", &x);
	removeNo(&T, x);
	emOrdem(T);

	printf("\n\nBFT\n");
	bft(T, &vet);
	for(int i = 1; i <= countNo(T); i++) {
		printf("%d\n", vet[i]->value);
	}

	printf("Destroy...\n");
	destroy(&T);
}	
