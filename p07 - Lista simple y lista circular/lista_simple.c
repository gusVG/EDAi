#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct juegoviborita {
    int key;
    char nombre[20];
    struct juegoviborita *next;
}cubito;

int main() {
    system("color F0");
    cubito *head = NULL;
    cubito *anterior = NULL; // variable para intercambiar referencias
    cubito *mueve = 0; // variable para moverse a través de los nodos

    if(head == NULL)
        printf("HEAD apunta a: %p\n", head);

    printf("\n---------INSERT---------");
    anterior = head; // anterior apunta al mismo lugar que head
    head = (cubito*)calloc(1, sizeof(cubito)); // head apunta al nuevo elemento
    head -> key = 1;
    strcpy(head -> nombre, "PRIMERO"); // uso de funcion de la libreria string
    head -> next = anterior; // el nuevo elemento apunta a anterior
    printf("\nHEAD apunta a: %p \ncon valores: key=%d, nombre=%s, next=%p\n", head, head->key, head->nombre, head->next);

    printf("\n---------INSERT---------");
    anterior = head;
    head = (cubito*)calloc(1, sizeof(cubito));
    head -> key = 2;
    strcpy(head -> nombre, "SEGUNDO");
    head -> next = anterior;
    printf("\nHEAD apunta a: %p \ncon valores: key=%d, nombre=%s, next=%p\n", head, head->key, head->nombre, head->next);
    printf("%s apunta a: %p \ncon valores: key=%d, nombre=%s, next=%p\n", head->nombre, head->next, head->next->key, head->next->nombre, head->next->next);

    printf("\n---------INSERT---------");
    anterior = head;
    head = (cubito*)calloc(1, sizeof(cubito));
    head -> key = 3;
    strcpy(head -> nombre, "TERCERO");
    head -> next = anterior;
    printf("\nHEAD apunta a: %p \ncon valores: key=%d, nombre=%s, next=%p\n", head, head->key, head->nombre, head->next);
    printf("%s apunta a: %p \ncon valores: key=%d, nombre=%s, next=%p\n", head->nombre, head->next, head->next->key, head->next->nombre, head->next->next);
    printf("%s apunta a: %p \ncon valores: key=%d, nombre=%s, next=%p\n", head->next->nombre, head->next->next, head->next->next->key, head->next->next->nombre, head->next->next->next);

    mueve = head;
    printf("\n---------PRINT, a partir de HEAD---------\n");
    while(mueve != NULL) {
        printf("%d,%s -> ", mueve->key, mueve->nombre);
        mueve = mueve->next;
    }
    printf("\n");

    return 0;
}
