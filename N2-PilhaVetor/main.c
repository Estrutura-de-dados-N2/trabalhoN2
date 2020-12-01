#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define TRUE 1
#define FALSE 0

int main()
{
    pilha *cabeca = NULL;
    pilha *no_retirado = NULL;
    int opcao;
    int executar = TRUE;

    //menu

    printf("Biblioteca Pilha de Livros:\n");
    do
    {

        printf("\n\t1. Inserir elemento na Pilha:");
        printf("\n\t2. Retirar elemento na Pilha:");
        printf("\n\t3. Mostrar Livros da Pilha:");
        printf("\n\t4. Esvaziar a Pilha Toda:");

        printf("\n\n\t0. Sair do Progama:");

        printf("\n\n\tEscolha Sua Opcao: ");
        (void)scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            executar = FALSE;
            break;
        case 1: // inserir
            inserir_pilha(&cabeca);
            mostrar_pilha(cabeca);
            break;
        case 2://retirar
            no_retirado = retirar_pilha(&cabeca);
            if (no_retirado != NULL)
            {
                printf("\n\tLivros retirado:\n");
                printf("\t%d - %s\n", no_retirado->codigo, no_retirado->livro);
                free(no_retirado);
                no_retirado = NULL;
            }
            break;
        case 3://mostrar
            mostrar_pilha(cabeca);
            break;
        case 4:// esvaziar
            esvaziar_pilha(&cabeca);
            break;
        default:
            printf("\n\tOpcao invalida.");
            break;
        }

    }
    while (executar == TRUE);
    return 0;
}


pilha *novo_no()
{
    pilha *temp = (pilha *)malloc(sizeof(pilha));
    if (temp == NULL)
    {
        printf("\tFalta de memoria");
        exit(0);
    }
    printf("\n\tCodigo do Livro: ");

    scanf("%d", &temp->codigo);
    printf("\tCategoria de livro: ");

    scanf("%s", temp->livro);
    return temp;
}


void inserir_pilha(pilha **cabeca)
{
    pilha *novo = novo_no();
    if ((*cabeca) == NULL)
    {
        novo->prox = NULL;
    }
    else
    {
        novo->prox = (*cabeca);
    }
    (*cabeca) = novo;
}

pilha *retirar_pilha(pilha **cabeca)
{
    if ((*cabeca) == NULL)
    {
        printf("\n\tPilha está vazia.");
        return NULL;
    }
    else
    {
        pilha *temp = (*cabeca);
        (*cabeca) = (*cabeca)->prox;
        return temp;
    }
}

void mostrar_pilha(pilha *cabeca)
{
    if (cabeca == NULL)
    {
        printf("\n\tPilha esta vazia.");
    }
    else
    {
        pilha *atual = cabeca;
        printf("\n\tConteudo da Pilha de Livros:\n\n");
        while (atual != NULL)
        {
            printf("\tCod : %d - Categoria : %s\n", atual->codigo, atual->livro);
            atual = atual->prox;
        }
    }
}

void esvaziar_pilha(pilha **cabeca)
{
    if (*cabeca == NULL)
    {
        printf("\n\t Voce esvaziou a Pilha.");
    }
    else
    {

        pilha *atual = (*cabeca);
        while (atual != NULL)
        {
            pilha *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(atual);
        (*cabeca) = NULL;
    }
}
