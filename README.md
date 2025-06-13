# Relatório Técnico: Implementação de Stack com Lista Ligada

**Disciplina:** Programação em Sistemas Computacionais  
**Ano Letivo:** 2024/2025  
**Docente:** Paulo Silva 
**Aluno:** Éder Évora
**Data de Entrega:** 13 de Junho de 2025

---

## Introdução

As estruturas de dados são fundamentais para o desenvolvimento eficiente de algoritmos e programas de computador. Entre elas, a **Stack** (ou pilha) destaca-se como uma estrutura linear que segue a política LIFO (Last-In, First-Out), ou seja, o último elemento inserido é o primeiro a ser removido. Neste trabalho prático, foi proposto desenvolver uma Stack utilizando **lista ligada**, como forma de reforçar os conceitos de alocação dinâmica e manipulação de ponteiros em linguagem C. A stack implementada armazena processos simulados, cada um identificado por um PID e um comando.

---

## Objetivo

Desenvolver uma estrutura de dados do tipo **Stack** utilizando **listas ligadas** para simular o armazenamento de processos. A implementação deverá contemplar as operações básicas `push`, `pop`, `empty`, `free` e outras, de acordo com os requisitos do enunciado fornecido.

---

## Estrutura de Dados

- **`valueT`**: representa um processo com `pid` (identificador) e `comando` (nome do programa).
- **`nodeT`**: nó da lista ligada contendo um valor do tipo `valueT` e um ponteiro para o próximo nó.
- **`stackT`**: representa a pilha com um ponteiro para o primeiro elemento da lista (`head`).

---

## Funções Implementadas

### `NewNode()`
Aloca memória dinamicamente para um novo nó da pilha. Retorna o ponteiro para o novo nó ou `NULL` em caso de falha.

### `NewStack()`
Cria uma nova estrutura do tipo `stackT` com o ponteiro `head` inicializado como `NULL`. Retorna `NULL` se não for possível alocar memória.

### `Push(stack, processo)`
Insere um novo processo no topo da stack. O novo nó aponta para o nó atual no topo, e o ponteiro `head` da stack passa a apontar para o novo nó.

### `Pop(stack)`
Remove e retorna o processo que se encontra no topo da stack. Caso a stack esteja vazia, imprime mensagem de erro e retorna um valor nulo (pid = 0).

### `EmptyStack(stack)`
Remove todos os nós da stack, libertando a memória alocada para cada um, e define `head = NULL`.

### `FreeStack(stack)`
Liberta a memória alocada para a estrutura da stack apenas se esta estiver vazia. Caso contrário, imprime uma mensagem de erro.

### `isEmpty(stack)`
Retorna 1 se a stack estiver vazia (`head == NULL`), ou 0 caso contrário.

---

## Teste no `main()`

Foi criado um bloco de teste no `main()` que simula o uso da stack:

1. Criação da stack.
2. Inserção de três processos com comandos distintos: `gedit`, `firefox` e `terminal`.
3. Utilização do `Pop()` para remover e exibir os processos inseridos, respeitando a ordem LIFO.
4. Liberação da estrutura da stack após esvaziá-la.

Este teste permite verificar se as funções estão operando corretamente e se a memória é devidamente gerida.

---

## Conclusão

A implementação da stack com lista ligada foi concluída com sucesso, respeitando todos os requisitos definidos no enunciado. A estrutura permite o armazenamento dinâmico de processos, com manipulação segura da memória. A abordagem em linguagem C fortalece o domínio de conceitos como alocação dinâmica, uso de `structs`, ponteiros e listas ligadas, proporcionando uma base sólida para aplicações mais complexas em sistemas computacionais. O código foi devidamente testado e validado.

---
