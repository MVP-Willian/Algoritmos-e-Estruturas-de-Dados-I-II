#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

// Estrutura que representa um dado da lista
typedef struct TipoDado{
    int atributo;         // Chave que será usada para buscas (ex: matrícula)
    int numeroRegistro;   // Número do registro (posição no arquivo, etc)
} TipoDado;

// Nó da lista encadeada
typedef struct TipoNo {
    TipoDado dado;           // Conteúdo armazenado no nó
    struct TipoNo* prox;     // Ponteiro para o próximo nó
} TipoNo;

// Estrutura da lista encadeada
typedef struct Lista{
    TipoNo* prim;  // Ponteiro para o primeiro elemento da lista
    TipoNo* ult;   // Ponteiro para o último elemento da lista
} Lista;

// Funções da lista encadeada:

// Cria e inicializa uma nova lista
Lista* criaListaEncadeada();

// Libera toda a memória ocupada pela lista
void liberaLista(Lista* lista);

// Insere um novo elemento ao final da lista
void insereNaLista(Lista *lista, TipoDado dadoNovo);

// Remove um elemento da lista, com base na chave. Retorna 1 se removeu, 0 se não encontrou
int removeLista(Lista *lista, int chave);

// Busca um elemento pelo identificador (atributo)
// Retorna o número de registro correspondente, ou -1 se não encontrar
// A variável colisao é incrementada a cada comparação (conta colisões em tabelas hash)
int buscaPorIdentificador(Lista *lista, int chave, int* colisao);

#endif
