#include "../include/hash.h"          // Inclui o arquivo de cabeçalho com as definições da estrutura de hash
#include "../include/arquivo.h"       // Inclui o cabeçalho com definições relacionadas a manipulação de arquivos
#include "../include/listaEncadeada.h"// Inclui o cabeçalho da lista encadeada usada nas colisões da tabela hash
#include <stdlib.h>                   // Biblioteca padrão para uso de malloc e NULL

// Função para criar e inicializar uma tabela hash
void criaHash(tipoHash *h, unsigned tamanho) {
    // Aloca dinamicamente memória para o vetor de listas encadeadas (uma lista para cada posição da tabela hash)
    h->tabHash = (Lista*) malloc(sizeof(Lista) * tamanho);
    if (h->tabHash == NULL) {
        // Se a alocação falhar, apenas retorna (a estrutura ficará inconsistente se não tratar isso depois)
        // Poderia incluir aqui uma mensagem de erro
        return;
    }

    // Inicializa todas as listas da tabela hash como vazias (ponteiros prim e ult = NULL)
    for (int x = 0; x < tamanho; x++) {
        h->tabHash[x].prim = NULL;  // Primeiro elemento da lista
        h->tabHash[x].ult = NULL;   // Último elemento da lista
    }

    h->numElem = 0;                // Inicializa contador de elementos na tabela
    h->tamanhoTabHash = tamanho;   // Salva o tamanho da tabela
}

// Função para inserir um registro na tabela hash
void insereNoHash(tipoHash *h, Registro novo, int numeroReg) {
    // Calcula a posição da tabela usando hashing simples: resto da matrícula pelo tamanho da tabela
    unsigned pos = novo.matricula % h->tamanhoTabHash;
    int x = 0;

    // Faz uma busca na lista dessa posição para evitar inserir duplicatas
    if (buscaPorIdentificador(&(h->tabHash[pos]), novo.matricula, &x) == -1) {
        // Se não encontrou, cria um novo elemento para inserir
        TipoDado dadoNovo;
        dadoNovo.atributo = novo.matricula;      // A chave de busca será a matrícula
        dadoNovo.numeroRegistro = numeroReg;     // Salva a posição (linha) do registro no arquivo original
        insereNaLista(&(h->tabHash[pos]), dadoNovo);  // Insere na lista correspondente
        h->numElem++;                            // Atualiza a contagem de elementos da tabela
    }
}

// Função para remover um elemento da tabela hash pela chave (matrícula)
int removeHash(tipoHash *h, int chave) {
    unsigned pos = chave % h->tamanhoTabHash;    // Calcula a posição na tabela
    int removido = removeLista(&(h->tabHash[pos]), chave); // Tenta remover da lista encadeada da posição
    if (removido) {
        h->numElem--;                            // Se removeu com sucesso, atualiza o contador de elementos
    }
    return removido;                             // Retorna 1 se removeu, 0 se não encontrou
}

// Função para buscar um elemento na tabela hash
// Recebe a chave (matrícula) e um ponteiro para contar colisões
int buscaNoHash(tipoHash *h, int chave, int* colisao) {
    unsigned pos = chave % h->tamanhoTabHash;    // Calcula a posição na tabela
    return buscaPorIdentificador(&(h->tabHash[pos]), chave, colisao);  // Busca na lista encadeada da posição
}

// Função que insere todos os registros de um vetor na tabela hash
void vetorEmHash(Registro* alunos, tipoHash* hash, int qtd) {
    for (int x = 0; x < qtd; x++) {
        // Para cada registro do vetor, insere na hash (posição no arquivo é o índice do vetor)
        insereNoHash(hash, alunos[x], x);
    }
}