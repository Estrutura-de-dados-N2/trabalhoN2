#include <stdio.h>
#include <stdlib.h>

typedef struct TPtPilha TipoPilha;
typedef int TipoInfo;

TipoPilha* InicializaPilha (TipoPilha *Topo);
int Vazia (TipoPilha *Topo);
void ImprimirPilha (TipoPilha *Topo);
TipoPilha* AdicionaValor (TipoPilha *Topo, TipoInfo Dado);
int RemoveUltimoAdicionado (TipoPilha **Topo, TipoInfo *Dado);
TipoPilha* DestroiPilha (TipoPilha *Topo);

