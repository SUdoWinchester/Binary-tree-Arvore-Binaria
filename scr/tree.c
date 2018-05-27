#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

no *create_node(int x){
    no *new_no = (no*)malloc(sizeof(no));
    new_no->value = x;
    new_no->Llink = NULL;
    new_no->Rlink = NULL;

    return new_no;
}

int insert(no **T, int x) {
    if (*T == NULL) {
        *T = (no *) malloc (sizeof(no));
        if (*T != NULL) {
            (*T)->value = x;
            (*T)->Llink = NULL;
            (*T)->Rlink = NULL;
        } else
            return 1;
    } else {
        if (x < (*T)->value)
            insert(&((*T)->Llink), x);
        else {
            if (x > (*T)->value)
                insert(&((*T)->Rlink), x);
            else
                return 2;
        }
        return 3;
    }
}

void emOrdem(no *T){
    if(T != NULL) {
        emOrdem(T->Llink);
        printf("%d\n", T->value);
        emOrdem(T->Rlink);
    }
}

void preOrdem(no *T){
    if(T != NULL) {
        printf("%d\n", T->value);
        preOrdem(T->Llink);
        preOrdem(T->Rlink);
    }
}

void posOrdem(no *T){
    if(T != NULL) {
        posOrdem(T->Llink);
        posOrdem(T->Rlink);
        printf("%d\n", T->value);
    }
}

void printFolhas(no *T) {
	if(T == NULL)
		return ;
	else {
		if(T->Llink == NULL && T->Rlink == NULL) {
			printf("%d\n", T->value);
		} else {
			printFolhas(T->Llink);
			printFolhas(T->Rlink);
		}
	}
}

int altura (no *T) {
   if (T == NULL) 
      return 0; // altura da árvore vazia
   else {
      int he = altura(T->Llink);
      int hd = altura(T->Rlink);
      if (he < hd) 
      	return hd + 1;
      else 
      	return he + 1;
   }
}

int countNo(no *T) {
	return (T != NULL) ? (countNo(T->Llink) + countNo(T->Rlink) + 1) : 0;
}

int nivelNo(no **T, int x) {
    if (search(&(*T), x)) {
        if ((*T)->value == x)
            return 0;
        else {
            if (x < (*T)->value)
                return (nivelNo(&(*T)->Llink, x)) + 1;
            else
                return (nivelNo(&(*T)->Rlink, x)) + 1;
        }
    } else {
        return -1;
    }
}

no *search(no **T, int valor){
    if(*T == NULL){
        return NULL;
    }
    if((*T)->value == valor){
        return *T;
    }
    else{
        if((*T)->value < valor){
            return search(&(*T)->Rlink, valor);
        }
        else{
            return search(&(*T)->Llink, valor);
        }
    }
}

no *menorValor(no **T) {
	if(*T == NULL)
		return NULL;

	if((*T)->Llink == NULL)
		return *T;
	else 
		return menorValor(&(*T)->Llink);
}

no *maiorValor(no **T) {
	if(*T == NULL)
		return NULL;
	
	if((*T)->Rlink == NULL)
		return *T;
	else 
		return maiorValor(&(*T)->Rlink);
}

void bft(no *T, int **vet) {
	if(T == NULL)
		return ;

	vet = malloc(2*sizeof(no));
	int n = countNo(T);
	int count = 1;
	*(vet[count]) = T;

	while(count <= countNo(T)) {
		*vet = (no *) realloc(*vet, sizeof(no));
		count++;
		if(*(vet[count/2])->Llink != NULL)
			*vet[count] = *(vet[count/2])->Llink;
		else
			*vet[count] = NULL;

		*vet = (no *) realloc(*vet, sizeof(no));
		count++;
		if(*(vet[count/2])->Rlink != NULL)
			*vet[count] = *(vet[count/2])->Rlink;
		else
			*vet[count] = NULL;
	}
}

int removeNo(no **T, int x) {
	no *p, *aux;
	
	if (*T == NULL) {
		return 0;
	} else {
		if (x < (*T)->value) 
			removeNo(&(*T)->Llink, x);
		else {
			if (x > (*T)->value) 
				removeNo(&(*T)->Rlink, x);
			else {
					if (((*T)->Llink == NULL) && ((*T)->Rlink == NULL)) {
						p = (*T);
						free(p);
						(*T) = NULL;
						return (1);
					}
				else {
						if ((*T)->Llink == NULL){ 
							p = (*T);
							(*T) = (*T)->Rlink;
							free(p);
							return (1);
						}
					else {
						if ((*T)->Rlink == NULL) {
							p = (*T);
							(*T) = (*T)->Llink;
							free((p));
							return (1);
						}
						else {
							p = maiorValor(&(*T)->Llink);
							(*T)->value = p->value;
							removeNo(&((*T)->Llink),p->value);
						}
					}
				}
			}
		}
	}
}

void destroy(no **T) {
	if((*T) != NULL) {
        destroy(&((*T)->Llink));
        destroy(&((*T)->Rlink));
        free(*T);
        *T = NULL;
    }
}