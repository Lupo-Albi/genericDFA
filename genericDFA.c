/* Headers */
#include <stdio.h>
#include <string.h> // Header para manipular strings

/* Definindo constantes */
#define FALSE 0 
#define TRUE !(FALSE)

/* Declaração de funções */
void imprimeCI(char* palavra, int comprPalavra, int estado, int posicao);


void main (int argc, char *argv[]) {
    /* Declaração de Variáveis */
    char *palavra = argv[1]; // Ponteiro para a palavra de entrada
    int estadoInicial = 0; 
    int funcaoTrans[4][2] = {{1,0}, {1,2}, {3, 0}, {3,3}}; // Função de Transição é um array multidimensional de inteiros, que representa a forma de tabela do autômato, onde as linhas são os estados e as colunas os símbolos do alfabeto. Por exemplo, funcaoTrans[q][a] representa a transição do autômato ao estar no estado q e receber o símbolo de entrada a
    int estadoFinal[1] = {3}; // Estado final é um array com os números inteiros que representam os estados finais do autômado

    int comprPalavra = strlen(palavra); // Guarda o tamanho da palavra de entrada
    int estado = estadoInicial; // Estado em que o autômato se encontra
    int posicao = 0; // Posição na leitura da palavra de entrada
    int eAceita = FALSE; // Informa se a palavra é aceita ou não pelo autômato

    while(posicao < comprPalavra) {
        imprimeCI(palavra, comprPalavra, estado, posicao); // Mostrando configuração instantânea do autômato

        char caractere = palavra[posicao];
        int caractereInt = caractere - '0'; // Converte caractere para o tipo int

        estado = funcaoTrans[estado][caractereInt]; 

        posicao++;
    }

    imprimeCI(palavra, comprPalavra, estado, posicao); // Mostrando configuração instantânea do final da execução do autômato

    // loop para percorrer todos os estados de aceitação. Se o autômato chegou em um estado de aceitação após o término da sua execucação, então a string de entrada é aceita por ele
    int tamEstadoFinal = sizeof(estadoFinal) / sizeof(estadoFinal[0]); // Tamanho do array de estados finais
    for (int i = 0; i < tamEstadoFinal; i++) {
        if (estado == estadoFinal[i]) {
            eAceita = TRUE; 
        }
    }

    // Verificando se o autômato chegou em um estado de aceitação
    if (eAceita) {
        printf("ACEITA");
    } else {
        printf("REJEITA");
    }
}

/* Definição de funções */

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