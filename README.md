# Algoritmos-e-Estruturas-de-Dados

Este repositório reúne materiais, códigos e implementações desenvolvidas durante as disciplinas **Algoritmos e Estruturas de Dados I (AED I)** e **Algoritmos e Estruturas de Dados II (AED II)**.  

Ele está organizado em dois diretórios principais:  
- **`Algoritmos AED1`**: Contém todos os **algoritmos básicos** estudados em AED I.  
- **`AED2`**: Contém **trabalhos e projetos** relacionados a estruturas de dados estudadas em AED II.

---

## 📂 Estrutura do Repositório

```bash
├── Algoritmos AED1/
│   ├── Teste_Algoritmos.c
│   ├── bolha.c
│   ├── buscaBinaria.c
│   ├── buscaLinear.c
│   ├── inserctionSort.c
│   ├── kNN.c
│   ├── mergeSort.c
│   ├── quickSort.c
└   └── selectionSort.c

├── AED2/
│   ├── Arvores/
│   │   ├── arvore.c
│   │   ├── teste
│   │   └── teste.exe
│   ├── Comparação algoritmos/
│   │   ├── bin/
│   │   │    ├── questao01
│   │   │    ├── questao02
│   │   │    ├── questao03
│   │   │    └── questao05
│   │   ├── include/
│   │   │    ├── ferramentas.h
│   │   │    ├── listaEncadea.h
│   │   │    └── vet.h
│   │   ├── src/
│   │   │    ├── ferramentas.c
│   │   │    ├── grafios.py
│   │   │    ├── listaEncadeada.c
│   │   │    ├── questao01.c
│   │   │    ├── questao02.c
│   │   │    ├── questao03.c
│   │   │    ├── questao05.c
│   │   │    └── vet.c
│   │   ├── Makefile
│   │   ├── README.md
│   │   ├── dados_1.csv
│   │   ├── dados_2.csv
│   │   ├── dados_3.csv
│   │   ├── dados_5.csv
│   │   └── trab01-aed2.pdf
│   ├── Arvores_Avl_Binaria/
│   │   ├── bin/
│   │   │    ├── questao01
│   │   │    ├── questao02
│   │   │    ├── questao03
│   │   │    └── questao04
│   │   ├── include/
│   │   │    ├── arvore.h
│   │   │    ├── avl.h
│   │   │    ├── pacotes.h
│   │   │    ├── tempo.h
│   │   │    └── vet.h
│   │   ├── src/
│   │   │    ├── arvore.c
│   │   │    ├── avl.c
│   │   │    ├── pacotes.c
│   │   │    ├── questao01.c
│   │   │    ├── questao02.c
│   │   │    ├── questao03.c
│   │   │    ├── questao04.c
│   │   │    ├── tempo.c
│   │   │    └── vet.c
│   │   ├── Makefile
│   │   ├── README.md
│   │   ├── dados1_4.csv
│   │   ├── dados2_4.csv
│   │   ├── dados_3.csv
│   │   ├── entrada.txt
│   │   ├── saida.txt
│   │   └── trab02-aed2.pdf
│   ├── Hash/
│   │   ├── include/
│   │   │    ├── arquivo.h
│   │   │    ├── arvore.h
│   │   │    ├── hash.h
│   │   │    ├── listaEncadeada.h
│   │   │    └── vet.h
│   │   ├── src/
│   │   │    ├── alunos
│   │   │    ├── arquivo.c
│   │   │    ├── arvore.c
│   │   │    ├── hash.c
│   │   │    ├── listaEncadeada.c
│   │   │    ├── main.c
│   │   │    ├── teste
│   │   │    └── vet.c
│   │   └── notas.txt
│   ├── Grafos/
│   │   ├── include/
│   │   │    ├── grafo.h
│   │   │    └── lista.h
│   │   ├── src/
│   │   │    ├── exemplo_main.c
│   │   │    ├── grafo.c
│   │   │    ├── lista.c
│   │   │    ├── main_questao04.c
│   │   │    ├── main_questao05.c
│   │   │    └── main_questao123.c
│   │   ├── tempos_bfs.csv
│   │   ├── tempos_dfs.csv
└   └   └── trab4_aed2.pdf
```

## 📊 Detalhes dos Algoritmos de Busca e Ordenação (`Algoritmos AED1`)

Abaixo estão descrições técnicas dos algoritmos implementados na pasta `Algoritmos AED1`, com foco em **complexidade**, **casos de uso ideais** e **características gerais**:

### 🔍 Algoritmos de Busca

| Algoritmo       | Complexidade Melhor Caso | Médio Caso | Pior Caso | Quando Usar |
|-----------------|--------------------------|------------|-----------|-------------|
| **Busca Linear** | O(1)                     | O(n)       | O(n)      | Listas pequenas ou não ordenadas. Fácil implementação. |
| **Busca Binária**| O(1)                     | O(log n)   | O(log n)  | Listas ordenadas. Muito eficiente em buscas sucessivas. |

