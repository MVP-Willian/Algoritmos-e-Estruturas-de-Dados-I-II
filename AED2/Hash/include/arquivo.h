#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

// Inclusão das bibliotecas padrão e do cabeçalho da lista encadeada
#include <stdio.h>
#include "../include/listaEncadeada.h"

// Define o tamanho máximo para os campos de nome e curso
#define NOME_TAM 50
#define CURSO_TAM 30

// Estrutura que representa um registro de aluno
typedef struct {
    int matricula;             // Chave primária única que identifica o aluno
    char nome[NOME_TAM];       // Nome completo do aluno
    char curso[CURSO_TAM];     // Curso que o aluno está matriculado (ex: Engenharia, Direito)
    int idade;                 // Idade do aluno, útil para buscas e filtros
    int coeficiente;           // Coeficiente de rendimento (CR) do aluno (ex: notas, desempenho)
    int anoIngresso;           // Ano de ingresso do aluno na instituição
} Registro;

// Abre um arquivo com o nome e modo especificados (ex: "rb", "wb")
// Retorna um ponteiro para o arquivo aberto ou encerra o programa em caso de erro
FILE* abrirArquivo(const char* nomeArquivo, const char* modo);

// Fecha o arquivo apontado pelo ponteiro fornecido, tratando erros de fechamento
void fecharArquivo(FILE* ponteiroArquivo);

// Escreve um registro no arquivo na posição especificada pelo offset (em número de registros)
// Usa fseek para posicionar e fwrite para gravar
void escreverRegistro(FILE* arquivo, Registro *reg, long offset);

// Adiciona um registro no final do arquivo (append)
void adicionarRegistro(FILE* arquivo, Registro *reg);

// Lê um registro do arquivo na posição indicada pelo offset (número do registro)
// Retorna uma cópia do registro lido
Registro lerRegistro(FILE* arquivo, long offset);

// Função auxiliar que lê um registro pelo número do registro (mesma funcionalidade do lerRegistro)
Registro lerRegistroPorNumero(FILE* arquivo, int numeroRegistro);

// Retorna a quantidade total de registros existentes no arquivo, calculando pelo tamanho do arquivo
int obterNumeroRegistros(FILE* arquivo);

// Gera um vetor de registros de alunos com dados aleatórios para testes
// Preenche os campos de nome, matrícula, curso, idade, coeficiente e ano de ingresso
void geraAlunos(Registro alunos[], int qtd);

// Imprime no console a lista completa de alunos recebida no vetor
void imprimeAlunos(Registro alunos[], int qtd);

// Imprime no console os dados de um único aluno
void imprimeAluno(Registro aluno);

// Imprime os alunos armazenados na lista encadeada, buscando os registros no arquivo
void imprimeListaAlunos(Lista *alunos, FILE *arquivo);

// Salva um vetor de registros no arquivo, adicionando um a um no final
void salvarVetorEmArquivo(Registro alunos[], FILE *arquivo, int qtd);

// Realiza busca sequencial no arquivo para encontrar o registro com a matrícula informada
// Retorna um ponteiro para o registro encontrado (alocado dinamicamente) ou NULL se não encontrar
Registro *buscaSequencialPorMatricula(FILE *arquivo, int chaveMatricula);

// Busca sequencial no arquivo filtrando registros pelo coeficiente de rendimento com base no modo:
// modo 0 = coeficiente > valor
// modo 1 = coeficiente < valor
// modo 2 = coeficiente <= valor
// modo 3 = coeficiente >= valor
// Retorna uma lista encadeada com os registros encontrados
Lista *buscarSequencialCoeficiente(FILE *arquivo, int coef, unsigned modo);

#endif