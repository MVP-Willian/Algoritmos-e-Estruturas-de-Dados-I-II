#include "../include/arquivo.h"
#include "../include/hash.h"
#include "../include/listaEncadeada.h"

// Inclui bibliotecas padrão para entrada/saída, alocação de memória e manipulação de strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Abre um arquivo com o nome e modo especificados.
// Se falhar, imprime mensagem de erro e encerra o programa.
FILE* abrirArquivo(const char* nomeArquivo, const char* modo) {
    FILE *arquivo = fopen(nomeArquivo, modo);
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    return arquivo;
}

// Fecha um arquivo aberto.
// Caso ocorra erro, imprime mensagem e encerra o programa.
void fecharArquivo(FILE* ponteiroArquivo) {
    if (fclose(ponteiroArquivo) != 0) {
        perror("Erro ao fechar o arquivo");
        exit(1);
    }
}

// Escreve um registro em uma posição específica no arquivo.
// Usa fseek para posicionar o cursor no local correto (offset * tamanhoRegistro).
// Em caso de erro na escrita, mostra mensagem e encerra.
void escreverRegistro(FILE* arquivo, Registro *reg, long offset) {
    fseek(arquivo, offset * sizeof(Registro), SEEK_SET);
    size_t tamanhoEscrito = fwrite(reg, sizeof(Registro), 1, arquivo);
    if (tamanhoEscrito != 1) {
        perror("Erro ao escrever registro no arquivo");
        exit(1);
    }
}

// Adiciona um registro no final do arquivo.
// Move o cursor para o final com fseek e escreve o registro.
// Em caso de erro, mostra mensagem e encerra.
void adicionarRegistro(FILE* arquivo, Registro *reg) {
    fseek(arquivo, 0, SEEK_END);
    size_t tamanhoEscrito = fwrite(reg, sizeof(Registro), 1, arquivo);
    if (tamanhoEscrito != 1) {
        perror("Erro ao adicionar registro no arquivo");
        exit(1);
    }
}

// Lê um registro na posição especificada pelo offset.
// Usa fseek para posicionar o cursor antes da leitura.
// Se falhar na leitura, exibe mensagem de erro e encerra.
Registro lerRegistro(FILE* arquivo, long offset) {
    Registro reg;
    fseek(arquivo, offset * sizeof(Registro), SEEK_SET);
    size_t tamanhoLido = fread(&reg, sizeof(Registro), 1, arquivo);
    if (tamanhoLido != 1) {
        perror("Erro ao ler registro do arquivo");
        exit(1);
    }
    return reg;
}

// Lê um registro dado o número do registro (índice).
// Reusa a função lerRegistro para evitar duplicação de código.
Registro lerRegistroPorNumero(FILE* arquivo, int numeroRegistro) {
    return lerRegistro(arquivo, numeroRegistro);
}

// Obtém o número total de registros armazenados no arquivo.
// Move o cursor para o final, obtém a posição atual (tamanho em bytes),
// e divide pelo tamanho de um registro para calcular a quantidade.
int obterNumeroRegistros(FILE* arquivo) {
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    return tamanhoArquivo / sizeof(Registro);
}

// Gera um vetor de registros (alunos) com dados aleatórios.
// Gera nomes combinando arrays de nomes e sobrenomes.
// Gera cursos, idades, coeficientes e anos de ingresso aleatórios.
// Garante matrícula única incrementando e somando um valor randômico.
void geraAlunos(Registro alunos[], int qtd) {
    const char *nomes[] = {"Ana", "Carlos", "Fernanda", "João", "Mariana", "Lucas", "Camila", "Gabriel", "Beatriz", "Abel",
                           "Paula", "Ricardo", "Juliana", "Pedro", "David", "Rafael", "Sophia", "Felipe", "Isabela", "Eduardo",
                           "Claudia", "Felipe", "Thiago", "Michael", "Mikaelly", "Marcos", "Natasha", "Victor", "Leticia", "Julia", "Airton"};
    const char *sobrenomes[] = {"Silva", "Souza", "Costa", "Oliveira", "Pereira", "Almeida", "Santos", "Lima", "Rocha", "Martins",
                                "Gomes", "Carvalho", "Dias", "Ferreira", "Ribeiro", "Fernandes", "Mendes", "Barbosa", "Pinto", "Nascimento",
                                "Pedrosa", "Vieira", "Sena", "Mendonça", "Medeiros", "Chaparro", "Barreto", "Moura", "Bragas Caldas", "Saraiva"};
    const char *cursos[] = {"Engenharia", "Direito", "Medicina", "Arquitetura", "Psicologia", "Sistemas de Informacao",
                            "Biologia", "Quimica", "Fisica", "Administracao", "Matematica", "Farmacia", "Enfermagem", "Pedagogia",
                            "Publicidade", "Economia", "Sociologia", "Design", "Veterinaria", "Ciencia da Computacao"};

    // Primeiro registro com matrícula base fixa (exemplo)
    snprintf(alunos[0].nome, NOME_TAM, "%s %s", nomes[rand() % 31], sobrenomes[rand() % 30]);
    strcpy(alunos[0].curso, cursos[rand() % 20]);
    alunos[0].matricula = 20000000;
    alunos[0].idade = 18 + rand() % 13;
    alunos[0].coeficiente = (rand() % 1001);
    alunos[0].anoIngresso = 2015 + rand() % 10;

    for (int i = 1; i < qtd; i++) {
        // Matrícula única: incrementa a anterior somando um valor randômico
        alunos[i].matricula = alunos[i-1].matricula + 1 + rand()%1000;
        // Nome aleatório combinando nome e sobrenome
        snprintf(alunos[i].nome, NOME_TAM, "%s %s", nomes[rand() % 31], sobrenomes[rand() % 30]);
        // Curso aleatório
        strcpy(alunos[i].curso, cursos[rand() % 20]);
        // Idade entre 18 e 30 anos
        alunos[i].idade = 18 + rand() % 13;
        // Coeficiente entre 0 e 1000 (pode ser interpretado como 0.00 a 10.00)
        alunos[i].coeficiente = (rand() % 1001);
        // Ano de ingresso entre 2010 e 2023
        alunos[i].anoIngresso = 2010 + rand() % 14;
    }
}

