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








