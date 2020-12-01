#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila
{
    char *nome;
    struct fila *primeiro;
    struct fila *frente;    
    struct fila *atras;
    int cont;
    int capacidade;
} No;

No *criaNo();

No *enfileirar (No *no, char *nome);

No *desenfileira (No *no);

char *primeiro (No *no);

bool esvazia (No *no);

bool vazia (No *no);

bool cheia (No *no);

void imprimir (No *no);





