#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef struct manejadorDeCorreoElectronico {
    int key;
    char remitente[30];
    char contenido[30];
    char fecha[20];
    struct manejadorDeCorreoElectronico *next;
    struct manejadorDeCorreoElectronico *prev;
}correo;

void insertar(correo **);
correo * buscar(correo **, int);
void borrar(correo **, correo *);
int estavacia(correo *);
void imprimir(correo **);
void obtenerfecha(char *);
int aleatorio (int);

int main() {
    system("color F0");
    correo *head = NULL;
    correo *aux = 0; // variable para moverse a través de los nodos
    int keyabuscar = 5, codigo;
    int encontro = 0, opc;

    while(1){
        system("cls");
        printf("MENU:\t\t1. INSERTAR\t\t2. BUSCAR\t\t3.BORRAR\t\t4.Imprimir\t5.Salir");
        printf("\nOpcion: ");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                insertar(&head);
                imprimir(&head);
            break;
            case 2:
                printf("\nLlave a buscar: ");
                scanf("%d", &keyabuscar);

                aux = buscar(&head, keyabuscar);

                if(aux == NULL)
                    printf("\nLlave %d no encontrada", keyabuscar);
                else {
                    printf("\n--------EL BUSCADO--------\n");
                    printf("%d. De: %s, Para: Mi\nMsj: %s\nRecibido el %s\n", aux->key, aux->remitente, aux->contenido, aux->fecha);
                    if(aux->prev != NULL) {
                        printf("\n------(prev)------\n");
                        printf("%d. Remitente: %s\nContenido: %s\nCon fecha del %s\n",
                            aux->prev->key, aux->prev->remitente, aux->prev->contenido, aux->prev->fecha);
                    }
                    if(aux->next != NULL) {
                        printf("\n------(next)------\n");
                        printf("%d. Remitente: %s\nContenido: %s\nCon fecha del %s\n",
                            aux->next->key, aux->next->remitente, aux->next->contenido, aux->next->fecha);
                    }
                }

                getch();
            break;
            case 3:
                printf("\nLlave a eliminar: ");
                scanf("%d", &keyabuscar);
                aux = buscar(&head, keyabuscar);

                if(aux == NULL)
                    printf("\nLlave %d no encontrada, no se ha borrado nada\n", keyabuscar);
                else {
                    borrar(&head, aux);
                    printf("\nLlave %d encontrada, se ha borrado el elemento\n", keyabuscar);
                }
                imprimir(&head);
            break;
            case 4:
                imprimir(&head);
            break;
            case 5:
                return 0;
            break;
            default:
                printf("\nOpcion invalida");
                getch();
            break;
        }
    }

    return 0;
}

void insertar(correo **apuhead) {
    char *mensaje[ ] = { "Pagame", "Saludos", "Besos", "Abrazos", "Cocolazos", "Fiesta en casa",
        "Cheves", "Ultima advertencia", "Ven en Navidad", "La ultima y nos vamos", "Te deposito", "Promociones",
        "Fiesta!", "Ya casate", "Con intereses", "Disfrazate", "Tiende la cama", "Haz de comer", "Paga las deudas"};//19
    char *quienenvia[ ] = { "Mama", "Papa", "Abuelito", "Abuelita", "Amazon", "Oxxo",
        "La/el de las Tortillas", "Hermana", "Hermano", "El banco", "Amiga", "Amigo", "Google", "Mercado libre"};//14
    static int llave = 1;
    correo *nuevo = NULL;
    nuevo = (correo*)calloc(1, sizeof(correo)); // "nuevo" apunta al espacio para nuevo nodo

    nuevo -> key = llave; // Se asigna la key al nuevo nodo
    strcpy(nuevo -> contenido, mensaje[aleatorio(19)]); // uso de funcion de la libreria string
    strcpy(nuevo -> remitente, quienenvia[aleatorio(14)]); // uso de funcion aleatorio
    obtenerfecha( nuevo -> fecha );
    nuevo -> prev = NULL; // La referencia "prev" del nodo creado apunta a NULL
    nuevo -> next = *apuhead; // La referencia "next" del nodo creado apunta a lo que está apuntando head

    // Si no esta vacia la referencia "prev" de lo que está apuntando head apuntara al nodo creado
    if(!estavacia(*apuhead))
        (*apuhead) -> prev = nuevo;

    (*apuhead) = nuevo; // Head apunta el nuevo nodo

    llave++;
}

correo * buscar(correo ** apuhead, int keyabuscar) {
    correo *mueve = NULL;
    mueve = *apuhead;

    if(estavacia(*apuhead))
        return NULL;

    while(mueve != NULL) {
        if( keyabuscar == mueve->key )
            return mueve;

        mueve = mueve->next;
    }
    return NULL;
}

void borrar(correo ** apuhead, correo *aborrar) {
    if(aborrar == *apuhead) {
        *apuhead = aborrar->next;
    } else {
        (aborrar->prev)->next = aborrar->next;
    }

    if(aborrar->next != NULL) {
        (aborrar->next)->prev = aborrar->prev;
    }

    free(aborrar);
}

int estavacia(correo *head) {
    return head == NULL ? 1 : 0;
}

void imprimir(correo ** apuhead) {
    if(estavacia(*apuhead)) {
        printf("\nLa estructura esta vacia\n\n");
    } else {
        correo *mueve = NULL;
        mueve = *apuhead;

        printf("\n");
        while(mueve != NULL) {
            printf("%d. De: %s, Msj: %s\nRecibido el %s ->\n\n", mueve->key, mueve->remitente, mueve->contenido, mueve->fecha);
            mueve = mueve->next;
        }
    }

    getch();
}

void obtenerfecha( char * buffer ) {
    time_t timer;
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 20, "%d-%m-%Y %H:%M:%S", tm_info);
}

// Generar numero aleatorio dependiendo limite
int aleatorio(int limite){
    time_t t;
    srand((unsigned) time(&t));

    return rand() % limite;
}