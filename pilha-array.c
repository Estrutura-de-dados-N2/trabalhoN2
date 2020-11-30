#include<stdio.h>


//IMPLEMENTACAO DE PILHA USANDO ARRAY

void push(char element, char stack[], int *top, int stackSize)
{
    if(*top == -1)
    {
        stack[stackSize - 1] = element;
        *top = stackSize - 1;
    }
    else if(*top == 0)
    {
        printf("A pilha já está cheia. \n");
    }
    else
    {
        stack[(*top) - 1] = element;
        (*top)--;
    }
}
void pop(char stack[], int *top, int stackSize)
{
    if(*top == -1)
    {
        printf("A pilha já está vazia. \n");
    }
    else
    {
        printf("Elemento estourado: %c \n", stack[(*top)]);
        // Se o elemento exibido for o último elemento da pilha
        // em seguida, defina top para -1 para mostrar que a pilha está vazia
        if((*top) == stackSize - 1)
        {
            (*top) = -1;
        }
        else
        {
            (*top)++;
        }
    }
}
int main()
{
    int stackSize = 4;
    char stack[stackSize];
    // Um índice negativo mostra que a pilha está vazia
    int top = -1;
    push('a', stack, &top, stackSize);
    printf("Elemento no topo: %c\n", stack[top]);
    push('b',stack, &top, stackSize);
    printf("Elemento no topo: %c\n", stack[top]);
    pop(stack, &top, stackSize);
    printf("Elemento no topo: %c\n", stack[top]);
    pop(stack, &top, stackSize);
    printf("Topo: %d\n", top);
    pop(stack, &top, stackSize);
    return 0;
}
