#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void adicionarCartaPilha(No** pilha, card carta) {
    No* novoNo = criarNo(carta);
    
    novoNo->proximo = *pilha;
    *pilha = novoNo;
}


void embaralharCartas(No** pilha, No** baralho, int tamanho) {
    srand(time(NULL));
    
    for (int i = tamanho - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        
        No* carta = baralho[i];
        
        adicionarCartaPilha(pilha, carta->carta);
        
        // Remove a carta embaralhada do baralho
        baralho[i] = baralho[j];
        baralho[j] = carta;
    }
}

void liberarPilha(No* pilha) {
    No* atual = pilha;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}



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
        printf("[%s %s]\n",atual->carta.valor, atual->carta.naipe);
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