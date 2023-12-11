#include <stdio.h>
#include <stdlib.h>
#include "processo.h"

const char *estados[] = {
"Pronto ",
"Executando  ",
"Bloqueado   ",
"Finalizado  "};

TProcesso * criarProcesso(){
    TProcesso *p = (TProcesso *) malloc(sizeof(TProcesso));
    if (p){
        printf("\nInsira os dados do processo %d\n",++contProcessos);
        printf("Tempo de CPU: ");
        scanf("%d",&p->tempoCpu);
        printf("Prioridade  : ");
        scanf("%d", &p->prioridade);
        p->id = contProcessos;
        p->tempoExec = 0;
        p->estado = pronto;
    }
    return p;
}

void imprimeDadosProcesso(TProcesso p){
	printf("%3d   |%7d     |%14s|%7d       |%7d %%\n",p.id,p.prioridade,estados[p.estado],p.tempoCpu,100*p.tempoExec/p.tempoCpu);
}
void liberarMemoriaProcesso(TProcesso *p){
	free(p);
}
