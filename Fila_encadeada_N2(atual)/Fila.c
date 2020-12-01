#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila.h"

No *criaNo()
{
    No *no = NULL;
    no = (No *)malloc(sizeof(No));
    if (no == NULL)
    {
        return NULL;
    }
    return no;
}

No *enfileirar(No *no, char *nome)
{
    No *novoNo;
    No *atual;
    if (vazia(no))
    {
        int maxLength;
        printf("\nDigite o tamanho da fila...");
        scanf("%d", &maxLength);

        novoNo = criaNo();
        novoNo->capacidade = maxLength;
        novoNo->nome = nome;
        novoNo->primeiro = novoNo;
        novoNo->atras = NULL;
        novoNo->frente = NULL;
        novoNo->cont++;
        return novoNo;
    }
    else
    {
        atual = no;
        novoNo->nome = (char *)malloc(sizeof(char));
        novoNo->nome = nome;
        if (!cheia(no))
        {
            while (atual->atras != NULL)
            {
                atual = atual->atras;
            }
            atual->atras = novoNo;
            novoNo->frente = atual;
            atual->cont++;

            return novoNo;
        }
        else
        {
            printf("\nA fila esta cheia...\n");
            return novoNo;
        }
    }
}

No *desenfileira(No *no)
{
    No *atualNo = no;
    if (vazia(no))
    {
        printf("\nA fila esta vazia...\n");
        return NULL;
    }

    while (atualNo->frente->frente != NULL)
    {
        atualNo = atualNo->frente;
    }

    printf("\nPaciente %s excluido da fila...", atualNo->frente->nome);
    atualNo->cont--;
    atualNo->frente = NULL;

    return atualNo;
}

bool esvazia(No *no)
{
    No *atualNo = no;
    if (vazia(atualNo))
    {
        printf("\nA fila ja esta vazia...\n");
        return true;
    }

    while (atualNo->frente != NULL)
    {
        atualNo = atualNo->frente;
        atualNo->cont--;
    }
    if (vazia(atualNo))
    {
        free(atualNo);
        free(no);
        return true;
    }
    else
    {
        return false;
    }
}

char *primeiro(No *no)
{
    if (vazia(no))
    {
        printf("\nNao ha ninguem na No! ");
    }
    return no->primeiro->nome;
}

bool vazia(No *no)
{
    if (no != NULL)
    {
        if (no->cont == 0)
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
        printf("\nNao existe No!\n");
        return true;
    }
}

bool cheia(No *no)
{
    if (no != NULL)
    {
        if (no->capacidade == no->cont)
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
        printf("\nNao existe No!\n");
        return true;
    }
}

void imprimir(No *no)
{
    No *atualNo = no;
    if (vazia(no))
    {
        printf("\nA fila esta vazia...\n");
    }
    else
    {

        while (atualNo->frente != NULL)
        {
            printf("-> %s ", atualNo->frente->nome);
            atualNo = atualNo->frente;
        }
        /* while (atualNo->frente != NULL)
        {
            atualNo = atualNo->frente;
            printf("-> %s ", atualNo->nome);
        } */
    }
}
