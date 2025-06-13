#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD 100

typedef struct {
    int pid;
    char comando[MAX_CMD];
} valueT;

typedef struct _nodeT {
    valueT value;
    struct _nodeT *next;
} nodeT;

typedef struct {
    nodeT *head;
} stackT;

nodeT *NewNode(void) {
    nodeT *node = (nodeT *)malloc(sizeof(nodeT));
    if (node == NULL) {
        printf("Erro: N\xC3\xA3o foi poss\xC3\xADvel alocar mem\xC3\xB3ria para novo n\xC3\xB3.\n");
        return NULL;
    }
    return node;
}

stackT *NewStack(void) {
    stackT *stack = (stackT *)malloc(sizeof(stackT));
    if (stack == NULL) {
        printf("Erro: N\xC3\xA3o foi poss\xC3\xADvel criar nova Stack.\n");
        return NULL;
    }
    stack->head = NULL;
    return stack;
}

void Push(stackT *stack, valueT processo) {
    nodeT *novo = NewNode();
    if (novo == NULL) return;

    novo->value = processo;
    novo->next = stack->head;
    stack->head = novo;
}

valueT Pop(stackT *stack) {
    valueT vazio = {0, ""};
    if (stack->head == NULL) {
        printf("Erro: Stack vazia.\n");
        return vazio;
    }

    nodeT *temp = stack->head;
    valueT valor = temp->value;
    stack->head = temp->next;
    free(temp);

    return valor;
}

void EmptyStack(stackT *stack) {
    nodeT *atual = stack->head;
    while (atual != NULL) {
        nodeT *prox = atual->next;
        free(atual);
        atual = prox;
    }
    stack->head = NULL;
}

void FreeStack(stackT *stack) {
    if (stack->head != NULL) {
        printf("Erro: Stack ainda cont\xC3\xA9m elementos.\n");
        return;
    }
    free(stack);
}

int isEmpty(stackT *stack) {
    return stack->head == NULL;
}

// Fun\xC3\xA7\xC3\xA3o de exemplo para teste
int main() {
    stackT *stack = NewStack();
    if (!stack) return 1;

    valueT p1 = {1, "gedit"};
    valueT p2 = {2, "firefox"};
    valueT p3 = {3, "terminal"};

    Push(stack, p1);
    Push(stack, p2);
    Push(stack, p3);

    while (!isEmpty(stack)) {
        valueT p = Pop(stack);
        printf("Processo removido: PID=%d, Comando=%s\n", p.pid, p.comando);
    }

    FreeStack(stack);
    return 0;
}
