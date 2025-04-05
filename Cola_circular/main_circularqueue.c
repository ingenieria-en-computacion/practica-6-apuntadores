#include "circularqueue.h"

int main() {
    cqueue q;
    init(&q);

    printf("\nEstado inicial de la cola circular:\n");
    print(&q);

    printf("\nAgregando elementos a la cola circular...\n");
    enqueue(&q, '1');
    enqueue(&q, '2');
    enqueue(&q, '3');
    print(&q);

    printf("Primer elemento: %c\n", first(&q));
    printf("Ultimo elemento: %c\n", last(&q));

    printf("\nEliminando un elemento...\n");
    dequeue(&q);
    print(&q);

    printf("\nAgregando mas elementos...\n");
    enqueue(&q, '4');
    enqueue(&q, '5');
    print(&q);

    printf("\nVaciando la cola circular...\n");
    empty(&q);
    print(&q);

    return 0;
}
