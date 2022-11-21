#include <stdio.h>
#include <math.h>

#define MAX 101
double fa(double x) {
    return 0.9-(1+x+(x*x)/2)*exp(-x);
}

double dfa(double x) {
    return exp(-x)*(x*x)/2;
}

void rootFA() {
    double valor_anterior = 0.0, valor_inicial= 1.1;

    double limite = pow(10, -6);
    double erro;

    int cont=0;
    while (1) {
        cont++;
        if (cont >= MAX) break;
        valor_anterior = valor_inicial;
        valor_inicial = valor_anterior - (fa(valor_anterior) / dfa(valor_anterior));

        erro = abs(valor_inicial-valor_anterior) / abs(valor_inicial);
        //printf("%lf\n", erro);
        if(erro < limite) break;
    }

    printf("Raiz de fa %lf -> Fa(%lf) = %lf\n", valor_inicial, valor_inicial, fa(valor_inicial));
}

double fb(double x) {
    return 0.1-(1+x+(x*x)/2)*exp(-x);
}

double dfb(double x) {
    return exp(-x)*(x*x)/2;
}

void rootFB() {
    double valor_anterior = 0.0, valor_inicial= 5.1;

    double limite = pow(10, -6);
    double erro;

    int cont=0;
    while (1) {
        cont++;
        if (cont >= MAX) break;
        valor_anterior = valor_inicial;
        valor_inicial = valor_anterior - (fb(valor_anterior) / dfb(valor_anterior));

        erro = abs(valor_inicial-valor_anterior) / abs(valor_inicial);
        //printf("%lf\n", erro);
        if(erro < limite) break;
    }

    printf("Raiz de fb %lf -> Fb(%lf) = %lf\n", valor_inicial, valor_inicial, fb(valor_inicial));
}

int main() {

    rootFA();
    rootFB();
    return 0;
}
