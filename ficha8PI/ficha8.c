#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}

//1
typedef LInt Stack;

void initStack (Stack *s) {
    (*s) = NULL;
}

int SisEmpty (Stack s) {
    if (s == NULL) return 1;
    else return 0;
}

int push(Stack *s, int x) {
    Stack new = newLInt(x,*s);
    if (new == NULL) return 1;
    *s = new;
    return 0;
}

int pop (Stack *s, int *x) {
    if (SisEmpty(*s)) return 1;
    *x = (*s)->valor;
    Stack aux =(*s)->prox;
    free(*s);
    (*s) = aux;
    return 0;
}

//2
typedef struct {
    LInt inicio;
    LInt fim;
} Queue;

void initQueue (Queue *q) {
    q->fim = NULL;
    q->inicio = NULL;
}

int QisEmpty (Queue q) {
    return (q.fim == NULL && q.inicio == NULL);
}

int enqueue (Queue *q, int x) {
    Stack new = newLInt(x,NULL);
    if (new == NULL) return 1;
    if (QisEmpty(*q)) {
        q->inicio = new;
        q->fim = new;
    }
    else {
        q->fim->prox = new;
        q->fim= new; 
    }
    return 0;
}

int dequeue (Queue *q, int *x) {
    if (QisEmpty(*q)) return 1; 
    *x = q->inicio->valor;
    LInt aux = q->inicio->prox;
    free(q->inicio);
    q->inicio = aux;
    if (q->inicio == NULL) 
        q->fim = NULL;
    return 0;
}

int frontQ (Queue q, int *x) {
    if (QisEmpty(q)) return 1;
    *x = q.inicio->valor;
    return 0;
}