#ifndef BICOLA_H
#define BICOLA_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define TAM 100

// Estructura de la bicola lineal
typedef struct {
    int elementos[TAM];
    int head;  // Índice del primer elemento
    int tail;  // Índice del último elemento
    int len;   // Cantidad de elementos en la bicola
} Bicola;

// Declaraciones de funciones
void initialize_deque(Bicola *bicola);
bool is_empty(Bicola *bicola);
bool is_full(Bicola *bicola);
int get_size(Bicola *bicola);
bool insert_first(Bicola *bicola, int valor);
bool insert_last(Bicola *bicola, int valor);
bool remove_first(Bicola *bicola, int *valor);
bool remove_last(Bicola *bicola, int *valor);
bool peek_first(Bicola *bicola, int *valor);
bool peek_last(Bicola *bicola, int *valor);
void display_deque(Bicola *bicola);

#endif /* BICOLA_H */
