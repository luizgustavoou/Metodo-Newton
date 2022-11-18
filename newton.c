#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x-x-2.0;
}

double df(double x) {
    //Outra forma por meio da aproximação de h muito próximo de 0 :
    const double h = 0.0001;
    return ((f(x+h)-f(x))/h);

    //return 2*x-1;
}


int main() {
    int valor_anterior;
    double valor_inicial=1.0;
    double limite = pow(10, -4);
    double erro;

    while (1) {
        valor_anterior = valor_inicial;
        valor_inicial = valor_anterior - (f(valor_anterior) / df(valor_anterior));

        erro = abs(valor_inicial-valor_anterior) / valor_inicial;
        if(erro < limite) break;
    }

    printf("Valor: %lf\n", valor_inicial);

    return 0;
}
