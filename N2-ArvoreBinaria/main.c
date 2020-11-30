#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"


int main()
{
   pNodoA *arv1 = NULL;

   arv1 = InsereArvore(arv1,25);
   arv1 = InsereArvore(arv1,22);
   arv1 = InsereArvore(arv1,40);
   arv1 = InsereArvore(arv1,30);
   arv1 = InsereArvore(arv1,45);
   arv1 = InsereArvore(arv1,27);
   arv1 = InsereArvore(arv1,20);

   printf(" -- Pre-ordem --\n");
   preFixadoE(arv1);
   printf("\n\n");

   printf(" -- Pos-ordem --\n");
   posFixadoE(arv1);
   printf("\n\n");

   RemoveMenor(arv1);

   printf(" -- Pos-ordem com menor removido --\n");
   posFixadoE(arv1);
   printf("\n\n");

   printf(" -- Pre-ordem com menor removido --\n");
   preFixadoE(arv1);
   printf("\n\n");

   RemoveMaior(arv1);

   printf(" -- Pos-ordem com maior removido --\n");
   posFixadoE(arv1);
   printf("\n\n");

   printf(" -- Pre-ordem com maior removido --\n");
   preFixadoE(arv1);
   printf("\n\n");

}
