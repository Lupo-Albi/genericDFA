#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functionsDFA.h"

#define FALSE 0
#define TRUE !(FALSE)

void main (int argc, char *argv[]) {
    /* Declaração de Variáveis */
    char *palavra = argv[1]; // Ponteiro para a palavra de entrada
    int configInstantanea = atoi(argv[2]); // Exibe a configuração Instantânea caso o argumento seja 1


    int estadoInicial = 0;
    // Função de Transição é um array multidimensional de inteiros, que representa a forma de tabela do autômato, onde as linhas são os estados e as colunas os símbolos do alfabeto. Por exemplo, funcaoTrans[q][a] representa a transição do autômato ao estar no estado q e receber o símbolo de entrada a
    int estadoFinal[1] = {3}; // Estado final é um array com os números inteiros que representam os estados finais do autômado
    int funcaoTrans[4][2] = {
                                {1, 2},
                                {0, 3},
                                {3, 0},
                                {2, 1}  
    };
    
    int comprPalavra = strlen(palavra); // Tamanho da palavra de entrada
    int tamEstadoFinal = sizeof(estadoFinal) / sizeof(estadoFinal[0]); // Tamanho do array de estados finais
    int estado = estadoInicial; // Estado em que o autômato se encontra
    int posicao = 0; // Posição na leitura da palavra de entrada
    int eAceita = FALSE; // Informa se a palavra é aceita ou não pelo autômato

    int palavraInt[40]; // Palavra convertida em inteiros
    int palavraAgrupada[40]; // palavraInt agrupada em valores únicos e em ordem crescente
    int comprPalavraAgrupada; 
    int caractereInt; // Símbolo que está sendo lido pelo autômato
    int colunaSimbolo; // Coluna a qual o símbolo que está sendo lido pertence na função de transição

    charArrayToInt(palavra, palavraInt, comprPalavra);
    comprPalavraAgrupada = agruparValores(palavraInt, palavraAgrupada, comprPalavra);

    while(posicao < comprPalavra) {
        if (configInstantanea == TRUE){
            imprimeCI(palavra, comprPalavra, estado, posicao);
        }

        caractereInt = palavraInt[posicao];
        colunaSimbolo = buscaSequencial(palavraAgrupada, caractereInt, comprPalavraAgrupada);

        estado = funcaoTrans[estado][colunaSimbolo]; 

        posicao++;
    }
    
    if (configInstantanea == TRUE){
        imprimeCI(palavra, comprPalavra, estado, posicao);
    }

    // Confere se o estado após a execução do AFD é um estado de aceitação
    if(memchr(estadoFinal, estado, tamEstadoFinal) != NULL) {
        eAceita = TRUE;
    }

    // Verificando se o autômato chegou em um estado de aceitação
    if (eAceita) {
        printf("ACEITA");
    } else {
        printf("REJEITA");
    }
}