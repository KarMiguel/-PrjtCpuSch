#ifndef _PROCESSO_
#define _PROCESSO_

typedef enum{
    pronto, executando, bloqueado,finalizado
}TEstado;
// P = pronto, E = Executando, B = Bloqueado, F = Finalizado

typedef struct processo{
    int id;
    int tempoExec; // quantidade de tempo de CPU que o processo já usou
    int tempoCpu; // quantidade de tempo que o processo precisa usar a CPU
    int prioridade;
    TEstado estado;

}TProcesso;

static unsigned int contProcessos = 0;

TProcesso * criarProcesso();
void imprimeDadosProcesso(TProcesso p);
void liberarMemoriaProcesso(TProcesso *p);

#endif
