/*
Autores:
    Marcos Paulo Vieira Pedrosa
    Letícia Souza de Souza
    Michael Willian Pereira Vieira
    Mikaelle Costa de Santana
*/

#include "../include/arquivo.h"          // Inclui funções para manipulação de arquivos
#include "../include/hash.h"             // Inclui funções relacionadas à tabela hash
#include "../include/arvore.h"           // Inclui funções relacionadas à árvore binária
#include "../include/listaEncadeada.h"   // Inclui funções para manipulação de listas encadeadas
#include "../include/tempo.h"            // Inclui funções para cálculo de tempo de execução
#include <time.h>                        // Biblioteca padrão para manipulação de tempo
#include <stdio.h>                       // Biblioteca padrão de entrada/saída
#include <string.h>                      // Biblioteca para manipulação de strings
#include <stdlib.h>                      // Biblioteca para alocação de memória e funções utilitárias

#define NUM_TESTES 30                    // Número de execuções de cada tipo de consulta
#define QTD_ALUNOS 10000                 // Quantidade total de alunos no teste
#define TAM_TAB_HASH 2000               // Tamanho da tabela hash
#define PRCT_DESORDEM 50                 // Percentual de desordem aplicada ao vetor de alunos
#define PRCT_FORA 20                     // Percentual de buscas por chave inexistente

