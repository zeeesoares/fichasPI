#include <stdio.h>
#include <math.h>
#include <string.h>

/*
--1

output:
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12


--2
output:
13

*/


void swapM (int *x, int *y) {
    int acc;
    acc = *x;
    *x = *y;
    *y = acc;
}

void swap (int v[], int i, int j) {
    int acc;
    acc = v[i];   // v[i] = *(v+i)
    v[i] = v[j];
    v[j] = acc;

}

int soma (int v[], int N) {
    int result = 0;
    for (int i = 0; i < N;i++) {
        result += *(v+i);
    }
    return result;
}


void inverteArray1 (int v[], int N) {
    for (int i = 0; i < N/2; i++) {
        swap (v,i,N-1-i);
    }
}

void inverteArray2 (int v[], int N) {
    for(int i = 0; i < N/2; i++) {
        swapM (&v[i],&v[N-1-i]);
    }
}

int maximum (int v[], int N, int *m) {
    for (int i = 0; i < N; i++) {
        if (v[i] > *m) (*m = v[i]);
    }
    return *m;
}


void quadrados (int q[], int N) {
    for (int i = 0; i < N; i++) {
        q[i] = pow(i,2);
    }

}
void imprime_espaco (int n) {
    int i = 0;
    while (i<n) {
        if (i%2 == 0) putchar(' ');
        else putchar(' ');
        i ++;
    }
}


void trianguloV (int v[], int N, int len){
    int i = 0;
    int j = 0;
    int pos = 0;
    int numero_espacos = N-1;
    while (i<N) {
        imprime_espaco(numero_espacos);
        for (j = 0; j < i + 1; j++) {
            printf("%d ", v[j + pos]);
        }
        putchar('\n');
        i++;
        numero_espacos--;
        pos = (i*(i+1))/2;
    }
    
    //printf ("TrianguloV %d ainda não está feito...\n", n);
}

void pascal (int v[], int N) {
    int linhas;
    int pos;
    int len;
    int m;
    for (int k = 1; k <= N; k++) (len += k);
    for (m = 0; m < len; m++) {
        for (linhas = 0; linhas < N; linhas++) {
            for (pos = 0; pos < linhas + 1; pos++) {
                if (pos == 0) {v[m] = 1; m++; continue;}
                if (linhas == pos) {v[m] = 1; m++; continue;}
                v[m] = v[m - linhas - 1] + v[m - linhas];
                m++;
            }
        }
    }
    v[m+1] = '\n';
    trianguloV(v,N,len);
}


int main() 
{   

    int ex;
    printf("Número do exercício: ");
    scanf("%d\n",&ex);
    switch(ex) {
        case 1:
            int x = 3, y = 5;
            swapM (&x, &y);
            printf ("%d %d\n", x, y);
            break;

        case 2:
            int v[] = {1,2,3};
            int N = 3;
            printf("%d\n", soma (v,N));
            break;

        case 3:
            int l[] = {3,3,3};
            int V = 3;
            inverteArray1(l,V);
            putchar('[');
            for (int i = 0; i < V; i++) (printf("%d",l[i]));
            putchar(']');
            putchar('\n');
            break;

        case 4:
            int l2[] = {1,2,3};
            int V2 = 3;
            inverteArray2(l2,V2);
            putchar('[');
            for (int i = 0; i < V2; i++) (printf("%d",l2[i]));
            putchar(']');
            putchar('\n');
            break;

        case 5:
            int l3[] = {1,2,7};
            int V3 = 3;
            int m = 0;
            maximum (l3,V3,&m);
            putchar('[');
            printf("%d",m);
            putchar(']');
            putchar('\n');
            break;
            
        case 6:
            int V4 = 5;
            int lista[1000];
            quadrados (lista,V4);
            putchar('[');
            for (int j = 0; j < V4; j++) (printf(" %d ",lista[j]));
            putchar(']');
            putchar('\n');
            break;
        case 7:
            int V5 = 7;
            int lista1[1000];
            pascal (lista1,V5);
            int len;
            printf("Lista: ");
            for (int k = 1; k <= V5; k++) (len += k);
            for (int j = 0; j < len; j++) (printf("%d",lista1[j]));
            putchar('\n');
            break;
        default :
            printf("Invalid ex\n" );
            break;
        }
    return 0;

    }