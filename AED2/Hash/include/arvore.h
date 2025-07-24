#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_iNCLUDED

#include "../include/listaEncadeada.h"
#include "../include/arquivo.h"

// Define a estrutura opaca ArvoreBin, que será implementada no .c
typedef struct ArvoreBin ArvoreBin;

/**
 * Busca um valor em uma árvore binária.
 * Retorna um ponteiro para o nó encontrado ou NULL se não existir.
 */
int buscaArvoreBin(ArvoreBin* raiz, int valor);

/**
 * Retorna a altura da árvore binária.
 */
int altura(ArvoreBin *arvore);

/**
 * Inicializa a árvore, atribuindo NULL à raiz.
 */
void inicializaArvore(ArvoreBin** raiz);

/**
 * Insere um valor na árvore binária (permite duplicatas).
 */
void insereArvoreBinaria(ArvoreBin** ptrRaiz, TipoDado valor);

/**
 * Realiza percurso pós-ordem na árvore e imprime os valores.
 */
void caminhaPos(ArvoreBin* raiz);

/**
 * Realiza percurso pré-ordem na árvore e imprime os valores.
 */
void caminhaPre(ArvoreBin* raiz);

/**
 * Realiza percurso em-ordem (central) na árvore e imprime os valores.
 */
void caminhaCentral(ArvoreBin* raiz);

/**
 * Insere todos os elementos de um vetor na árvore binária.
 * Se opcao == 0, insere com duplicatas; se opcao != 0, evita duplicatas.
 */
void vetorEmArvoreBinMatricula(Registro* vetor, ArvoreBin** ptrRaiz, int tam, int opcao);

void vetorEmArvoreBinCoeficiente(Registro *vetor, ArvoreBin **ptrRaiz, int tam, int opcao);

/**
 * Libera toda a memória alocada para a árvore binária.
 */
void liberaArvore(ArvoreBin* raiz);
/**
 * Insere um valor na árvore binária apenas se ele ainda não existir (sem duplicatas).
 */
void insereArvoreBinSemDuplicata(ArvoreBin** ptrRaiz, TipoDado valor);

static void buscaRecursiva(ArvoreBin* no, unsigned modo, int coefComparador, Lista *resultado);

Lista* buscaPorDesigualdade(ArvoreBin* ptrRaiz, unsigned modo, int coeficiente);
#endif