int main(){
    srand(time(NULL));                   // Inicializa o gerador de números aleatórios com base no tempo atual

    FILE* arquivo = abrirArquivo("alunos", "w+");                   // Abre o arquivo para armazenar alunos
    FILE *csv_matricula = abrirArquivo("dados_matricula.csv", "w+");       // Abre arquivo CSV para registrar resultados de busca por matrícula
    FILE *csv_coeficiente = abrirArquivo("dados_coeficiente.csv", "w+");   // Abre arquivo CSV para busca por coeficiente

    if (arquivo == NULL || csv_matricula == NULL || csv_coeficiente == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");    // Verifica se houve erro na abertura de algum arquivo
        return 1;
    }

    fprintf(csv_matricula, "Execuções, Tabela Hash (s), Árvore Binária de Pesquisa (s), Busca Sequencial (s), Chave, Colisões\n");  // Cabeçalho do CSV de matrícula
    fprintf(csv_coeficiente, "Execuções, Árvore Binária de Pesquisa (s), Busca Sequencial no arquivo (s), Maior ou Igual que\n"); // Cabeçalho do CSV de coeficiente

    Registro alunos[QTD_ALUNOS];                 // Vetor de registros de alunos
    geraAlunos(alunos, QTD_ALUNOS);              // Gera alunos com dados aleatórios

    int trocas = PRCT_DESORDEM * QTD_ALUNOS / 100;  // Calcula número de trocas para desordenar o vetor
    int j = 0;
    int indice;
    Registro aux;
    // Desordena parcialmente o vetor de alunos
    while (j < trocas){
        indice = rand()%QTD_ALUNOS;               // Seleciona índice aleatório
        aux = alunos[j];                          // Troca o aluno da posição j com o de índice aleatório
        alunos[j] = alunos[indice];
        alunos[indice] = aux;
        j++;
    }

    salvarVetorEmArquivo(alunos, arquivo, QTD_ALUNOS);   // Salva os registros de alunos no arquivo

    tipoHash hash;
    criaHash(&(hash), TAM_TAB_HASH);                    // Inicializa a tabela hash
    vetorEmHash(alunos, &hash, QTD_ALUNOS);             // Insere os alunos na hash

    ArvoreBin *arvoreMatricula;
    inicializaArvore(&arvoreMatricula);                 // Inicializa a árvore binária para matrícula
    vetorEmArvoreBinMatricula(alunos, &arvoreMatricula, QTD_ALUNOS, 0);  // Insere os alunos na árvore por matrícula

    ArvoreBin *arvoreCR;
    inicializaArvore(&arvoreCR);                        // Inicializa a árvore binária para coeficiente
    vetorEmArvoreBinCoeficiente(alunos, &arvoreCR, QTD_ALUNOS, 0);       // Insere os alunos na árvore por coeficiente

    Registro aleatorio;               // Registro aleatório para testes
    Registro alunoAux1;               // Auxiliar de registro
    Registro *alunoAux2;              // Ponteiro auxiliar para registro
    Lista *consultados;               // Lista de resultados para consultas por coeficiente
    int chaveAleatoria;               // Chave aleatória para consulta
    int coeficienteAleatorio;         // Coeficiente aleatório para consulta
    int n_registro;                   // Número do registro retornado
    int colisao;                      // Contador de colisões na hash

    clock_t tempoInicial_1, tempoInicial_2, tempoInicial_3, tempoInicial_4, tempoInicial_5;  // Marcação de tempo inicial de cada consulta
    clock_t tempoFinal_1, tempoFinal_2, tempoFinal_3, tempoFinal_4, tempoFinal_5;          // Marcação de tempo final
    double tempoTotal_hash, tempoTotal_arvore_matricula, tempoTotal_seq_matricula, tempoTotal_arvore_cr, tempoTotal_seq_cr;  // Tempo de execução das buscas
    double media_hash, media_arv_matricula, media_seq_matricula, media_arv_cr, media_seq_cr;  // Médias dos tempos

    double temposHash[NUM_TESTES];    // Array para guardar os tempos das buscas na hash
    double temposArvMatricula[NUM_TESTES]; // Tempos da árvore por matrícula
    double temposSeqMatricula[NUM_TESTES]; // Tempos da busca sequencial por matrícula
    double temposArvCr[NUM_TESTES];        // Tempos da árvore por coeficiente
    double temposSeqCR[NUM_TESTES];        // Tempos da busca sequencial por coeficiente

    for (int x = 1; x <= NUM_TESTES; x++)  // Loop para realizar 30 execuções de consulta por matrícula
    {
        printf("\n=== Consulta por Matricula: %d ===\n\n", x);
        if (rand() % 100 > PRCT_FORA)   // Decide se vai buscar um aluno que existe ou não
        {
            indice = rand()%QTD_ALUNOS;                          // Escolhe um aluno aleatório
            aleatorio = lerRegistroPorNumero(arquivo, indice);   // Lê o registro do arquivo
            chaveAleatoria = aleatorio.matricula;                // Usa a matrícula como chave
        }
        else{
            chaveAleatoria = 0;                                  // Gera uma chave que não existe
        }
        colisao = 0;

        tempoInicial_1 = clock();                                // Marca início da busca na hash
        n_registro = buscaNoHash(&hash, chaveAleatoria, &colisao); // Busca na hash
        tempoFinal_1 = clock();                                  // Marca fim da busca

        printf("Buscando aluno na tabela Hash.\n");

        tempoInicial_2 = clock();                                // Busca na árvore por matrícula
        n_registro = buscaArvoreBin(arvoreMatricula, chaveAleatoria);
        tempoFinal_2 = clock();
        printf("Buscando aluno na Arvore Binaria de Pesquisa.\n");

        tempoInicial_3 = clock();                                // Busca sequencial no arquivo
        alunoAux2 = buscaSequencialPorMatricula(arquivo, chaveAleatoria);
        tempoFinal_3 = clock();
        printf("Buscando aluno sequencialmente no arquivo. \n");

        if (alunoAux2){                                          // Se encontrou o aluno
            printf("------------------------------------\n");
            printf("Colisao da consulta na tabela Hash: %d\n", colisao);
            imprimeAluno(*alunoAux2);                            // Imprime os dados do aluno
        }
        else{
            printf("O aluno nao foi encontrado!\n");             // Caso não encontrado
        }

        tempoTotal_hash = calculaTempo(tempoInicial_1, tempoFinal_1);  // Calcula tempo da hash
        tempoTotal_arvore_matricula = calculaTempo(tempoInicial_2, tempoFinal_2);  // Da árvore
        tempoTotal_seq_matricula = calculaTempo(tempoInicial_3, tempoFinal_3);     // E da sequencial
        tempoTotal_arvore_cr = calculaTempo(tempoInicial_4, tempoFinal_4);         // (Zerado nesta fase)
        tempoTotal_seq_cr = calculaTempo(tempoInicial_5, tempoFinal_5);            // (Zerado também)

        temposHash[x-1] = tempoTotal_hash;                         // Guarda tempos
        temposArvMatricula[x-1] = tempoTotal_arvore_matricula;
        temposSeqMatricula[x-1] = tempoTotal_seq_matricula;

        fprintf(csv_matricula, "Execução %d:,        %.9f,        %.9f,        %.9f,        %d,        %d\n", x, tempoTotal_hash, tempoTotal_arvore_matricula, tempoTotal_seq_matricula, chaveAleatoria, colisao); // Escreve no CSV
    }

    media_hash = calculaMedia(temposHash, NUM_TESTES);                         // Calcula médias
    media_arv_matricula = calculaMedia(temposArvMatricula, NUM_TESTES);
    media_seq_matricula = calculaMedia(temposSeqMatricula, NUM_TESTES);

    printf("Media Tabela Hash: %.12f\n", media_hash);
    printf("Media Arvore Binaria de Pesquisa: %.12f\n", media_arv_matricula);
    printf("Media Busca Sequencial no arquivo: %.12f\n\n", media_seq_matricula);

    fprintf(csv_matricula, "Média (s),        %.9f,        %.9f,        %.9f\n", media_hash, media_arv_matricula, media_seq_matricula);  // Registra médias no CSV

    char ch;
    printf("Pressione ENTER para realizar as 30 consultas por >= :\n");    // Aguarda ENTER
    scanf("%c", &ch);
    printf("\033[H\033[J");                                                // Limpa tela (escape ANSI)

    for (int x = 1; x <= NUM_TESTES; x++){                                // Loop para buscas por coeficiente
        printf("=== Consulta por Coeficiente: %d ===\n\n", x);
        coeficienteAleatorio = rand() % 1001;                             // Gera coeficiente aleatório
        printf("Coeficiente >= %f\n\n", coeficienteAleatorio / 100.0);

        tempoInicial_4 = clock();                                         // Busca na árvore por coeficiente
        consultados = buscaPorDesigualdade(arvoreCR, 3, coeficienteAleatorio);
        tempoFinal_4 = clock();
        printf("Buscando aluno na Arvore Binaria de Pesquisa.\n");

        tempoInicial_5 = clock();                                         // Busca sequencial por coeficiente
        consultados = buscarSequencialCoeficiente(arquivo, coeficienteAleatorio, 3);
        tempoFinal_5 = clock();
        printf("Buscando aluno sequencialmente no arquivo.\n\n");

        if (consultados){                                                 // Se encontrou alunos
            imprimeListaAlunos(consultados, arquivo);                     // Imprime a lista
        }
        else{
            printf("Nenhum aluno foi encontrado!\n\n");
        }

        tempoTotal_arvore_cr = calculaTempo(tempoInicial_4, tempoFinal_4);  // Calcula tempos
        tempoTotal_seq_cr = calculaTempo(tempoInicial_5, tempoFinal_5);

        temposArvCr[x-1] = tempoTotal_arvore_cr;                           // Armazena tempos
        temposSeqCR[x-1] = tempoTotal_seq_cr;

        fprintf(csv_coeficiente, "Execução %d:,        %.9f,        %.9f,        %.2f\n", x, tempoTotal_arvore_cr, tempoTotal_seq_cr, coeficienteAleatorio/100.0);  // Registra resultados
    }

    media_arv_cr = calculaMedia(temposArvCr, NUM_TESTES);                  // Calcula médias finais
    media_seq_cr = calculaMedia(temposSeqCR, NUM_TESTES);

    printf("Media Arvore Binaria de Pesquisa: %.12f\n", media_arv_cr);
    printf("Media Busca Sequencial no arquivo: %.12f\n", media_seq_cr);

    fprintf(csv_coeficiente, "Média (s),        %.9f,        %.9f\n", media_arv_cr, media_seq_cr);  // Registra no CSV

    fclose(arquivo);
    fclose(csv_matricula);
    fclose(csv_coeficiente);

    return 0;   // Finaliza o programa
}