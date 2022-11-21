#include <stdio.h>
#include <math.h>

#define MAX 101
double f(double x) {
    return 0.9-(1+x+(x*x)/2)*exp(-x);
}

double df(double x) {
    //Outra forma por meio da aproximação de h muito próximo de 0 :
    // return ((f(x+h)-f(x))/h);

    return exp(-x)*(x*x)/2;
}

int main() {
    double valor_anterior = 0.0, valor_inicial= 1.1;

    double limite = pow(10, -6);
    double erro;

    int cont=0;
    while (1) {
        cont++;
        if (cont >= MAX) break;
        valor_anterior = valor_inicial;
        valor_inicial = valor_anterior - (f(valor_anterior) / df(valor_anterior));

        erro = abs(valor_inicial-valor_anterior) / abs(valor_inicial);
        printf("%lf\n", erro);
        if(erro < limite) break;
    }

    printf("Raiz %lf -> F(%lf) = %lf\n", valor_inicial, valor_inicial, f(valor_inicial));

    return 0;
}
