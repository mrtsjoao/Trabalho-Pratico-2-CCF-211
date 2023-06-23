#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cartas.h"

int main() {

    int N, nCartas;

    scanf("%d", &N); //Para quebrar o galho durante os testes,N será uma variável dada pelo usuario ao executar

    nCartas = N * 52;
    No baralho[nCartas];
    
    // Montando o baralho com todas as cartas
    char naipes[4][2] = {"C", "O", "P", "E"};
    char valores[13][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
    int contador = 0;
    

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(baralho[contador].carta.naipe, naipes[i]);
            strcpy(baralho[contador].carta.valor, valores[j]);
            contador++;
        }
    }
    
    int tamanho = sizeof(baralho) / sizeof(baralho[0]);
    
    printf("Baralho antes da ordenação:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s %s\n", baralho[i].carta.naipe, baralho[i].carta.valor);
    }
    
    ordenarBaralho(baralho, tamanho);
    
    printf("\nBaralho após a ordenação:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s %s\n", baralho[i].carta.naipe, baralho[i].carta.valor);
    }
    
    return 0;
}