// Imprime os dados de vários alunos do vetor.
// Exibe matrícula, nome, curso, idade, coeficiente (dividido por 100 para ficar em decimal), e ano ingresso.
void imprimeAlunos(Registro alunos[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Curso: %s\n", alunos[i].curso);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Coeficiente de Rendimento: %.2f\n", alunos[i].coeficiente/100.0);
        printf("Ano de Ingresso: %d\n", alunos[i].anoIngresso);
        printf("------------------------------------\n");
    }
}

// Imprime os dados de um aluno individual.
void imprimeAluno(Registro aluno) {
    printf("------------------------------------\n");
    printf("Matrícula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);
    printf("Curso: %s\n", aluno.curso);
    printf("Idade: %d\n", aluno.idade);
    printf("Coeficiente de Rendimento: %.2f\n", aluno.coeficiente/100.0);
    printf("Ano de Ingresso: %d\n", aluno.anoIngresso);
    printf("------------------------------------\n\n");
}

// Imprime todos os alunos de uma lista encadeada, lendo cada registro do arquivo.
// Usa o campo numeroRegistro armazenado no TipoDado para acessar o registro no arquivo.
void imprimeListaAlunos(Lista* alunos, FILE* arquivo){
    Registro aluno;
    for (TipoNo *aux = alunos->prim; aux; aux = aux->prox)
    {
        aluno = lerRegistroPorNumero(arquivo, aux->dado.numeroRegistro);
        imprimeAluno(aluno);
    }
}

// Salva um vetor de alunos no arquivo, adicionando-os sequencialmente no final.
void salvarVetorEmArquivo(Registro alunos[], FILE* arquivo, int qtd){
    for(int x = 0; x<qtd; x++){
        adicionarRegistro(arquivo, &(alunos[x]));
    }
}

// Busca sequencial no arquivo por coeficiente usando condição (modo).
// Modos: 0 = >, 1 = <, 2 = <=, 3 = >=
// Retorna uma lista encadeada com os registros que satisfazem a condição.
Lista *buscarSequencialCoeficiente(FILE *arquivo, int coef, unsigned modo) {
    if (!arquivo) return NULL;
    rewind(arquivo); // Retorna ao início do arquivo para leitura

    Registro temp;
    int pos = 0;

    // Aloca e inicializa uma lista para os resultados
    Lista *resultado = malloc(sizeof(Lista));
    if (!resultado) {
        perror("Erro de alocação da lista");
        return NULL;
    }
    resultado->prim = NULL;
    resultado->ult = NULL;

    // Lê registros um a um e verifica a condição
    while (fread(&temp, sizeof(Registro), 1, arquivo) == 1) {
        int cond = 0;
        switch (modo) {
            case 0: cond = temp.coeficiente > coef; break;
            case 1: cond = temp.coeficiente < coef; break;
            case 2: cond = temp.coeficiente <= coef; break;
            case 3: cond = temp.coeficiente >= coef; break;
            default: cond = 0; break;
        }

        if (cond) {
            TipoDado d;
            d.atributo = temp.coeficiente;
            d.numeroRegistro = pos;
            insereNaLista(resultado, d);
        }

        pos++;
    }

    return resultado;
}

// Busca sequencial no arquivo por matrícula exata.
// Retorna um ponteiro para um registro alocado dinamicamente se encontrado, NULL caso contrário.
Registro *buscaSequencialPorMatricula(FILE *arquivo, int chaveMatricula){
    Registro temp;
    rewind(arquivo);  // Garante leitura do início
    while (fread(&temp, sizeof(Registro), 1, arquivo) == 1) {
        if (temp.matricula == chaveMatricula){
            // Aloca e copia o registro encontrado para retornar
            Registro *encontrado = malloc(sizeof(Registro));
            if (encontrado == NULL) {
                perror("Erro de alocação");
                return NULL;
            }
            *encontrado = temp;
            return encontrado;
        }
    }
    return NULL; // Não encontrado
}