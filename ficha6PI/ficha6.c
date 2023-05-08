#include <stdio.h>
#define Max 1000

struct staticStack {
    int sp;
    int values[Max];
};

typedef struct staticStack * SStack;

void SinitStack (SStack s) {
    s -> sp = 0; // == (*s)-sp = 0;
}

int Spush (SStack s, int x) {
    if (s -> sp < Max) 
        s -> values[s->sp] = x;
        s -> sp++;
        return 0;
}

void imprimeStack(SStack s) {
    for (int i = s -> sp -1; i >= 0; i--) {
        printf("| %d |\n", s -> values[i]);
    }
}

int Spop (SStack s, int *x) {
    if (s -> sp > 0) {
        *x = s -> values[s->sp-1];
        s -> sp--;
        return 0;
    }
    else return 1;
}

int Stop (SStack s, int *x) {
    if (s -> sp > 0) {
        *x = s -> values[s->sp-1];
        return 0;
    }
    else return 1;
}

int main() {
    int x;
    int y;
    struct staticStack stack;
    SinitStack(&stack);

    Spush(&stack,1);
    Spush(&stack,2);
    Spush(&stack,3);
    Spop(&stack,&x);
    Stop(&stack,&y);
    printf("_____\n");
    imprimeStack(&stack);
    printf("=====\n");
    printf("--%d--\n", x);
    printf("->%d<-\n", y);


    return 0;
    
}