#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cartas.h"

No* criarNo(card carta) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->carta = carta;
    novoNo->proximo = NULL;
    return novoNo;
}

void adicionarCarta(No** lista, card carta) {
    No* novoNo = criarNo(carta);
    
    if (*lista == NULL) {
        *lista = novoNo;
    } else {
        No* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

void liberarLista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int compararCartas(const void* a, const void* b) {
    const No* cartaA = (const No*)a;
    const No* cartaB = (const No*)b;
    
    // Primeiro, comparar os naipes
    int comparacaoNaipe = strcmp(cartaA->carta.naipe, cartaB->carta.naipe);
    if (comparacaoNaipe != 0) {
        return comparacaoNaipe;
    }
    
    // Se os naipes são iguais, comparar os valores
    return strcmp(cartaA->carta.valor, cartaB->carta.valor);
}

void ordenarBaralho(No* baralho, int tamanho) {
    qsort(baralho, tamanho, sizeof(No), compararCartas);
}

/*int preencheBaralho() {
    No* lista = NULL;
    
    // Montando o baralho com todas as cartas
    char naipes[4] = {"C", "O", "P", "E"};
    char valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            card carta;
            strcpy(carta.naipe, naipes[i]);
            strcpy(carta.valor, valores[j]);
            adicionarCarta(&lista, carta);
        }
    }
}*/