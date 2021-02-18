#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    // O Estado Inicial é representado por um número inteiro
    int estadoInicial = 0;
    // Função de Transição é um array multidimensional de inteiros, sendo o primeiro valor corresponde ao estado atual e o segundo ao símbolo lido
    int funcaoTrans[][2] = {{1,2}, {1,2}};
    // Estado final é um array com os números inteiros que representam os estados finais do autômado
    int estadoFinal[1] = {0};

    int x = 4;
    printf("%s", argv[1]);
    return 0;
}