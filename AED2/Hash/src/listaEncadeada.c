#include "../include/listaEncadeada.h"  // Inclui o cabeçalho com a definição das estruturas e funções da lista encadeada
#include "../include/arquivo.h"          // Inclui funções de manipulação de arquivo (caso sejam usadas junto com listas)
#include <stdlib.h>                      // Para funções de alocação dinâmica (malloc, free)

// Cria e inicializa uma nova lista encadeada
Lista* criaListaEncadeada() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));  // Aloca memória para a estrutura da lista
    if (lista) {
        lista->prim = NULL;  // Inicializa o ponteiro para o primeiro elemento como NULL (lista vazia)
        lista->ult = NULL;   // Inicializa o ponteiro para o último elemento também como NULL
    }
    return lista;            // Retorna o ponteiro para a lista criada
}

// Libera toda a memória alocada pela lista encadeada
void liberaLista(Lista* lista) {
    TipoNo* atual = lista->prim;  // Começa do primeiro elemento da lista
    TipoNo* aux;

    // Percorre a lista liberando cada nó
    while (atual) {
        aux = atual->prox;   // Salva o próximo nó
        free(atual);         // Libera o nó atual
        atual = aux;         // Avança para o próximo nó
    }

    // Depois de liberar todos os nós, atualiza os ponteiros da lista
    lista->prim = NULL;
    lista->ult = NULL;
}

// Remove um elemento da lista com base na chave (atributo)
int removeLista(Lista *lista, int chave) {
    TipoNo *aux = lista->prim;      // Ponteiro auxiliar para percorrer a lista
    TipoNo *anterior = NULL;        // Ponteiro para guardar o nó anterior

    // Percorre a lista
    while (aux) {
        // Verifica se o nó atual contém a chave a ser removida
        if (aux->dado.atributo == chave) {
            if (anterior == NULL) {
                // Caso o elemento a ser removido seja o primeiro da lista
                lista->prim = aux->prox;  // Atualiza o primeiro da lista
                if (lista->prim == NULL) lista->ult = NULL;  // Se a lista ficar vazia, atualiza também o último
            } else {
                // Caso o elemento esteja no meio ou no final
                anterior->prox = aux->prox;  // Remove o nó atual da cadeia
                if (anterior->prox == NULL) lista->ult = anterior;  // Se era o último, atualiza o ponteiro ult
            }
            free(aux);  // Libera a memória do nó removido
            return 1;   // Retorna 1 para indicar que a remoção foi feita com sucesso
        }
        anterior = aux;   // Avança o ponteiro anterior
        aux = aux->prox;  // Avança para o próximo nó
    }

    return 0;  // Retorna 0 se o elemento com a chave não foi encontrado na lista
}

// Insere um novo elemento ao final da lista encadeada
void insereNaLista(Lista *lista, TipoDado dadoNovo) {
    TipoNo *novo = (TipoNo *) malloc(sizeof(TipoNo));  // Aloca um novo nó
    novo->dado = dadoNovo;   // Copia os dados para o novo nó
    novo->prox = NULL;       // O próximo do novo nó será NULL (pois será o último da lista)

    if (lista->ult == NULL) {
        // Caso a lista esteja vazia
        lista->prim = novo;   // O novo nó passa a ser o primeiro
        lista->ult = novo;    // E também o último
    } else {
        // Caso a lista já tenha elementos
        lista->ult->prox = novo;  // O último elemento aponta para o novo nó
        lista->ult = novo;         // Atualiza o ponteiro do último elemento
    }
}

// Realiza busca sequencial na lista encadeada por identificador (chave)
// Também conta o número de colisões (quantidade de nós visitados)
int buscaPorIdentificador(Lista *lista, int chave, int* colisao) {
    TipoNo *aux = lista->prim;  // Começa do início da lista
    while (aux) {
        (*colisao)++;  // Incrementa o contador de colisões a cada nó visitado
        if (aux->dado.atributo == chave) {
            // Se encontrar o elemento, retorna o número de registro armazenado no nó
            return aux->dado.numeroRegistro;
        }
        aux = aux->prox;  // Avança para o próximo nó
    }
    return -1;  // Retorna -1 se o elemento não for encontrado
}