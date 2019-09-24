#include <stdio.h>
#include <stdlib.h>

typedef struct juego{
    int llave; // consecutivo
    char *ref;
    struct juego *siguiente;
} Viborita;

int main () {
    Viborita *head = NULL;
    Viborita *mueve;
    // Se crea un nodo. Al crearlo head apuntará a él
    head = (Viborita *) calloc(1, sizeof(Viborita));
    head->llave = 1;
    head->ref = "Empieza";

    // Se crea un nodo. Al crearlo head-siguiente apuntará a él
    head->siguiente = (Viborita *) calloc(1, sizeof(Viborita));
    head->siguiente->llave = 2;
    head->siguiente->ref = "LeSigue";

    head->siguiente->siguiente = (Viborita *) calloc(1, sizeof(Viborita));
    head->siguiente->siguiente->llave = 3;
    head->siguiente->siguiente->ref = "LeSigueOtro";

    mueve = head;

    // Se recorre la referencia hasta que el elemento ‘siguiente’ es nulo
    while(mueve != NULL){
        printf("%d\t", mueve->llave);
        printf("%s\n", mueve->ref);
        mueve = mueve->siguiente;
    }

    free(mueve);
    free(head);

    return 0;
}