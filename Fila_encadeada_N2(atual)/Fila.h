#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct paciente
{
    char *nome;
} No;

typedef struct fila
{
    No *primeiro;
    No *frente;    
    No *atras;
    int cont;
    int capacidade;
} Fila;

/* No *criaNo(char *nome); */

Fila *criaFila(int maxLength);

Fila *enfileirar (Fila *f, char *nome);

Fila *desenfileira (Fila *f);

Fila *esvazia (Fila *f);

char *primeiro (Fila *f);

bool vazia (Fila *f);

bool cheia (Fila *f);

void imprimir (Fila *f);





