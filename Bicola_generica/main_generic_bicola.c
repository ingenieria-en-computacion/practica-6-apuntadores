#define LINKED_LIST_IMPLEMENTATION
#include "../include/linked_list.h"

#define GENERIC_BICOLA_IMPLEMENTATION
#include "generic_bicola.h"

// Función para imprimir enteros
void print_int(int value) {
    printf("%d ", value);
}

// Función para imprimir caracteres
void print_char(char value) {
    printf("%c ", value);
}

int main() {
    // Ejemplo con bicola de enteros
    printf("\nBicola (int): operaciones basicas \n");
    Bicola_int* bicola_int = bicola_int_create();

    // Insertar elementos al final y al frente
    bicola_int_push_back(bicola_int, 1);     // [1]
    bicola_int_push_back(bicola_int, 2);     // [1, 2]
    bicola_int_push_front(bicola_int, 8);     // [8, 1, 2]
    bicola_int_push_front(bicola_int, 9);     // [9, 5, 1, 2]

    // Mostrar contenido actual
    printf("Contenido actual: ");
    bicola_int_display(bicola_int, print_int);
    printf("\n");

    // Mostrar tamaño actual
    printf("Cantidad de elementos: %zu\n", bicola_int_size(bicola_int));

    // Ver valores en los extremos
    int front_value, back_value;
    if (bicola_int_peek_front(bicola_int, &front_value)) {
        printf("Frente de la bicola: %d\n", front_value);
    }

    if (bicola_int_peek_back(bicola_int, &back_value)) {
        printf("Final de la bicola: %d\n", back_value);
    }

    // Eliminar elementos de ambos extremos
    if (bicola_int_pop_front(bicola_int, &front_value)) {
        printf("Se elimino del frente: %d\n", front_value);
    }

    if (bicola_int_pop_back(bicola_int, &back_value)) {
        printf("Se elimino del final: %d\n", back_value);
    }

    // Mostrar después de eliminar
    printf("Bicola actualizada: ");
    bicola_int_display(bicola_int, print_int);
    printf("\n");

    // Ejemplo con bicola de caracteres
    printf("\nBicola (char): ejemplo con letras\n");
    Bicola_char* bicola_char = bicola_char_create();

    bicola_char_push_back(bicola_char, 'b');
    bicola_char_push_back(bicola_char, 'i');
    bicola_char_push_back(bicola_char, 'c');
    bicola_char_push_back(bicola_char, 'o');
    bicola_char_push_back(bicola_char, 'l');
    bicola_char_push_back(bicola_char, 'a');

    printf("Contenido de la bicola de caracteres: ");
    bicola_char_display(bicola_char, print_char);
    printf("\n");

    // Liberar memoria de ambas bicolas
    bicola_int_destroy(bicola_int);
    bicola_char_destroy(bicola_char);

    return 0;
}
