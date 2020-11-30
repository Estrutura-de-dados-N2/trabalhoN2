typedef int tipoinfo;

struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

pNodoA* InsereArvore(pNodoA *a, tipoinfo ch);
void preFixadoE(pNodoA *a);
void posFixadoE(pNodoA *a);
void RemoveMenor(pNodoA *a);
void RemoveMaior(pNodoA *a);



