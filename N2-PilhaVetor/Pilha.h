#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct p_node
{
    int codigo;
    char livro[30];
    struct p_node *prox;
} pilha;


void iniciar_pilha(pilha *cabeca);

pilha *novo_no();

void inserir_pilha(pilha **cabeca);

pilha *retirar_pilha(pilha **cabeca);

void mostrar_pilha(pilha *cabeca);

void esvaziar_pilha(pilha **cabeca);


#endif // PILHA_H_INCLUDED
