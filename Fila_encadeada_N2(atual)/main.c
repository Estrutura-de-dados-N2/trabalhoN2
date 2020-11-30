#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila.h"

int menu(){
int opcao = -1;

    printf("\n");
    printf("      ######################################\n");
    printf("      #                MENU                #\n");
    printf("      #                                    #\n");
    printf("      # 1- Criar fila                      #\n");
    printf("      #                                    #\n");
    printf("      # 2- Enfileirar pessoa               #\n");
    printf("      #                                    #\n");
    printf("      # 3- Desenfileirar pessoa            #\n");
    printf("      #                                    #\n");
    printf("      # 4- Ver se fila esta vazia          #\n");
    printf("      #                                    #\n");
    printf("      # 5- Ver se fila esta cheia          #\n");
    printf("      #                                    #\n");
    printf("      # 6- Ver quem e o primeiro da fila   #\n");
    printf("      #                                    #\n");
    printf("      # 7- Esvaziar fila                   #\n");
    printf("      #                                    #\n");
    printf("      # 8- Mostrar fila                    #\n");
    printf("      #                                    #\n");
    printf("      # 0- Sair                            #\n");
    printf("      #                                    #\n");
    printf("      ######################################\n");
    printf("\nDigite o numero da sua opcao: ");
    scanf("%d", &opcao);

return opcao;
}

int main ()
{

    Fila *fila;
    int opcao = 1, tamanhoMaximo = 0;
    bool filaCriada = false;

    while (opcao > 0 && opcao < 8)
    {
        opcao = menu();
        if (opcao < 0 || opcao > 8)
        {
            printf("\nDigite uma opcao valida!\n");
        }
        if (opcao == 0)
        {
            return 1;
        }

        switch (opcao)
        {

        case 1:
            printf("\nVoce escolheu a opcao: Criar fila!");
            printf("\n\nDigite o tamanho maximo da fila: ");
            scanf("%d", &tamanhoMaximo);
            fila = criaFila(tamanhoMaximo);
            filaCriada = true;
            break;

        case 2:
            printf("\nVoce escolheu a opcao: Enfileirar pessoa!");
            if (filaCriada)
            {
                char *nome = malloc(15);
                printf("\nDigite o nome do paciente: ");
                scanf("%s15", nome);
                printf("\n>>>>> %s", nome);
                fila = enfileirar(fila, nome);
            }
            else
            {
                printf("\nPrimeiro crie a Fila! \n");
            }
            break;

        case 3:
            printf("\nVoce escolheu a opcao: Desenfileirar pessoa!");
            fila = desenfileira(fila);
            break;

        case 4:
            printf("\nVoce escolheu a opcao: Ver se fila esta vazia!");
            if (vazia(fila))
            {
                printf("\nA fila esta vazia! ");
            }
            else
            {
                printf("\nA fila nao esta vazia! ");
            }
            break;

        case 5:
            printf("\nVoce escolheu a opcao: Ver se fila esta cheia!");
            if (cheia(fila))
            {
                printf("\nA fila esta cheia! ");
            }
            else
            {
                printf("\nA fila nao esta cheia! ");
            }
            break;

        case 6:
            printf("\nVoce escolheu a opcao: Ver quem e o primeiro da fila!");
            printf("\n-> %s", primeiro(fila));
            break;

        case 7:
            printf("\nVoce escolheu a opcao: Esvaziar fila\n!");
            fila = esvazia(fila);
            break;

        case 8:
            printf("\nVoce escolheu a opcao: Mostrar fila!\n");
            imprimir(fila);
            break;
        }
    }
    return 0;
}