---

### 🔃 Algoritmos de Ordenação

| Algoritmo        | Melhor Caso | Médio Caso | Pior Caso | Estável | In-place | Quando Usar |
|------------------|-------------|------------|-----------|---------|----------|-------------|
| **Bubble Sort**      | O(n)        | O(n²)      | O(n²)     | Sim     | Sim      | Ensino, simplicidade. Pouco eficiente. |
| **Insertion Sort**   | O(n)        | O(n²)      | O(n²)     | Sim     | Sim      | Listas pequenas ou quase ordenadas. Razoável em prática. |
| **Selection Sort**   | O(n²)       | O(n²)      | O(n²)     | Não     | Sim      | Pouco uso prático. Simples e previsível. |
| **Quick Sort**       | O(n log n)  | O(n log n) | O(n²)     | Não     | Sim      | Um dos mais rápidos na prática. Ideal para grandes volumes. |
| **Merge Sort**       | O(n log n)  | O(n log n) | O(n log n)| Sim     | Não      | Quando estabilidade e desempenho são importantes. |

---

✅ **Observação:** Todos os algoritmos estão implementados separadamente em arquivos `.c`, podendo ser compilados com `gcc` ou outro compilador C.

## 📘 Trabalhos de AED II: Aplicações com Tipos Abstratos de Dados (TADs)

A pasta `AED2/` contém trabalhos desenvolvidos durante a disciplina de **Algoritmos e Estruturas de Dados II**, com foco na aplicação prática dos **Tipos Abstratos de Dados (TADs)**.

Cada projeto segue uma organização modular, com os arquivos:
- `include/`: contém os arquivos `.h` com as definições de estruturas de dados e funções.
- `src/`: contém os arquivos `.c` com a implementação e os executáveis principais.

---

### 📊 Comparação de Algoritmos (`AED2/Comparação algoritmos/`)

Este diretório reúne experimentos de comparação de desempenho de algoritmos clássicos de busca e ordenação.

#### ✅ Questão 01 - Comparação entre Busca Linear e Busca Binária em Vetores
- Arquivo: `questao01.c`
- Objetivo: Comparar os tempos de execução entre busca linear e binária sobre um vetor.
- Resultados salvos para análise.

#### ✅ Questão 02 - Busca Binária: Lista Encadeada vs Vetor
- Arquivo: `questao02.c`
- Objetivo: Comparar o desempenho da busca binária quando aplicada em vetores versus listas encadeadas.
- Utiliza TADs definidos em `include/listaEncadea.h`.

#### ✅ Questão 03 - Comparação de Algoritmos de Ordenação
- Arquivo: `questao03.c`
- Algoritmos testados: Bubble Sort, Selection Sort, Insertion Sort, Quick Sort e Merge Sort.
- Objetivo: Medir e comparar os tempos de execução com diferentes entradas.

#### 📈 Questão 05 - Geração de Dados e Visualização Gráfica
- Arquivo: `questao05.c`
- Objetivo: Gerar dados a partir das ordenações para posterior análise gráfica.
- Os dados gerados são salvos em arquivos `.csv`.

#### 📊 Visualização com Python
- Script: `graficos.py`
- Bibliotecas usadas: `pandas`, `numpy`, `matplotlib`
- Função: Gerar gráficos com os dados dos arquivos CSV para facilitar a análise visual.
- Os gráficos resultantes estão disponíveis no relatório `trab01-aed2.pdf`.

#### 📄 Resultados finais com gráficos: `trab01-aed2.pdf`
---
### 🌲 Árvores Binárias e AVL (`AED2/Arvores_Avl_Binaria/`)

#### ✅ Questão 01 — Caminhamentos em Árvores Binárias  
- Arquivo: `questao01.c`
- Caminhamentos: **pré-fixado**, **pós-fixado**, **em ordem**.

#### 💬 Questão 02 — Simulação de Transmissão de Pacotes  
- Arquivo: `questao02.c`  
- Entrada: `entrada.txt`, Saída: `saida.txt`
- Mensagens transmitidas com pacotes desordenados.
- Reordenação por caminhamento em ordem em uma árvore binária.

#### ✅ Questão 03 — Busca Binária: Árvore Binária vs Vetor  
- Arquivo: `questao03.c`
- Compara tempo de execução e uso de memória.

#### ✅ Questão 04 — Árvores Binárias vs AVL  
- Arquivo: `questao04.c`
- Compara criação e tempo de busca entre **árvores binárias** e **AVL**.
- Resultados exportados para `.csv`.

#### 📄 Resultados finais: `trab02-aed2.pdf`
---

🧠 **Observação:** Todos os experimentos foram conduzidos respeitando os princípios de modularização com TADs, e o repositório segue uma separação clara entre cabeçalhos (`include/`) e código-fonte (`src/`).






