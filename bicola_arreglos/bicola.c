#include "bicola.h"

void initialize_deque(Bicola *bicola) {
    bicola->head = 0;
    bicola->tail = -1;
    bicola->len = 0;
}

bool is_empty(Bicola *bicola) {
    return bicola->len == 0;
}

bool is_full(Bicola *bicola) {
    return bicola->len == TAM;
}

int get_size(Bicola *bicola) {
    return bicola->len;
}

bool insert_first(Bicola *bicola, int valor) {
    if (is_full(bicola)) {
        printf("Error: La bicola esta llena\n");
        return false;
    }

    if (is_empty(bicola)) {
        bicola->head = 0;
        bicola->tail = 0;
    } else {
        for (int i = bicola->tail; i >= bicola->head; i--) {
            bicola->elementos[i + 1] = bicola->elementos[i];
        }
        bicola->tail++;
    }

    bicola->elementos[bicola->head] = valor;
    bicola->len++;
    return true;
}

bool insert_last(Bicola *bicola, int valor) {
    if (is_full(bicola)) {
        printf("Error: La bicola esta llena\n");
        return false;
    }

    if (is_empty(bicola)) {
        bicola->head = 0;
        bicola->tail = 0;
    } else {
        bicola->tail++;
    }

    bicola->elementos[bicola->tail] = valor;
    bicola->len++;
    return true;
}

bool remove_first(Bicola *bicola, int *valor) {
    if (is_empty(bicola)) {
        printf("Error: La bicola esta vacia\n");
        return false;
    }

    *valor = bicola->elementos[bicola->head];

    if (bicola->head == bicola->tail) {
        bicola->head = 0;
        bicola->tail = -1;
    } else {
        bicola->head++;
    }

    bicola->len--;
    return true;
}

bool remove_last(Bicola *bicola, int *valor) {
    if (is_empty(bicola)) {
        printf("Error: La bicola esta vacia\n");
        return false;
    }

    *valor = bicola->elementos[bicola->tail];

    if (bicola->head == bicola->tail) {
        bicola->head = 0;
        bicola->tail = -1;
    } else {
        bicola->tail--;
    }

    bicola->len--;
    return true;
}

bool peek_first(Bicola *bicola, int *valor) {
    if (is_empty(bicola)) {
        printf("Error: La bicola esta vacia\n");
        return false;
    }

    *valor = bicola->elementos[bicola->head];
    return true;
}

bool peek_last(Bicola *bicola, int *valor) {
    if (is_empty(bicola)) {
        printf("Error: La bicola esta vacia\n");
        return false;
    }

    *valor = bicola->elementos[bicola->tail];
    return true;
}

void display_deque(Bicola *bicola) {
    if (is_empty(bicola)) {
        printf("La bicola esta vacia\n");
        return;
    }

    printf("Elementos de la bicola: ");
    for (int i = bicola->head; i <= bicola->tail; i++) {
        printf("%d ", bicola->elementos[i]);
    }
    printf("\n");
}
