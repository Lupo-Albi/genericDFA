#include <stdio.h>
#include <string.h> // Cabeçalho para manipular strings

void imprimeCI(char* palavra, int comprPalavra, int estado, int posicao)

int main (int argc, char *argv[]) {
    char *palavra = argv[1]; // Ponteiro para a palavra de entrada
    int comprPalavra = strlen(palavra); // Guarda o tamanho da palavra de entrada
    int estado = 0; // O estado é um número inteiro. O valor colocado aqui representa o estado inicial
    int funcaoTrans[][2] = {{1,2}, {1,2}}; // Função de Transição é um array multidimensional de inteiros, sendo o primeiro valor corresponde ao estado atual e o segundo ao símbolo lido
    int estadoFinal[1] = {0}; // Estado final é um array com os números inteiros que representam os estados finais do autômado
    int posicao = 0; // Posição na leitura da palavra de entrada

    imprimeCI(palavra, comprPalavra, estado, posicao); // Mostrando configuração instantânea do autômato

    return 0;
}


// Função para imprimir as configurações instantâneas da execução do Autômato.
void imprimeCI(char* palavra, int comprPalavra, int estado, int posicao) {
    int contador = 0; // Contador que percorre a palavra de entrada

    // Imprime os caracteres antes do estado atual, os que já foram lidos
    for (; contador < posicao; contador++) {
        printf("%c", palavra[contador]); 
    }

    printf("[q%i]", estado); // Imprime o estado atual
    
    // Imprime os caracteres que faltam ser lidos a partir do estado atual
    for (; contador < comprPalavra; contador++) {
        printf("%c", palavra[contador]);
    }

    printf("\n"); // Quebra de linha
}