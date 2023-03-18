#include <stdio.h>

float multInt1(int n, float m) {
    int count = 0;
    float r = 0;
    int i = 0;
    while (i < n) {
        r += m;
        i++;
        count++;
    }
    printf("%d",count);
    return r;
}

float multInt2(int n, float m) {
    float r = 0;
    int count = 0;
    for(; n >= 1; n /= 2) {
        if (n % 2 == 1) {
            r += m;
            count++;}
        m = m*2;
        count++;
    }
    printf("%d",count);
    return r;
}

int mdc1 (int a, int b) {
    int result;
    int i = 1;
    if (a > b) {
        while (i <= b) {
            if ((a%i) == 0 && ((b%i) == 0)) (result = i);
            i++;
        }
    }
    else {
        int r = 1;
        while (r <= a) {
            if ((a%r) == 0 && ((b%r) == 0)) (result = r);
            r++;
        } 
    }
    return result;
}


int mdc2 (int a, int b) {
    int res = 0;
    while ((a != 0) && (b != 0)) {
        if (a >= b) {
            a = a - b;
            res++;}
        if (a < b) {
            b = b - a;
            res++;}
    }
    printf("Foram execudados %d ciclos\n",res);
    return b;
}

int mdc3 (int a, int b) {
    int res = 0;
    while ((a%b != 0) && (b%a != 0)) {
        if (a >= b) {
            a = a%b;
            res++;}
        if (a < b) {
            b = b%a;
            res++;}
    }
    printf("Foram execudados %d ciclos\n",res);
    return b;
}

int fib1 (int n) {
    if (n <=2) return 1;
    else return fib1 (n-1) + fib1 (n-2);
}

int fib2 (int n) {
    int aux1 = 1;
    int aux2 = 1;
    int acc;
    while (n > 2) {
        acc = aux1;
        aux1 = aux1 + aux2;
        aux2 = acc;
        n--;
    }
    return aux1;
}


int main() 
{  
    int a;
    float b;
    int ex;
    int res1;
    printf("Número do exercício: ");
    scanf("%d\n",&ex);
    switch(ex) {
        case 1:
            scanf("%d %f", &a, &b);
            float res = multInt1(a, b);
            printf("Resposta: %.2f\n", res);
            break;
        case 2:
            scanf("%d %f", &a, &b);
            res = multInt2(a, b);
            printf("Resposta: %.2f\n", res);
            break;
        case 3:
            scanf("%d %f", &a, &b);
            res = mdc1 (a, b);
            printf("Resposta: %.2f\n", res);
            break;
        case 4:
            scanf("%d %f", &a, &b);
            res = mdc2 (a, b);
            printf("Resposta: %.2f\n", res);
            break;
        case 5:
            scanf("%d %f", &a, &b);
            res = mdc3 (a, b);
            printf("Resposta: %.2f\n", res);
            break;
        case 6:
            scanf("%d", &a);
            res1 = fib1 (a);
            printf("Resposta: %d\n", res1);
            break;
        case 7:
            scanf("%d", &a);
            res1 = fib2 (a);
            printf("Resposta: %d\n", res1);
            break;
        default :
            printf("Invalid ex\n" );
            break;
        }
    return 0;

}