#include <stdio.h>
#include <math.h>

#define MAX 30
double f(double x) {
    return 25.0*x*x+log(x);
}

double df(double x) {
    //Outra forma por meio da aproximação de h muito próximo de 0 :
    const double h = 0.0001;
    return ((f(x+h)-f(x))/h);

    //return 2*x-1;
}

int main() {
    double valor_anterior = 0.0, valor_inicial= 0.1;

    double limite = pow(10, -6);
    double erro;

    int cont=0;
    while (1) {
        cont++;
        if (cont >= MAX) break;
        valor_anterior = valor_inicial;
        valor_inicial = valor_anterior - (f(valor_anterior) / df(valor_anterior));

        erro = abs(valor_inicial-valor_anterior) / valor_inicial;
        printf("%lf\n", erro);
        if(erro < limite) break;
    }

    printf("Valor: %lf\n", valor_inicial);

    return 0;
}
