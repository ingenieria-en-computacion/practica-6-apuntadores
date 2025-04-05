#define LINKED_LIST_IMPLEMENTATION
#include "../include/linked_list.h" // Incluimos las listas enlazadas
#define CIRCULAR_QUEUE_IMPLEMENTATION
#include "generic_circularqueue.h" // Incluimos la cola circular

// Funciones para mostrar diferentes tipos de datos
void print_int(int val) {
    printf("%d", val); // Imprime un entero
}

void print_char(char val) {
    printf("'%c'", val); // Imprime un carácter entre comillas simples
}

void print_float(float val) {
    printf("%.2f", val); // Imprime un número flotante con dos decimales
}

int main() {
    // Crear una cola circular para enteros con una capacidad de 5
    CircularQueue_int* queue_int = circular_queue_int_create(5);
    
    printf("\nCola Circular de Enteros\n");
    printf("Estado inicial de la cola: ");
    circular_queue_int_print(queue_int, print_int); // Imprime el estado inicial
    
    // Agregar elementos a la cola
    printf("\nAgregando elementos: 1, 2, 3...\n");
    circular_queue_int_enqueue(queue_int, 1);
    circular_queue_int_enqueue(queue_int, 2);
    circular_queue_int_enqueue(queue_int, 3);
    
    printf("Estado actual de la cola: ");
    circular_queue_int_print(queue_int, print_int); // Imprime el estado actualizado
    printf("Tamano de la cola: %zu\n", circular_queue_int_size(queue_int));
    
    // Ver el elemento frontal de la cola
    int front_value;
    if (circular_queue_int_peek(queue_int, &front_value)) {
        printf("Elemento al frente de la cola: %d\n", front_value);
    }
    
    // Eliminar un elemento de la cola
    printf("\nEliminando un elemento de la cola...\n");
    int removed_value;
    if (circular_queue_int_dequeue(queue_int, &removed_value)) {
        printf("Elemento eliminado: %d\n", removed_value);
    }
    
    printf("Estado de la cola despues de la eliminacion: ");
    circular_queue_int_print(queue_int, print_int); // Imprime el estado después de eliminar
    
    // Liberar memoria de la cola
    circular_queue_int_destroy(queue_int);
    
    // Probar con una cola circular de caracteres
    printf("\nCola Circular de Caracteres \n");
    CircularQueue_char* queue_char = circular_queue_char_create(3);
    
    printf("Agregando los caracteres: j, k, l...\n");
    circular_queue_char_enqueue(queue_char, 'j');
    circular_queue_char_enqueue(queue_char, 'k');
    circular_queue_char_enqueue(queue_char, 'l');
    
    printf("Estado de la cola de caracteres: ");
    circular_queue_char_print(queue_char, print_char); // Imprime el estado actual
    
    printf("La cola esta llena? %s\n", circular_queue_char_is_full(queue_char) ? "Si" : "No");
    
    if (!circular_queue_char_enqueue(queue_char, 'm')) {
        printf("No se pudo agregar 'm', la cola esta llena.\n\n");
    }
    
    // Liberar memoria de la cola de caracteres
    circular_queue_char_destroy(queue_char);
    
    return 0;
}
