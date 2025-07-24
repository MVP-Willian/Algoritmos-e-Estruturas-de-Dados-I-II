#include "../include/arvore.h"
#include "../include/listaEncadeada.h"
#include "../include/arquivo.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura que representa um nó da árvore binária
typedef struct ArvoreBin
{
    struct ArvoreBin *esquerda; // Ponteiro para subárvore esquerda
    struct ArvoreBin *direita;  // Ponteiro para subárvore direita
    TipoDado dado;              // Valor armazenado no nó (contendo atributo e número de registro)
} ArvoreBin;

/**
 * Calcula a altura de uma árvore binária.
 * Retorna 0 se a árvore for vazia.
 */
int altura(ArvoreBin *arvore){
    if(arvore == NULL) // Árvore vazia tem altura 0
    {
        return 0;
    }
    else{
        // Calcula altura da subárvore esquerda
        int alt_Esq = altura(arvore->esquerda);
        // Calcula altura da subárvore direita
        int alt_Dir = altura(arvore->direita);
        int alt;
        // A altura da árvore é 1 + altura máxima das subárvores
        if(alt_Esq > alt_Dir){
            alt = alt_Esq;
        }
        else{
            alt = alt_Dir;
        }
        return 1 + alt;
    }
}

/**
 * Inicializa uma árvore binária definindo a raiz como NULL (árvore vazia).
 */
void inicializaArvore(ArvoreBin **raiz)
{
    *raiz = NULL;
}

/**
 * Insere um valor em uma árvore binária iterativamente.
 * Permite duplicatas (valores iguais ficam no lado direito).
 */
void insereArvoreBinaria(ArvoreBin **ptrRaiz, TipoDado valor)
{
    ArvoreBin *aux = *ptrRaiz;
    while ((aux)) // Desce na árvore até encontrar um nó NULL
    {
        if (aux->dado.atributo > valor.atributo)
        {
            ptrRaiz = &(aux->esquerda); // Vai para esquerda se valor menor
        }
        else
        {
            ptrRaiz = &(aux->direita); // Senão vai para direita (incluindo duplicatas)
        }
        aux = *ptrRaiz;
    }

    // Aloca novo nó
    *ptrRaiz = (ArvoreBin *)malloc(sizeof(ArvoreBin));
    // Inicializa subárvores esquerda e direita como vazias
    inicializaArvore(&((*ptrRaiz)->esquerda));
    inicializaArvore(&((*ptrRaiz)->direita));
    // Atribui o valor ao nó criado
    (*ptrRaiz)->dado = valor;
}

/**
 * Busca um valor na árvore binária.
 * Retorna o número de registro se encontrado, ou -1 se não encontrado.
 */
int buscaArvoreBin(ArvoreBin *raiz, int valor)
{
    ArvoreBin *aux = raiz;
    while (aux != NULL)
    {
        if (aux->dado.atributo > valor)
        {
            aux = aux->esquerda;  // Vai para esquerda se valor menor
        }
        else if (aux->dado.atributo < valor)
        {
            aux = aux->direita;   // Vai para direita se valor maior
        }
        else
        {
            return aux->dado.numeroRegistro; // Encontrou o valor, retorna registro
        }
    }
    return -1; // Não encontrado
}

/**
 * Percorre a árvore em pós-ordem (esquerda, direita, raiz) e imprime os valores.
 */
void caminhaPos(ArvoreBin *raiz)
{
    if (raiz == NULL)
        return;
    caminhaPos(raiz->esquerda);
    caminhaPos(raiz->direita);
    printf("%d ", raiz->dado.atributo);
}

/**
 * Percorre a árvore em pré-ordem (raiz, esquerda, direita) e imprime os valores.
 */
void caminhaPre(ArvoreBin *raiz)
{
    if (raiz == NULL)
        return;
    printf("%d ", raiz->dado.atributo);
    caminhaPre(raiz->esquerda);
    caminhaPre(raiz->direita);
}

/**
 * Percorre a árvore em ordem central (esquerda, raiz, direita) e imprime os valores.
 */
void caminhaCentral(ArvoreBin *raiz)
{
    if (raiz == NULL)
        return;
    caminhaCentral(raiz->esquerda);
    printf("%d ", raiz->dado.atributo);
    caminhaCentral(raiz->direita);
}

/**
 * Insere elementos de um vetor na árvore binária com base na matrícula.
 * Se opcao == 0, permite duplicatas. Se != 0, evita duplicatas.
 */
