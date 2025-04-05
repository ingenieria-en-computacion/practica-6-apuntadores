#include "circularqueue.h"

void init(cqueue *q) {
    q->head = q->tail = -1;
    q->len = 0;
}

bool is_empty(cqueue *q) {
    return (q->len == 0);
}

bool is_full(cqueue *q) {
    return (q->len == TAM);
}

void enqueue(cqueue *q, char d) {
    if (is_full(q)) {
        printf("Error: la cola esta llena\n");
        return;
    }

    if (is_empty(q)) {
        q->head = q->tail = 0;
    } else {
        q->tail = (q->tail + 1) % TAM;
    }

    q->data[q->tail] = d;
    q->len++;
}

void dequeue(cqueue *q) {
    if (is_empty(q)) {
        printf("Error: la cola esta vacia\n");
        return;
    }

    if (q->head == q->tail) {
        q->head = q->tail = -1;
    } else {
        q->head = (q->head + 1) % TAM;
    }

    q->len--;
}

char first(cqueue *q) {
    if (is_empty(q)) {
        printf("Error: la cola esta vacia\n");
        return '\0';
    }

    return q->data[q->head];
}

char last(cqueue *q) {
    if (is_empty(q)) {
        printf("Error: la cola esta vacia\n");
        return '\0';
    }

    return q->data[q->tail];
}

void empty(cqueue *q) {
    q->head = -1;
    q->tail = -1;
    q->len = 0;
}

void print(cqueue *q) {
    if (is_empty(q)) {
        printf("La cola esta vacia\n");
        return;
    }

    printf("Elementos de la cola: ");
    int i = q->head;
    int count = 0;

    while (count < q->len) {
        printf("%c ", q->data[i]);
        i = (i + 1) % TAM;
        count++;
    }

    printf("\n");
}
