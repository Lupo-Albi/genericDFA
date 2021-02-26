/* Headers */
#include <stdio.h>
#include <string.h>
#include "functionsDFA.h"

/* Definição de funções */
/*
 *  Função: imprimeCI
 * ---------------------
 * Imprime as configurações instântaneas da execução do Autômato
 * 
 * vetor: array com a palavra de entrada
 * comprVetor: tamanho do array de entrada
 * estado: estado em que o autômato se encontra
 * posicao: posicao do autômato na leitura do array de entrada
 */
// Função para imprimir as configurações instantâneas da execução do Autômato.
void imprimeCI(char* vetor, int comprVetor, int estado, int posicao) {
    int contador = 0; // Contador que percorre a palavra de entrada

    // Imprime os caracteres antes do estado atual, os que já foram lidos
    for (; contador < posicao; contador++) {
        printf("%c", vetor[contador]); 
    }

    printf("[q%i]", estado); // Imprime o estado atual
    
    // Imprime os caracteres que faltam ser lidos a partir do estado atual
    for (; contador < comprVetor; contador++) {
        printf("%c", vetor[contador]);
    }

    printf("\n"); // Quebra de linha
}

/*
 * Função: buscaSequencial 
 * ------------------------
 * percorre o vetor buscando por um valor chave
 * 
 * vetor: vetor de inteiros a ser buscado um valor
 * chave: valor a ser buscado
 * comprVetor: inteiro com o tamanho do vetor
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
 * vetor: vetor de inteiros a ser ordenado
 * tamanho: tamanho do vetor a ser ordenado
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
 * vetorOrigem: array de caracteres
 * vetorDestino: array que recebe os valores convertidos para inteiros
 * comprVetor: tamanho do array de origem vetorOrigem
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
 * vetorOrigem: array de inteiros
 * vetorDestino: array que recebe o agrupamento em ordem crescence
 * comprVetor: tamanho do array de origem vetorOrigem
 * 
 * returns: retorna a quantidade final de elementos gravados no vetor de destino
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