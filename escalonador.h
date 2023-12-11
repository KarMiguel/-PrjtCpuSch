#ifndef _ESCALONADOR_
#define _ESCALONADOR_

#include "listaencadeada.h"
	// Algoritmos de escalonamento
	// fcfs
	void primeiroChegarPrimeiroServido(Tlista L);
	//jsf
	void jobMenorPrimeiro(Tlista L);
    void ordenaPorTempoCpu(Tlista L) ;
	//rr
	void roundRobin(Tlista L, int quantum);
	//fp
	void filaPrioridades(Tlista L);

	// Simula a execução do processo p
	void cpuExecuta(TProcesso * p, int quantum);

#endif
