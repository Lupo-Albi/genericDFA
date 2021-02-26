/* Headers */
#include <stdio.h>
#include <string.h> // Header para manipular strings

/* Declaração de funções */
void imprimeCI(char* palavra, int comprPalavra, int estado, int posicao);
int buscaSequencial(int* vetor, int chave, int comprVetor);
void insertionSort(int* vetor, int comprVetor);
void charArrayToInt(char* vetorOrigem, int* vetorDestino, int comprVetor);
int agruparValores(int* vetorOrigem, int* vetorDestino, int comprVetor);

// int argc, char *argv[]
void main () {
    /* Declaração de Variáveis */
    // char *palavra = argv[1]; // Ponteiro para a palavra de entrada
    char palavra[6] = "aabbab";
    int estadoInicial = 0; 
    int funcaoTrans[4][2] = {{1,2}, {0,3}, {3, 0}, {2,1}}; // Função de Transição é um array multidimensional de inteiros, que representa a forma de tabela do autômato, onde as linhas são os estados e as colunas os símbolos do alfabeto. Por exemplo, funcaoTrans[q][a] representa a transição do autômato ao estar no estado q e receber o símbolo de entrada a
    int estadoFinal[1] = {3}; // Estado final é um array com os números inteiros que representam os estados finais do autômado
    int comprPalavra = strlen(palavra); // Guarda o tamanho da palavra de entrada
    int estado = estadoInicial; // Estado em que o autômato se encontra
    int posicao = 0; // Posição na leitura da palavra de entrada
    int eAceita = 0; // Informa se a palavra é aceita ou não pelo autômato

    int palavraInt[6], palavraAgrupada[6];
    int comprAgrupado, caractereInt, letraAlfabeto;

    charArrayToInt(palavra, palavraInt, comprPalavra);
    comprAgrupado = agruparValores(palavraInt, palavraAgrupada, comprPalavra);

    while(posicao < comprPalavra) {
        imprimeCI(palavra, comprPalavra, estado, posicao);

        caractereInt = palavraInt[posicao];
        letraAlfabeto = buscaSequencial(palavraAgrupada, caractereInt, comprAgrupado);
        // char caractere = palavra[posicao];
        // int caractereInt = caractere - '0'; // Converte caractere para o tipo int

        estado = funcaoTrans[estado][letraAlfabeto]; 

        posicao++;
    }
    imprimeCI(palavra, comprPalavra, estado, posicao); // Mostrando configuração instantânea do final da execução do autômato

    // loop para percorrer todos os estados de aceitação. Se o autômato chegou em um estado de aceitação após o término da sua execucação, então a string de entrada é aceita por ele
    int tamEstadoFinal = sizeof(estadoFinal) / sizeof(estadoFinal[0]); // Tamanho do array de estados finais
    if(memchr(estadoFinal, estado, tamEstadoFinal) != NULL) {
        eAceita = 1;
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

/*
 * Função: buscaSequencial 
 * ------------------------
 * percorre o vetor buscando por um valor chave
 * 
 * int* vetor: vetor de inteiros a ser buscado um valor
 * int chave: valor a ser buscado
 * int comprVetor: inteiro com o tamanho do vetor
 * 
 * returns: o índice da primeira ocorrência da chave buscada ou -1 caso não encontra a chave no array
 */
int buscaSequencial(int* vetor, int chave, int comprVetor) {
    for (int i = 0; i < comprVetor; i++) {
        if(vetor[i] == chave) {
            return i;
        }
    }
    return -1;
}

/*
 * Função: insertionSort
 * ----------------------
 * Ordena um vetor de inteiros de forma crescente
 * 
 *  int* vetor: vetor de inteiros a ser ordenado
 *  int tamanho: tamanho do vetor a ser ordenado
 */
void insertionSort(int* vetor, int comprVetor) {
    int chave, i;
    for (int j = 1; j < comprVetor; j++){
        chave = vetor[j];
        i = j - 1;

        while (i >= 0 && vetor[i] > chave) {
            vetor[i+1] = vetor[i];
            i--;
        }

        vetor[i + 1] = chave;
    }
}

/*
 * Função: charArrayToInt
 * -----------------------
 * Converte os valores de um array de caracteres em valores inteiros (correspondente aos da tabela ASCII) para um array de destino
 * 
 * char* vetorOrigem: array de caracteres
 * int* vetorDestino: array que recebe os valores convertidos para inteiros
 * int comprVetor: tamanho do array de origem vetorOrigem
 */
void charArrayToInt(char* vetorOrigem, int* vetorDestino, int comprVetor) {
    for (int i = 0; i < comprVetor; i++) {
        vetorDestino[i] = (int)(vetorOrigem[i]);
    }
}

/*
 * Função: agruparValores
 * ------------------------
 * Agrupa valores iguais encontrados em um array e os ordena em ordem crescente.
 * Exemplo: Se o vetor de origem é [3, 3, 1, 1, 2] o vetor de destino será [1, 2, 3] após a execução da função e retorna o valor 3 (número de elementos no array de destino)
 * 
 * int* vetorOrigem: array de inteiros
 * int* vetorDestino: array que recebe o agrupamento em ordem crescence
 * int comprVetor: tamanho do array de origem vetorOrigem
 * 
 *  returns: retorna a quantidade final de elementos gravados no vetor de destino
 */
int agruparValores(int* vetorOrigem, int* vetorDestino, int comprVetor) {
    int posicao = 0; // posição para gravar no array, também informa quantos valores foram gravados no vetor de destino
    int chave; // e veirifica se ele já foi adicionado ao vetor de origem. Caso não, 

    for (int i = 0; i < comprVetor; i++){
        chave = vetorOrigem[i]; // armazena a cada iteração do laço um valor do vetor de origem

        // Caso a chave não esteja no vetor destino, ela é adicionada a ele
        if(buscaSequencial(vetorDestino, chave, posicao) < 0){
            vetorDestino[posicao] = chave;
            posicao++;
        }
    }
    // Nesse ponto, todos os valores únicos do vetor de origem foram adicionados ao vetor de destino
    insertionSort(vetorDestino, posicao); // Ordenando o vetor de destino final em ordem crescente

    return posicao;
}