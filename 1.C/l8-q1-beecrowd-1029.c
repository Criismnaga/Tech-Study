//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 8 - Questão 01
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/1029

#include <stdio.h>

int n_chamadas_recursivas;

int main() {
    int numero_de_testes;
    scanf("%d", &numero_de_testes);

    for (int i = 0; i < numero_de_testes; i++) {
        int argumento;
        scanf("%d", &argumento);

        n_chamadas_recursivas = -1;
        int valor_fibonacci = fibonacci(argumento);

        printf("fib(%d) = %d calls = %d\n", argumento, n_chamadas_recursivas, valor_fibonacci);
    }

    return 0;
}

int fibonacci(int argumento) {
    n_chamadas_recursivas++;
    if (argumento == 0) {
        return 0;
    } else if (argumento == 1) {
        return 1;
    } else {
        return fibonacci(argumento - 1) + fibonacci(argumento - 2);
    }
}