//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 3 - Questão 02
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/1255

#include <stdio.h>
#include <string.h>

int main() {
    int testes, i, j, k, l, m, n;
    int tamanhoFrase = 201, tamanhoLetras = 26;
    int freq[tamanhoLetras], letras[tamanhoLetras], freqMaior, tamanhoInput;
    char ch, texto[tamanhoFrase];

    scanf("%d", &testes);
    getchar();

    for (i = 0; i < testes; i++) {
        fgets(texto, tamanhoFrase, stdin);
        tamanhoInput = strlen(texto);
        while (texto[tamanhoInput-1] == '\n') {
            texto[tamanhoInput-1] = '\0';
        }

        freqMaior = 0;
        for (j = 0; j < tamanhoLetras; j++) {
            freq[j] = 0;
            letras[j] = 0;
        }
        for (k = 0; k < tamanhoInput; k++) {
            ch = texto[k];
            if (ch >= 'A' && ch <= 'Z') {
                ch += ('a'-'A');
            }
            if (ch >= 'a' && ch <= 'z') {
                freq[ch - 'a']++;
            }
        }
        for (l = 0; l < tamanhoLetras; l++) {
            if (freq[l] > freqMaior) {
                freqMaior = freq[l];
                for (m = 0; m < tamanhoLetras; m++) {
                    letras[m] = 0;
                }
                letras[l] = 1;
            } else if (freq[l] == freqMaior) {
                letras[l] = 1;
            }
        }
        for (n = 0; n < tamanhoLetras; n++) {
            if (letras[n]) {
                printf("%c", 'a'+ n);
            }
        }
        printf("\n");
    }
}