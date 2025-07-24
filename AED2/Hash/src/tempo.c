#include <stdio.h>   // Para funções de entrada/saída como printf
#include <time.h>    // Para medir tempo usando clock_t
#include <math.h>    // Para funções matemáticas como pow e sqrt

// Calcula o tempo decorrido (em segundos) entre dois instantes de clock
double calculaTempo(clock_t inicial, clock_t final)
{
    // Diferença de clocks dividida pela constante CLOCKS_PER_SEC para converter para segundos
    return (double)(final - inicial) / CLOCKS_PER_SEC;
}

// Calcula a média dos valores de um vetor de doubles
double calculaMedia(double *tempos, int tamanho)
{
    double media = 0;
    // Percorre o vetor somando todos os valores
    for (int x = 0; x < tamanho; x++)
    {
        media += tempos[x];  // Soma dos elementos
    }
    // Se o tamanho for maior que zero, calcula e retorna a média
    if (tamanho)
    {
        return media / tamanho;  // Média aritmética
    }
    // Caso o tamanho seja zero (para evitar divisão por zero), retorna -1 como valor de erro
    return -1;
}

// Calcula o desvio padrão dos valores de um vetor de doubles
double calculaDesvioPadrao(double *tempos, double media, int tamanho)
{
    double soma = 0;
    // Calcula a soma dos quadrados das diferenças entre cada valor e a média
    for (int x = 0; x < tamanho; x++)
    {
        soma += pow(tempos[x] - media, 2);  // (xi - media)²
    }
    // Se o tamanho for maior que zero, calcula e retorna o desvio padrão
    if (tamanho)
    {
        return sqrt(soma / tamanho);  // Raiz quadrada da média das diferenças quadradas
    }
    // Caso o tamanho seja zero (para evitar divisão por zero), retorna -1 como valor de erro
    return -1;
}

// Exibe os valores de um vetor de doubles no formato [x, y, z, ...]
void mostraVetorDouble(double* vetor, int tamanho)
{
    printf("[");  // Abre colchete para iniciar a exibição do vetor

    if (tamanho)
    {
        printf("%f", vetor[0]);  // Imprime o primeiro elemento (sem vírgula antes dele)
    }

    // Imprime os demais elementos separados por vírgula
    for (int x = 1; x < tamanho; x++)
    {
        printf(", %f", vetor[x]);  // Imprime vírgula seguida do valor
    }

    printf("]");  // Fecha colchete ao final da impressão
}