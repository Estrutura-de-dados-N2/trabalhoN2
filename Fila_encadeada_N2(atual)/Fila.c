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
        no->atras = NULL;      
        printf("\nNo criado");
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
        fila->cont = 0;

        printf("\nA fila foi criada!\n");
    }
    return fila;
}

Fila *enfileirar(Fila *f, No *novoNo)
{
    int auxCont = f->cont;
    if (vazia(f))
    {
        f->primeiro = novoNo;
        f->cont++;
        return f;
    }

    if (cheia(f))
    {
        printf("\nA fila esta cheia!\n");
        return f;
    }

    do
    {
        if (novoNo->atras == NULL)
        {
            novoNo->atras = novoNo;
            f->cont++;
            return f;
        }
        auxCont--;
        printf("\n XXXXXXXX %s", novoNo->nome);
    } while (auxCont >= 0);

    return f;
}

Fila *desenfileira(Fila *f)
{
    if (vazia(f))
    {
        printf("\nA fila esta vazia! \n");
        return f;
    }
    free(f->primeiro);
    f->primeiro = f->atras;
    f->cont--;
    return f;
}

Fila *esvazia(Fila *f)
{
    if (vazia(f))
    {
        return f;
    }

    do
    {
        free(f->atras);
    } while (f->atras != NULL);

    if (vazia(f))
    {
        printf("\nFila esvaziada com sucesso! ");
    }
    else
    {
        printf("\nErro ao esvaziar a fila! ");
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
            printf("\n>>>>>> %d\n", f->cont);
            return false;
        }
    }
    else
    {
        printf("\nNao existe fila!\n");
        return 1;
    }
}

void imprimir(Fila *f)
{

    if (!vazia(f))
    {
        printf("\nA fila esta assim:\n");

        while (f->atras != NULL)
        {
            printf("-> %s ", f->atras->nome);
        }
    }
    else
    {
        printf("\nA fila est� vazia! ");
    }
}
