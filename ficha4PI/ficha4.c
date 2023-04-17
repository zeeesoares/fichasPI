#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001

int verificaVogais(char a) {
    char vogais[] = "AEIOUaeiou";
    for (int i = 0; i < 11; i++) {
        if (a == vogais[i])
            return 1;
    }
    return 0;
}


int contaVogais (char *s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (verificaVogais(*(s+i)) == 1) count++;
    }
    return count;
}


int retiraVogaisRep (char *s) {
    int count = 0;
    int len = strlen(s);
    char aux[len];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1] && verificaVogais(s[i])) {count++;}
        else {aux[j] = s[i]; j++;}
    }
    aux[j] = '\0';
    strcpy(s,aux);
    return count;
}

int retiraVogaisRep2 (char *s) {
    int count = 0;
    int len = strlen(s);
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1] && verificaVogais(s[i])) {count++; s[j] = s[i+1];}
        else {s[j] = s[i]; j++;}
    }
    s[j] = '\0';
    return count;
}

int duplicaVogais (char *s) {
    int count = 0;
    int len = strlen(s);
    char aux[MAX];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (verificaVogais(s[i]) == 1) {count++; aux[j] = s[i]; aux[j+1] = s[i]; j += 2;}
        else {aux[j] = s[i]; j++;}
    }
    aux[j] = '\0';
    strcpy(s,aux);
    return count;
}

int duplicaVogais2 (char *s) {
    int count = 0;
    int tam = strlen(s);
    int j = tam + contaVogais(s) - 1;
    for (int i = tam - 1; i >= 0; i--) {
        if (verificaVogais(s[i]) == 1) {
            s[j] = s[i]; count;
            s[j-1] = s[i];
            j -= 2; 
        }
        else {s[j] = s[i]; j++;}
    }
    return count;
}

int ordenado (int v[], int N) {
    for (int i = 1; i < N; i++) {
        if (v[i-1] > v[i]) return 0;
    }
    return 1;
}


void merge (int a[], int na, int b[], int nb, int r[]) {
    int ia = 0; int ib = 0; int i = 0;
    while (ia < na && ib < nb) {
        if (a[ia] < b[ib]) {r[i] = a[ia]; ia++;}
        else {r[i] = b[ib]; ib++;}
        i++;
    }
    while (ia < na) {
        r[i] = a[ia];
        ia++;
        i++; 
    }
    while (ib < nb) {
        r[i] = a[ib];
        ib++;
        i++; 
    }
}