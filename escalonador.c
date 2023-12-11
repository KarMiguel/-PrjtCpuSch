#include <time.h>
#include "escalonador.h"
#include "listaencadeada.h"
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void primeiroChegarPrimeiroServido(Tlista L){
	No * paux = L;
	//while (!isVazia(&L)){
	while (paux !=NULL){
		TProcesso *p = paux->info;
		p->estado = executando;

		while (p->tempoCpu > p->tempoExec){
			cpuExecuta(p,1);
			imprimeLista(L);
		}
		p->estado = finalizado;
		paux = paux->prox;
		imprimeLista(L);
		//removeInicio(&L);
	}
}



bool isFinalizado(Tlista L) {
    No* paux = L;
    while (paux != NULL) {
        TProcesso* p = paux->info;
        if (p->estado != finalizado) {
            return false;  // Return false when an unfinished process is found
        }
        paux = paux->prox;
    }
    return true;  // Return true if all processes are finished
}

void roundRobin(Tlista L, int quantum) {
    while (!isFinalizado(L)) {
        No* paux = L;
        while (paux != NULL) {
            TProcesso* p = paux->info;
            p->estado = executando;
            int resto = p->tempoCpu - p->tempoExec;
            if (resto > quantum) {
                cpuExecuta(p, quantum);
            } else {
                cpuExecuta(p, resto);
                p->estado = finalizado;
            }
            paux = paux->prox;  // Move this line inside the inner loop
            imprimeLista(L);
            //removeInicio(L);
        }
    }
}

// Simula a execução do processo na CPU
void cpuExecuta(TProcesso * p, int quantum){
    // aguarda 1 quantum de segundos;
    delay(quantum);
    // incrementa o tempo de execução em 1 qunatum
    p->tempoExec+= quantum;
}


/*

bool isFinalizado (Tlista L){
    No * paux =L;
    while(isVazia(&L)){
        No * paux =L;
        TProcesso* p = paux->info;
            if(p->estado != finalizado){
                return true;
            }
    }
    return false;
}

void roundRobin(Tlista L, int quantum){

    while(isFinalizado(L)){
        No * paux =L;
	while (paux !=NULL){
		TProcesso *p = paux->info;
		p->estado = executando;
		int resto=p->tempoCpu - p->tempoExec;
		if (resto > quantum){
            cpuExecuta(p,quantum);
		}else{
            cpuExecuta(p, resto);
            p->estado = finalizado;
        }
        while (p->tempoCpu > p->tempoExec){
			cpuExecuta(p,quantum);
			imprimeLista(L);
		}
		p->estado = finalizado;
		paux = paux->prox;
		imprimeLista(L);
		//removeInicio(&L);
	}
    }
}

*/
void jobMenorPrimeiro(Tlista L){
    // Ordena a lista de acordo com o tempo de execução dos processos em ordem crescente
  ordenaPorTempoCpu(L);

    No* paux = L;
    while (paux != NULL)
    {
        TProcesso* p = paux->info;
        p->estado = executando;

        while (p->tempoCpu > p->tempoExec)
        {
            cpuExecuta(p, 1);
            imprimeLista(L);
        }

        p->estado = finalizado;
        paux = paux->prox;
        imprimeLista(L);
    }

}

void ordenaPorTempoCpu(Tlista L) {
    int troca;
    No* atual;
    No* seguinte = NULL;

    if (L == NULL)
        return;

    do {
        troca = 0;
        atual = L;

        while (atual->prox != seguinte) {
            TProcesso* pAtual = atual->info;
            TProcesso* pProximo = atual->prox->info;

            if (pAtual->tempoCpu > pProximo->tempoCpu) {
                troca = 1;
                atual->info = pProximo;
                atual->prox->info = pAtual;
            }

            atual = atual->prox;
        }

        seguinte = atual;
    } while (troca);
}
