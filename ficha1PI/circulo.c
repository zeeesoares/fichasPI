#include <math.h>
#include <stdio.h>


int circulo (int raio){
    int res = 0, i, j;
    for (i= 0; i < 2*raio + 1; i ++) {
        for (j= 0 ;j < 2*raio + 1; j++) {
            if (sqrt( pow(j-raio,2) + pow(i-raio,2)) > raio) (putchar(' '));
            else {putchar('#');
                  res++;
            }
        }
        putchar('\n');
    }
    

    printf ("\nForam usados %d caracteres para fazer o circulo\n", res);
    return 0;
}


int main()
{
    circulo(4);
    return 0;
}
