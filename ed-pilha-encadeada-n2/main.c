#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include <conio.h>


int main ()
{
    printf("Undo de programas de texto utiliza pilhas, por usar sistema LIFO\n6 valores adicionados como exemplo, para depois serem apagados\n\n");
    system("pause");
    system("cls");

    TipoPilha *P1;
    TipoInfo dado;

    P1=InicializaPilha(P1);

    P1 = AdicionaValor(P1,6);
    P1 = AdicionaValor(P1,5);
    P1 = AdicionaValor(P1,4);
    P1 = AdicionaValor(P1,3);
    P1 = AdicionaValor(P1,2);
    P1 = AdicionaValor(P1,1);

    printf("Adicionados em pilha: 6, 5, 4, 3, 2, 1\n");
    ImprimirPilha(P1);

    do {
    printf("\n\nPressione qualquer tecla para apagar a ultima adicionada\n\n");
    system("pause");
    RemoveUltimoAdicionado(&P1, &dado);
    system("cls");
    ImprimirPilha(P1);
       }
    while (P1 != NULL);
}
