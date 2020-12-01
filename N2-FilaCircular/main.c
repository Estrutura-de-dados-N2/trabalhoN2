#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

/*//struct da fila tipo normal*/
typedef struct {
    char nome[100];
    int  numFila;
    int  senha;
}normal;
/*//struct da fila tipo preferencial*/
typedef struct {
    char nome[100];
    int  numFila;
    int  senha;
}preferencial;

/*//declara uma variavel do tipo struct*/
normal filaNormal[10];/*declarado como global para ser acessado em qualquer lugar*/
preferencial  filaPreferencial[10];
int senha,cont,cont2;

/*//Função pra ver se a posição é a menor na fila*/
int menor_Posicao(int vetor[], int tamanho){
    int menor = 0;
    int ind=0;
    for (tamanho=0;tamanho < 10;tamanho++){
        if (menor > vetor[tamanho]) {
            menor = vetor[tamanho];
        }
    }
    return menor;
}
int ordena_Vetor(int vetor[]){
    int i,x,j,ind,temp;
    int retorno=0;        /*estava com valor indeterminado */
    for (i=0;i<10;i++){   /*faltava o =0 */
        for(j=i+1;j<10;j++){
            if( vetor[j] < vetor[i]){/*esse ind serve para que */
                temp     = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = temp    ;
            }
        }
    }
    /*//Imprime vetor ordenado*/
    /*printf("Vetor ordenado : \n");
    for(i=0;i<10;i++)
        printf(" %d",vetor[i]);*/
    return senha;
}
/*//Função pra ver se existe espaço na fila*/
int existe_Espaco(int vetor[],int posicao){
    int vazio[10];
    if(vazio[posicao]=='0')
        return 1;
    else
        return 0;
}
/*//chama a senha*/
int chamar_Senha(int vetor[]){
    int num,i,retorno = 0;
    int vazio[10];
    int vet[10];
    for(i=0; i<10; i++) {
        if (vazio[i]=='O'){/*sem dimensão do vetor*/
            vetor[i]=num;/*sem dimensão do vetor e num sem valor definido*/
            vazio[i]='X';/*falta a posição desse vetor*/
            retorno=1;
            break;
        }
    }
    return retorno;
}
int main (){
    srand(time(NULL));
    /*//Variaveis Globais*/
    int tipo_Fila,i ;
    int resultadoFila;
    char op;
    /*//declara e instancia os  vetores*/
    int fila_Preferencial[10] = {0,0,0,0,0,0,0,0,0,0};
    int fila_Normal[10]= {0,0,0,0,0,0,0,0,0,0};

    do{
        op='n';
        system("cls");
        printf("*******************************\n");
        printf("Bem vindo ao Banco\n");
        printf("*******************************\n\n");
        printf("Digite qual fila deseja entrar:\n");
        printf(" 1 - Para a fila normal\n");
        printf(" 2 - Para a fila preferencial\n");
        printf(" 3 - Listar Todos\n");
        printf(" 0 - Para encerrar o programa\n\n");
        printf("Resposta:  ");
        scanf("%d", &tipo_Fila);

        if (tipo_Fila == 1){
            int i=0;
            printf("Digite seu nome:");
            scanf("%s",&filaNormal[cont].nome);
            printf("Bem vindo a fila %s\n", filaNormal[cont].nome);
            printf("voce esta na fila de espera normal e o numero do seu ticket e : ");
            /*i=ordena_Vetor(fila_Normal);*/
            filaNormal[cont].senha=senha;
            printf("%d",senha);
            cont++;
            senha++;
        }
        if(tipo_Fila == 2){
            printf("Digite seu nome:");
            scanf("%s", &filaPreferencial[cont2].nome);
            printf("Bem vindo a fila %s\n", filaPreferencial[cont2].nome);
            filaPreferencial[cont2].senha=senha;
            printf("Você está na fila de espera preferencial e numero do seu ticket e : ");
            printf("%d",senha);
            cont2++;
            senha++;
        }
        if(tipo_Fila== 3){
            for(i=0;i<cont;i++){

                printf("Nome ----> %s\n",filaNormal[i].nome );
                printf("Senha ---> %d\n\n",filaNormal[i].senha);

            }
            for(i=0;i<cont2;i++){
                if(strcmp(filaPreferencial[0].nome,"")!= 0&&i==0)
                    printf("FilaPreferencial\n");
                    printf("Nome ----> %s\n",filaPreferencial[i].nome );
                    printf("Senha ---> %d\n\n",filaPreferencial[i].senha);
            }
        }
        if(tipo_Fila == 0){
            printf("Encerrando o sistema\n");
            exit(0);
        }
        printf("\nQuer Pegar Outra Senha S/N ");
        fflush(stdin);
        scanf("%c",&op);
    }while(op=='s');
}

