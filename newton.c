#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 101

double funcao(double x, double valor_g)
{
    return valor_g - (1 + x + pow(x, 2)/2) * exp(-x);
}

double derivada_funcao(double x)
{
    return exp(-x) * pow(x, 2)/2;
}

double raiz(double valor_inicial, double valor_g)
{
    double valor_anterior = 0.0;

    double limite = pow(10, -6);
    double erro;

    int cont = 0;
    while (1) {
        cont++;
        if (cont >= MAX) break;
        valor_anterior = valor_inicial;
        valor_inicial = valor_anterior - (funcao(valor_anterior, valor_g) / derivada_funcao(valor_anterior));

        erro = abs(valor_inicial-valor_anterior) / abs(valor_inicial);
        if(erro < limite) break;
    }

    printf("Raiz de f %lf -> F(%lf) = %lf\n", valor_inicial, valor_inicial, funcao(valor_inicial, valor_g));

  return valor_inicial; //funcao(valor_inicial, valor_g)
}


int main()
{
    double raiz_A = raiz(1.1, 0.9);
    double raiz_B = raiz(5.1, 0.1);

    printf("O tempo de subida é: %lf \n", (raiz_B - raiz_A));

    return 0;
}
