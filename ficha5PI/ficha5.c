#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
    } Aluno;

//1
int nota (Aluno a) {
    int nota_final = 0;
    float nota_miniteste;
    for (int i = 0; i < 6; i++)
        nota_miniteste += a.miniT[i];
    nota_miniteste /= 6;
    if (nota_miniteste < 0.25) return 0;    
    nota_miniteste = (nota_miniteste * 20)*2;
    nota_final = 0.20*nota_miniteste + 0.80*a.teste;
    if (nota_final < 9.5) return 0;
    return (nota_final);

}

Aluno turma[4] = {
     {4444, "Andre", {2,1,0,2,2,2}, 10.5}
    ,{2222, "Joana", {2,2,2,1,0,0}, 14.5}
    ,{7777, "Maria", {2,2,2,2,2,1}, 18.5}
    ,{3333, "Paulo", {0,0,2,2,2,1}, 8.7}
};

//2
int procuraNum (int num, Aluno t[], int N) {
    int res = -1;
    int i;
    for (i = 0; i < N && num > t[i].numero ;i++);
    if (i < N && num == t[i].numero) res = i;
    return res;
}

//3
void insereNum(Aluno a, Aluno t[], int n) {
    while (n > 0 && t[n-1].numero > a.numero) {
        t[n].numero  = t[n-1].numero;
        n--;
    }
    t[n].numero = a.numero;
}

void ordenaPorNum (Aluno t[], int N) {
    int i;
    for (i = 0; i < N;i++) {
        insereNum(t[i],t,i);
    }
}

//4
void criaIndPorNum (Aluno t [], int N, int ind[]) {
    int res[N];
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (t[i].numero > t[j].numero)
                count++;
        }
        res[i] = count;
    }
    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            if (k == res[l]) ind[k] = l;
        }
    }
}



//5
void imprimeTurma (int ind[], Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        int indT = ind[i];
        Aluno a = t[indT];
        printf("%d | %5s | %d\n", a.numero, a.nome, nota(a));
    }
}

//6
int procuraNum2 (int num,  Aluno t[], int ind[], int N) {
    int res = -1;
    for (int i = 0; i < N; i++) {
        if  (num == t[ind[i]].numero) res = ind[i];
    }
    return res;
}


//7

void ordenaPorNome (Aluno t[], int N, int ind[]) {
    if (N <= 1) return;

    ordenaPorNome(t, N-1, ind);

    int i;
    for (i = N-2; i >= 0; i--) {
        if (strcmp(t[ind[i]].nome,t[ind[i+1]].nome) > 0) {
            int temp = ind[i];
            ind[i] = ind[i+1];
            ind[i+1] = temp;        
        }
    }
}

void criaIndPorNome (Aluno t [], int N, int ind[]) {
    for (int i = 0; i < N; i++) {
        ind[i] = i;
    }
    ordenaPorNome(t, N, ind);
}

/*
int main() {
    Aluno turma1[] = {
     {4444, "Pedro", {2,1,0,2,2,2}, 10.5}
    ,{5555, "Joana", {2,2,2,1,0,0}, 14.5}
    ,{7777, "Zé", {2,2,2,2,2,1}, 18.5}
    ,{3333, "Lina", {0,0,2,2,2,1}, 8.7}
    };
    int ind[] = {0,0,0,0};
    int ind2[4];
    criaIndPorNum(turma1,4,ind);
    printf("%d\n", procuraNum2 (7777, turma1,ind, 4));
    for (int i = 0; i < 4; i++) printf("%d ", ind[i]);
    printf("\n");
    return 0;

}
*/