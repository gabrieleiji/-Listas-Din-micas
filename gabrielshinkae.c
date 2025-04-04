# Listas Dinâmicas em C

## 1️⃣ Introdução às Listas Dinâmicas

As **listas dinâmicas** são estruturas de dados que permitem a alocação dinâmica de memória, possibilitando um tamanho variável durante a execução do programa. Diferente dos **arrays (listas estáticas)**, que possuem um tamanho fixo determinado em tempo de compilação, as listas dinâmicas podem crescer ou diminuir conforme necessário.

### Comparação entre listas estáticas e dinâmicas
| Característica        | Listas Estáticas (Arrays) | Listas Dinâmicas |
|----------------------|------------------------|-----------------|
| Tamanho fixo        | Sim                     | Não             |
| Uso de memória      | Pré-alocada             | Alocação dinâmica |
| Acesso a elementos  | Direto (índices)        | Sequencial       |
| Inserção/Remoção    | Ineficiente (realocação necessária) | Eficiente |

### Vantagens e desvantagens
**Vantagens das listas dinâmicas:**
- Uso eficiente de memória.
- Facilidade para inserir e remover elementos.
- Flexibilidade no gerenciamento de dados.

**Desvantagens das listas dinâmicas:**
- Acesso mais lento aos elementos.
- Uso de ponteiros pode gerar erros como vazamento de memória.

## 2️⃣ Estrutura de uma Lista Dinâmica

Uma lista dinâmica é geralmente implementada usando **estruturas encadeadas**, onde cada nó contém:
- **Dado:** A informação armazenada.
- **Ponteiro:** Referência para o próximo nó na lista.

```c
typedef struct No {
    int dado;
    struct No *prox;
} No;
```

## 3️⃣ Operações Básicas

### Criação e Inicialização

```c
No* criarLista() {
    return NULL; // Lista vazia
}
```

### Inserção de um Elemento

```c
No* inserirInicio(No *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return lista;
    novo->dado = valor;
    novo->prox = lista;
    return novo;
}
```

### Remoção de um Elemento

```c
No* removerElemento(No *lista, int valor) {
    No *atual = lista, *anterior = NULL;
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return lista; // Elemento não encontrado
    if (anterior == NULL) lista = atual->prox; // Remoção do primeiro nó
    else anterior->prox = atual->prox;
    free(atual);
    return lista;
}
```

## 4️⃣ Implementação em C

```c
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura
typedef struct No {
    int dado;
    struct No *prox;
} No;

// Funções de manipulação
No* criarLista() { return NULL; }

No* inserirInicio(No *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return lista;
    novo->dado = valor;
    novo->prox = lista;
    return novo;
}

void imprimirLista(No *lista) {
    No *atual = lista;
    while (atual) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lista = criarLista();
    lista = inserirInicio(lista, 10);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 30);
    imprimirLista(lista);
    return 0;
}
```

## 5️⃣ Referências
- DAMAS, Luís. **Linguagem C**. Lisboa: FCA, 2009.
- TANENBAUM, Andrew S. **Estruturas de Dados em C**. Pearson, 2015.
- NUMERO DO LIVRO :70889