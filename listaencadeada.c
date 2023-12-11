#include <stdlib.h>
#include <stdio.h>
#include "listaencadeada.h"

Tlista * criaLista(){
	Tlista * L = (Tlista *) malloc (sizeof(Tlista)) ;
	*L = NULL;
	return L;
}
void destroiLista(Tlista *L){
	No * paux = *L;
}

void insereInicio(Tlista *L, TProcesso *info){
	
	No * novo = (No *) malloc(sizeof(No));
	
	novo->info = info;
	novo->prox = *L;
	*L = novo;
}

void insereFinal(Tlista L, TProcesso * info){
	No * novo = (No *) malloc(sizeof(No));
	novo->info = info;
	novo->prox = NULL;
	
	No * paux;
	paux = L;
	
	while (paux->prox != NULL)
		paux = paux->prox;
		
	paux->prox = novo;
}

void imprimeLista(Tlista L){
	if (!isVazia(&L)){
		system("cls");
		No * paux = L;
		printf("  ID  | Prioridade |    Estado    | Tempo CPU(s) | %% Executado \n");
	
		while (paux != NULL){
			imprimeDadosProcesso(*paux->info);
			paux = paux->prox;
		}
	} else{
		printf("Lista vazia!!\n");
	}
	
}

void removeInicio(Tlista *L){
	No * paux;
	paux = *L;
	
	*L = (*L)->prox;
	// lebera a memória do processo info
	liberarMemoriaProcesso(paux->info);
	// libera a memória do nó da lista
	free(paux);
}

void removeFinal(Tlista L){
	No * pant, * pprox;
	pprox = L;
	
	while (pprox->prox != NULL){
		pant = pprox;
		pprox = pprox->prox;
	}
	free(pprox);
	pant->prox = NULL;
}
bool isVazia(Tlista *L){
	return *L == NULL;
}