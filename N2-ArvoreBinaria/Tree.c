#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

pNodoA* InsereArvore(pNodoA *a, tipoinfo ch)
{
     if (a == NULL)
     {
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info)
              a->esq = InsereArvore(a->esq,ch);
          else if (ch > a->info)
              a->dir = InsereArvore(a->dir,ch);
     return a;
}

void preFixadoE(pNodoA *a)
{
     if (a!= NULL)
     {
          printf("%d - ",a->info);
          preFixadoE(a->esq);
          preFixadoE(a->dir);
      }
}

void posFixadoE(pNodoA *a)
{
     if (a!= NULL)
     {
          posFixadoE(a->esq);
          posFixadoE(a->dir);
          printf("%d - ",a->info);
      }
}

void RemoveMenor(pNodoA *a)
{
       do {
          a = a->esq;
          }
       while (a->esq < a && a->esq->dir != NULL);
        if (a->esq->esq == NULL)
        {
            free(a->esq);
            a->esq = NULL;
        }
}

void RemoveMaior(pNodoA *a)
{
    do {
       a = a->dir;
       }
    while (a < a->dir && a->dir->esq != NULL);
     if (a->dir->dir == NULL)
     {
        free(a->dir);
        a->dir = NULL;
     }
}



