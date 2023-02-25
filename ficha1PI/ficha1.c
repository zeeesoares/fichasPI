// exercicio 1

// 1.1 

/*
int x, y;
x = 3; y = x+1;
x = x*y; y = x + y;
printf("%d %d\n", x, y);

output: 12 16     
*/


// 1.2

/*
int x, y;
x = 0;
printf ("%d %d\n", x, y);

output: 0 (nº aleatorio)     
*/


// 1.3

/*
char a, b, c;
a = ’A’; b = ’ ’; c = ’0’;
printf ("%c %d\n", a, a);
a = a+1; c = c+2;
printf ("%c %d %c %d\n", a, a, c, c);
c = a + b;
printf ("%c %d\n", c, c);

output:
A 65
B 66 2 50
b 98

*/

// 1.4

/*
int x, y;
x = 200; y = 100;
x = x+y; y = x-y; x = x-y;
printf ("%d %d\n", x, y);

output: 100 200
*/



// exercicio 2

// 2.1 

/*
int x, y;
x = 3; y = 5;
if (x > y)
y = 6;
printf ("%d %d\n", x, y);

output: 3 5
*/


// 2.2

/*
int x, y;
x = y = 0;
while (x != 11) {
x = x+1; y += x;
}
printf ("%d %d\n", x, y);

output: 11 66
*/


// 2.3

/*
int x, y;
x = y = 0;
while (x != 11) {
x = x+1; y += x;
}
printf ("%d %d\n", x, y);

output: 11 66
*/


// 2.4

/*
void f (int n) {
    while (n>0) {
        if (n%2 == 0) putchar (’0’);
        else putchar (’1’);
    n = n/2;
    }
    putchar (’\n’);
}
int main () {
    int i;
    for (i=0;(i<16);i++)
    f (i);
    return 0;
}

output: 
1
10
11
100
101
110
111
1000
1001
1010
1011
1100
1101
1110
1111
10000
*/






// PROGRAMAS ITERATIVOS

#include <math.h>
#include <stdio.h>


//1

/*
quadrado(4)
output:    ####
           ####
           ####
           ####

Explicação: Construção de um quadrado de lado 4 a partir de linhas, usando a função imprime_cardinal que numa linha coloca um número n de #;
*/


void quadrado(int n) {       
    int i = 0;
    while (i<n) {
        imprime_cardinal(n);
        putchar('\n');
        i++;
    }

}

/* EXTRA
quadradov2(4)
output:    ####
           ----
           ####
           ----

Explicação: Construção de um quadrado de lado 4 a partir de linhas, mas desta vez entrecaladas por dois tipos de char, 
usando a função imprime_cardinal e imprime_traco que numa linha coluca um número n de # e de '-', respetivamente;
*/

void quadradov2(int n) {
    int i = 0;
    while (i<n) {
        if ((i%2)== 0) imprime_cardinal(n); 
        else imprime_traco (n);
        putchar('\n');
        i++;
    }

}


void imprime_cardinal (int n) {
    int i = 0;
    while (i<n) {
        putchar ('#');
        i += 1;
    }
}

void imprime_traco (int n) { 
    int i = 0;
    while (i<n) {
        putchar ('-');
        i += 1;
    }

}

/* 
xadrez(5)
output:    #-#-#
           -#-#-
           #-#-#
           -#-#-
           #-#-#

Explicação: Construção de um quadrado de lado 4 a partir de linhas, mas desta vez entrecaladas por dois tipos de char, 
usando a função imprime_cardinal e imprime_traco que numa linha coluca um número n de # e de '-', respetivamente;
*/


void xadrez (int n){
    int i = 0;
    while (i < n) {
        if (i%2) imprime_xadrez2(n);
        else imprime_xadrez1(n);
        putchar('\n');
        i++;
    }
    return 0;
}

// Explicação: função que cria as linhas iniciadas em '#';
void imprime_xadrez1 (int n) {
    int i = 0;
    while (i<n) {
        if (i%2 == 0) putchar('#');
        else putchar('-');
        i ++;
    }
}

// Explicação: função que cria as linhas iniciadas em '-';
void imprime_xadrez2 (int n) {
    int i = 0;
    while (i<n) {
        if (i%2 == 0) putchar('-');
        else putchar('#');
        i ++;
    }
}


/* 
trianguloH(4);
output: 

#
##
###
####
#####
####
###
##
#


Explicação: Construção de um triângulo na vertical com o char '#';
*/


void trianguloH (int n){
    int i = 1;
    while (i < n) {
        imprime_cardinal(i);
        putchar('\n');
        i++;
    }
    while (i != 0) {
        imprime_cardinal(i);
        putchar('\n');
        i += -1;
    }
    // printf ("TrianguloH %d ainda não está feito...\n", n);
}


/* 
trianguloV(4);
output: 

    #
   ###
  #####
 #######
#########


Explicação: Construção de um triângulo na horizontal com o char '#';
*/


void trianguloV (int n){
    int i = 0;
    int numero_cardinais = 1;
    int numero_espacos = n-1;
    while (i<n) {
        imprime_espaco(numero_espacos);
        imprime_cardinal(numero_cardinais);
        putchar('\n');
        i ++;
        numero_cardinais += 2;
        numero_espacos += -1;
    }
    

    //printf ("TrianguloV %d ainda não está feito...\n", n);
}

void imprime_espaco (int n) {
    int i = 0;
    while (i<n) {
        if (i%2 == 0) putchar(' ');
        else putchar(' ');
        i ++;
    }
}


int main()
{
    quadrado (5);
    putchar('\n');
    quadradov2 (5);
    putchar('\n');
    xadrez (5);
    putchar('\n');
    trianguloH (5);
    putchar('\n');
    trianguloV (5);
    putchar('\n');
    return 0;
}
