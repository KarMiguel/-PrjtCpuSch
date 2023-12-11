#include <stdlib.h>
#include <stdio.h>
#include "escalonador.h"

void testaFCFS(int numProcessos){
	// cria a fila de prontos
	Tlista *filaProntos = criaLista();

	//if (numProcessos > 0){
		for (int i = 0 ; i < numProcessos;i++){
			TProcesso *p = (TProcesso *) criarProcesso();
			// insere o processo pi no início da fila de prontos
    		if (i == 0)
				insereInicio(filaProntos,p);
			else
				insereFinal(*filaProntos,p);

		}
		// imprime os processos da fila de proontos
		imprimeLista(*filaProntos);
		// chama o escalonador FCFS
		primeiroChegarPrimeiroServido(*filaProntos);
	//}
}

void testaRoundRobin(int numProcessos, int quantum) {
    Tlista *filaProntos = criaLista();

    for (int i = 0; i < numProcessos; i++) {
        TProcesso *p = (TProcesso *) criarProcesso();
        // insere o processo pi no início da fila de prontos
        if (i == 0) {
            insereInicio(filaProntos, p);
        } else {
            insereFinal(*filaProntos, p);
        }
    }

    // imprime os processos da fila de prontos
    imprimeLista(*filaProntos);
    // chama o escalonador RR
    roundRobin(*filaProntos, quantum);
}

void testaJobMenor(int numProcessos) {
    Tlista *filaProntos = criaLista();

    for (int i = 0; i < numProcessos; i++) {
        TProcesso *p = (TProcesso *) criarProcesso();
            if (i == 0)
                insereInicio(filaProntos,p);
            else
                insereFinal(*filaProntos,p);
   }
    // Ordena a lista de processos pelo tempo de execução

    // Imprime os processos da fila de prontos
    imprimeLista(*filaProntos);

        jobMenorPrimeiro(*filaProntos);
}


void testaFilaPrioridades(int numProcessos){
	Tlista *filaPrioridades[5];

	for (int i = 0; i < 5 ; i++){
		filaPrioridades[i] = criaLista();
	}
	for (int i = 0 ; i < numProcessos;i++){
		TProcesso *p = (TProcesso *) criarProcesso();
		// insere o processo p no início da fila de prontos
    	if (isVazia(filaPrioridades[p->prioridade -1]))
			insereInicio(filaPrioridades[p->prioridade -1],p);
		else
			insereFinal(*filaPrioridades[p->prioridade -1],p);
	}
	// imprime os processos da fila de prioridades 0
	for (int i = 0; i < 5 ; i++){
		if (!isVazia(filaPrioridades[i]))
			// chama o escalonador FCFS
			primeiroChegarPrimeiroServido(*filaPrioridades[i]);
	}

}

int main (int argc, char *argv[]){

    int algoritmo, quantum;

        printf("\n=====================================================\n");
        printf("==============BEM VINDO AO CPU SCHULER===============\n");
        printf("=====================================================\n\n");
        printf("\t1 - FCFS\n");
        printf("\t2 - ROUND ROBIN\n");
        printf("\t3 - FILA DE PRIORIDADE\n");
        printf("\t4 - JOB MENOR\n");
        printf("\t5 - Sair\n");
        printf("\n====================================================\n");
        printf("ESCOLHA UM ALGORITMO :");
        scanf("%d",&algoritmo);

        int numProcessos;
            if((algoritmo == 1) || (algoritmo == 2) || (algoritmo == 3)||(algoritmo ==4 ) ){
                printf("Quantidade de Processos:");
                scanf("%d",&numProcessos);
            }
        switch(algoritmo){
            case 1:
                testaFCFS(numProcessos);
            break;
            case 2:
                printf("Informe a qtd do quantum:");
                scanf("%d",&quantum);
                testaRoundRobin(numProcessos, quantum);
            break;
            case 3:
                testaFilaPrioridades(numProcessos);
            break;
            case 4:
                testaJobMenor(numProcessos);
            break;
            case 5:
                printf("\n\tSaindo ...\n");
            break;
            default:
                printf("Opcao Invalida.");
            break;
        }

	return 0;
}