void vetorEmArvoreBinMatricula(Registro* vetor, ArvoreBin **ptrRaiz, int tam, int opcao)
{
    for (int i = 0; i < tam; i++)
    {
        TipoDado aux;
        aux.atributo = vetor[i].matricula;   // Usa matrícula como chave
        aux.numeroRegistro = i;               // Número do registro (posição no vetor)
        if(opcao == 0)
        {
            insereArvoreBinaria(ptrRaiz, aux);
        }
        else
        {
            insereArvoreBinSemDuplicata(ptrRaiz, aux);
        }
    }
}

/**
 * Insere elementos de um vetor na árvore binária com base no coeficiente.
 * Se opcao == 0, permite duplicatas. Se != 0, evita duplicatas.
 */
void vetorEmArvoreBinCoeficiente(Registro* vetor, ArvoreBin **ptrRaiz, int tam, int opcao)
{
    for (int i = 0; i < tam; i++)
    {
        TipoDado aux;
        aux.atributo = vetor[i].coeficiente; // Usa coeficiente como chave
        aux.numeroRegistro = i;
        if(opcao == 0)
        {
            insereArvoreBinaria(ptrRaiz, aux);
        }
        else
        {
            insereArvoreBinSemDuplicata(ptrRaiz, aux);
        }
    }
}

/**
 * Libera a memória de toda a árvore (liberação pós-ordem).
 */
void liberaArvore(ArvoreBin *raiz)
{
    if (raiz == NULL)
        return;
    liberaArvore(raiz->esquerda);
    liberaArvore(raiz->direita);
    free(raiz);
}

/**
 * Insere valor na árvore binária **sem duplicatas**.
 * Se o valor já existe, não insere.
 */
void insereArvoreBinSemDuplicata(ArvoreBin **ptrRaiz, TipoDado valor)
{
    ArvoreBin *aux = *ptrRaiz;
    while ((aux))
    {
        if (aux->dado.atributo > valor.atributo)
        {
            ptrRaiz = &(aux->esquerda);
        }
        else if(aux->dado.atributo < valor.atributo)
        {
            ptrRaiz = &(aux->direita);
        }
        else {
            return; // valor já existe, não insere
        }
        aux = *ptrRaiz;
    }

    *ptrRaiz = (ArvoreBin *)malloc(sizeof(ArvoreBin));
    inicializaArvore(&((*ptrRaiz)->esquerda));
    inicializaArvore(&((*ptrRaiz)->direita));
    (*ptrRaiz)->dado = valor;
}

/**
 * Função recursiva auxiliar para busca na árvore por desigualdade (> , < , >= , <=).
 * Insere os elementos que satisfazem a condição na lista resultado.
 */
static void buscaRecursiva(ArvoreBin* no, unsigned modo, int coefComparador, Lista *resultado) {
    if (no == NULL) return;

    int inserir = 0;

    switch (modo) {
        case 0: // >
            if (no->dado.atributo > coefComparador) {
                inserir = 1;
                buscaRecursiva(no->esquerda, modo, coefComparador, resultado); // Subárvore esquerda pode conter valores maiores
            }
            buscaRecursiva(no->direita, modo, coefComparador, resultado); // Sempre pode ter maiores na direita
            break;

        case 1: // <
            if (no->dado.atributo < coefComparador) {
                inserir = 1;
                buscaRecursiva(no->direita, modo, coefComparador, resultado); // Pode ter mais valores menores na direita?
            }
            buscaRecursiva(no->esquerda, modo, coefComparador, resultado); // Sempre pode ter menores na esquerda
            break;

        case 2: // <=
            if (no->dado.atributo <= coefComparador) {
                inserir = 1;
                buscaRecursiva(no->direita, modo, coefComparador, resultado);
            }
            buscaRecursiva(no->esquerda, modo, coefComparador, resultado);
            break;

        case 3: // >=
            if (no->dado.atributo >= coefComparador) {
                inserir = 1;
                buscaRecursiva(no->esquerda, modo, coefComparador, resultado);
            }
            buscaRecursiva(no->direita, modo, coefComparador, resultado);
            break;

        default:
            break;
    }

    if (inserir) {
        insereNaLista(resultado, no->dado); // Insere o dado na lista resultado
    }
}

/**
 * Busca na árvore todos os elementos que satisfazem a desigualdade indicada pelo modo e coefComparador.
 * Modo: 0 = >, 1 = <, 2 = <=, 3 = >=.
 * Retorna uma lista encadeada com os resultados.
 */
Lista* buscaPorDesigualdade(ArvoreBin* ptrRaiz, unsigned modo, int coefComparador) {
    Lista* resultado = malloc(sizeof(Lista));
    criaListaEncadeada(resultado);
    buscaRecursiva(ptrRaiz, modo, coefComparador, resultado);

    return resultado;
}