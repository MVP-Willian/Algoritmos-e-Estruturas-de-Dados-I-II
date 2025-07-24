#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "../include/listaEncadeada.h"
#include "../include/arquivo.h"

typedef struct {
    Lista* tabHash;       // Vetor de listas encadeadas (uma lista por posição da tabela)
    unsigned tamanhoTabHash; // Tamanho da tabela hash (número de posições)
    unsigned numElem;        // Quantidade total de elementos inseridos
} tipoHash;

// Cria a tabela hash com o tamanho especificado
void criaHash(tipoHash *h, unsigned tamanho);

// Insere um registro na tabela hash
void insereNoHash(tipoHash *h, Registro novo, int numeroReg);

// Remove um elemento da hash com base na chave (matrícula)
int removeHash(tipoHash *h, int chave);

// Busca por uma chave na hash, retorna o número do registro ou -1 se não encontrar
int buscaNoHash(tipoHash *h, int chave, int* colisao);

// Transforma um vetor de registros em uma hash
void vetorEmHash(Registro* alunos, tipoHash* hash, int qtd);

#endif
