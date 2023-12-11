#ifndef _LISTA_ENCADEADA_
#define _LISTA_ENCADEADA_

#include "processo.h"

typedef struct No{
    TProcesso * info;
    struct No * prox;
} No;

typedef No * Tlista;

Tlista * criaLista();
void destroiLista(Tlista *L);
void insereInicio(Tlista * L, TProcesso *info);
void insereFinal(Tlista L, TProcesso *info);
void imprimeLista(Tlista L);

void removeInicio(Tlista *L);
void removeFinal(Tlista L);

bool isVazia(Tlista *L);


#endif
