#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;


void libertalista (Palavras l) {
    Palavras aux;
    while (l  != NULL) {
        aux = l -> prox;
        free(l -> palavra);
        free (l);
        l = aux;
    }
}

int quantasP (Palavras l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = (l -> prox);
    }
    return count;
}

void listaPal (Palavras l) {
    int count = 0;
    while (l != NULL) {
        printf("%d --- %s\n", l -> ocorr, l->palavra);
        l = (l -> prox);
    } 
}

char * ultima (Palavras l) {
    if (l == NULL) return NULL;
    while (l -> prox != NULL) {
        l = (l -> prox);
    }
    return (printf("%s\n", l -> palavra));
}

Palavras acrescentaFim (Palavras l, char *p) {
    Palavras new = malloc(sizeof(struct celula));
    char* new_word = malloc(sizeof(sizeof (char) * strlen(p) + 1));
    strcpy(new_word,p);
    new -> palavra = new_word;
    new -> ocorr = 1;
    new -> prox = l;
    return new;
}

Palavras acrescentaFim (Palavras l, char *p) {
    Palavras aux = l;
    Palavras new = malloc(sizeof(struct celula));
    char* new_word = malloc(sizeof(sizeof (char) * strlen(p) + 1));
    strcpy(new_word,p);
    if (l == NULL) {              // caso da struct estar vazia
        new -> palavra = new_word;
        new -> ocorr = 1;
        new -> prox = NULL;
        return new;
    }
    while (l -> prox != NULL) {  // correr a lista
        l = l -> prox;
    }
    new -> palavra = new_word;  // adicionar uma celula
    new -> ocorr = 1;
    new -> prox = NULL;
    aux = new -> prox;
    return aux;
}

Palavras acrescentaFim_V2 (Palavras l, char *p) {
    Palavras aux = l;
    Palavras new = malloc(sizeof(struct celula));
    char* new_word = malloc(sizeof(sizeof (char) * strlen(p) + 1));
    strcpy(new_word,p);
    new -> palavra = new_word;  // adicionar uma celula
    new -> ocorr = 1;
    new -> prox = NULL;
    Palavras * lp;
    lp = &l;
    while (*lp != NULL) {
        lp = &((*lp) -> prox);
    }
    *lp = new;
    return l;
}
