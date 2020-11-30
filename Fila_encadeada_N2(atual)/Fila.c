#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila.h"

No *criaNo(char *nome)
{
    No *no = (No *)malloc(15 * sizeof(No));

    if (no != NULL)
    {
        no->nome = nome;
        printf("\nNo criado...");
    }
    return no;
}

Fila *criaFila(int maxLength)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila != NULL)
    {
        fila->capacidade = maxLength;
        fila->primeiro = NULL;
        fila->frente = NULL;
        fila->atras = NULL;
        fila->cont = 0;

        printf("\nA fila foi criada...\n");
    }
    return fila;
}

Fila *enfileirar(Fila *f, char *nome)
{
    No *novoNo = criaNo(nome);
    Fila *aux = f;

    if (vazia(f))
    {
        f->primeiro = novoNo;
        f->cont++;
        return f;
    }

    if (cheia(f))
    {
        printf("\nA fila esta cheia...\n");
        return f;
    }

    while (aux->atras != NULL)
    {
        aux->atras = f->atras;
    }
    aux->atras = novoNo;
    f->cont++;

    return aux;
}

Fila *desenfileira(Fila *f)
{
    Fila *aux = f;
    if (vazia(f))
    {
        printf("\nA fila esta vazia...\n");
        return f;
    }

    while (aux->frente != NULL)
    {
        aux->frente = f->frente;
    }

    if (aux->frente == f->primeiro)
    {
        free(aux);
        f->primeiro = f->atras;
        f->cont--;
    }
    else
    {
        printf("\nErro ao buscar o primeiro da fila...\n");
    }

    return f;
}

Fila *esvazia(Fila *f)
{
    Fila *aux = f;
    if (vazia(f))
    {
        printf("\nA fila esta vazia...\n");
        return f;
    }

    while (aux->frente != NULL)
    {
        aux->frente = f->frente;
        f->cont--;
        free(f->frente);
        free(f->atras);
    }
    free(aux);
    free(f->primeiro);
    free(f);

    if (vazia(f))
    {
        printf("\nA fila foi esvaziada com sucesso...\n");
    }
    return f;
}

char *primeiro(Fila *f)
{
    if (vazia(f))
    {
        printf("\nNao ha ninguem na fila! ");
    }
    return f->primeiro->nome;
}

bool vazia(Fila *f)
{
    if (f != NULL)
    {
        if (f->cont == 0)
            return true;
        return false;
    }
    else
    {
        printf("\nNao existe fila!\n");
        return true;
    }
}

bool cheia(Fila *f)
{
    if (f != NULL)
    {
        if (f->capacidade == f->cont)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        printf("\nNao existe fila!\n");
        return true;
    }
}

void imprimir(Fila *f)
{
    Fila *aux = f;
    if (vazia(f))
    {
        printf("\nA fila esta vazia...\n");
    }
    else
    {
        while (aux->frente != NULL)
        {
            aux->frente = f->frente;
            printf("-> %s", aux->frente->nome);
        }
    }
}
