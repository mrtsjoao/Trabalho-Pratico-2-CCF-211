#ifndef cartas.h
#define cartas.h

typedef struct Cartas
{
    char valor[1];
    char naipe[1];
} card;


typedef struct No {
    card carta;
    struct No* proximo;
} No;

void adicionarCarta(No** lista, card carta);
void liberarLista(No* lista);
int preencheBaralho();
int compararCartas(const void* a, const void* b);
void ordenarBaralho(No* baralho, int tamanho);



#endif //cartas.h