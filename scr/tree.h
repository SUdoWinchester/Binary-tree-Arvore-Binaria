#ifndef TREE_H
#define TREE_H

typedef struct Treeno{
	int value;
	struct Treeno *Llink;
	struct Treeno *Rlink;
} no;

no *create_node(int x);

int insert(no **T, int x);

no *search(no **T, int x);

void emOrdem(no *T);

void preOrdem(no *T);

void posOrdem(no *T);

int altura (no *T);

void printFolhas(no *T);

void destroy(no **T);

int countNo(no *T);

no *menorValor(no **T);

no *maiorValor(no **T);

int nivelNo(no **T, int num);

int removeNo(no **T, int x);

void bft(no *T, int **vet);

#endif