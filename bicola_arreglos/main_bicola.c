#include "bicola.h"

int main() {
    Bicola mi_bicola;
    int valor;

    initialize_deque(&mi_bicola);

    printf("\nInsercion de elementos atras y al frente \n");
    insert_last(&mi_bicola, 2);
    display_deque(&mi_bicola);

    insert_first(&mi_bicola, 1);
    display_deque(&mi_bicola);

    insert_last(&mi_bicola, 3);
    display_deque(&mi_bicola);

    insert_first(&mi_bicola, 0);
    display_deque(&mi_bicola);

    printf("Tamano actual: %d\n", get_size(&mi_bicola));

    printf("\nConsulta de elementos \n");
    if (peek_first(&mi_bicola, &valor)) {
        printf("Elemento del frente: %d\n", valor);
    }

    if (peek_last(&mi_bicola, &valor)) {
        printf("Elemento del final: %d\n", valor);
    }

    printf("\nEliminar elementos\n");
    if (remove_first(&mi_bicola, &valor)) {
        printf("Elemento eliminado del frente: %d\n", valor);
        display_deque(&mi_bicola);
    }

    if (remove_last(&mi_bicola, &valor)) {
        printf("Elemento eliminado del final: %d\n", valor);
        display_deque(&mi_bicola);
    }

    printf("Tamano actual: %d\n", get_size(&mi_bicola));

    printf("Eliminando todos los elementos...\n");
    while (!is_empty(&mi_bicola)) {
        remove_first(&mi_bicola, &valor);
        printf("Eliminado: %d\n", valor);
    }

    printf("Bicola despues de eliminar todos los elementos:\n");
    display_deque(&mi_bicola);

    if (!remove_first(&mi_bicola, &valor)) {
        printf("No se puede eliminar una bicola vacia.\n");
    }

    return 0;
}
