#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin, abin;


//1

int max (int x, int y) {
    int maximo = 0;
    if (x > y) maximo = x;
    else maximo = y;
    return maximo;
}

int altura (ABin a) {
    int count = 0;
    if (a != NULL) {
        count = 1 + max(altura(a->esq),altura(a->dir));
    } 
    return count;
}

int nFolhas (ABin a) {
    int count = 0;
    if (a != NULL) {
        if (a->esq == NULL && a->dir == NULL)
            count = 1;
        else count = nFolhas(a->esq) + nFolhas(a->esq);
    }
    return count;
}

ABin maisEsquerda (ABin a) {
    if (a == NULL) return NULL;
    while (a->esq != NULL)
        a =a->esq;
    return a;
}

void imprimeNivel (ABin a, int l) {
    if (a != NULL) {
        if (l == 0) printf("%d ", a->valor);
        else {
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir,l-1);
        }
    }
}

int procuraE (ABin a, int x) {
    if (a != NULL) {
        if (x == a->valor) return 1;
        else {
            procuraE(a->esq, x);
            procuraE(a->dir, x);struct nodo *procura (ABin a, int x);
        }
    }
    else return 0;
}

//2
ABin procura (ABin a, int x) {
    ABin res = NULL;
    if (a != NULL) {
        if (a->valor == x) res = a;
        else if (a->valor > x) procura(a->esq,x);
        else procura(a->dir,x);
    }
    return res;
}

int nivel (ABin a, int x) {
    int count = -1;
    if (a != NULL) {
        if (a->valor == x) count = 0;
        else {
            if (a->valor > x) count = 1 + nivel(a->esq,x); 
            else count = 1 + nivel(a->dir,x);
        }
    }
}

void imprimeAte (ABin a, int x) {
    if (a != NULL) {
        if (x < a->valor) {
            imprimeAte(a->esq,x);
            printf("%d ", a->valor);
            imprimeAte(a->dir,x);
        }
        else imprimeAte(a->esq,x);
    }
}
