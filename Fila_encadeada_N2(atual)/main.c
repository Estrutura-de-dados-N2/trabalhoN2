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
    printf("      # 1- Enfileirar pessoa               #\n");
    printf("      #                                    #\n");
    printf("      # 2- Desenfileirar pessoa            #\n");
    printf("      #                                    #\n");
    printf("      # 3- Ver se fila esta vazia          #\n");
    printf("      #                                    #\n");
    printf("      # 4- Ver se fila esta cheia          #\n");
    printf("      #                                    #\n");
    printf("      # 5- Ver quem e o primeiro da fila   #\n");
    printf("      #                                    #\n");
    printf("      # 6- Esvaziar fila                   #\n");
    printf("      #                                    #\n");
    printf("      # 7- Mostrar fila                    #\n");
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
    No *no = NULL;
    int opcao = 1;
    bool noCriado = false;

    while (opcao > 0 && opcao < 7)
    {
        opcao = menu();
        if (opcao < 0 || opcao > 7)
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
            printf("\nVoce escolheu a opcao: Enfileirar pessoa!\n");
            
            char *nome = malloc(15);
            printf("\nDigite o nome do paciente: ");
            scanf("%s15", nome);
            printf("\n>>>>> %s", nome);
            no = enfileirar(no, nome);           
            break;

        case 2:
            printf("\nVoce escolheu a opcao: Desenfileirar pessoa!\n");
            no = desenfileira(no);
            break;

        case 3:
            printf("\nVoce escolheu a opcao: Ver se fila esta vazia!\n");
            if (vazia(no))
            {
                printf("\nA fila esta vazia! ");
            }
            else
            {
                printf("\nA fila nao esta vazia! ");
            }
            break;

        case 4:
            printf("\nVoce escolheu a opcao: Ver se fila esta cheia!\n");
            if (cheia(no))
            {
                printf("\nA fila esta cheia! ");
            }
            else
            {
                printf("\nA fila nao esta cheia! ");
            }
            break;

        case 5:
            printf("\nVoce escolheu a opcao: Ver quem e o primeiro da fila!\n");
            printf("\n-> %s", primeiro(no));
            break;

        case 6:
            printf("\nVoce escolheu a opcao: Esvaziar fila\n!");
            if(esvazia(no))
            {
                printf("\nFila vazia...");
            }
            else
            {
                printf("\nErro ao esvaziar a fila...");
            }            
            break;

        case 7:
            printf("\nVoce escolheu a opcao: Mostrar fila!\n");
            imprimir(no);
            break;
        }
    }
    return 0;
}
