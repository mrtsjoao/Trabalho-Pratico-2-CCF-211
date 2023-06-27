#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cartas.h"

int main() {
    int N, nCartas;

    scanf("%d", &N);
    nCartas = N * 52;
    No* baralho[nCartas];
    
    // Montando o baralho com todas as cartas
    char naipes[4][3] = {"C", "O", "P", "E"};
    char valores[13][4] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
    int contador = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            card novaCarta;
            strcpy(novaCarta.naipe, naipes[i]);
            strcpy(novaCarta.valor, valores[j]);
            baralho[contador] = criarNo(novaCarta);
            contador++;
        }
    }
    
    No* pilha = NULL;
    
    embaralharCartas(&pilha, baralho, nCartas);
    
    printf("Pilha de cartas embaralhadas:\n");
    No* atual = pilha;
    while (atual != NULL) {
        printf("[%s %s]\n", atual->carta.naipe, atual->carta.valor);
        atual = atual->proximo;
    }
    
    // Libera a memória alocada para as cartas do baralho
    for (int i = 0; i < nCartas; i++) {
        free(baralho[i]);
    }
    
    // Libera a memória alocada para as cartas da pilha
    liberarPilha(pilha);
    
    return 0;
}