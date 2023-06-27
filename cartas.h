#ifndef cartas.h
#define cartas.h

typedef struct Cartas
{
    char valor[4];
    char naipe[3];
} card;


typedef struct No {
    card carta;
    struct No* proximo;
} No;

No* criarNo(card carta);
void adicionarCarta(No** lista, card carta);
void liberarLista(No* lista);
//int preencheBaralho();
int compararCartas(const void* a, const void* b);
void ordenarBaralho(No* baralho, int tamanho);
void adicionarCartaPilha(No** pilha, card carta);
void embaralharCartas(No** pilha, No** baralho, int tamanho);
void liberarPilha(No* pilha);



#endif //cartas.h