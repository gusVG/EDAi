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
    // system("color F0");
    correo *head = NULL;
    correo *aux = 0; // variable que almacena lo devuelto por la funcion buscar
    int keyabuscar = 0;
    int opc = 0;

    while(1){
        system("clear"); // system("cls"); // en Windows
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
                
                // "buscar" devuelve NULL si no es encontrada o la direccion del nodo si se encontro
                aux = buscar(&head, keyabuscar);

                if(aux == NULL)
                    printf("\nLlave %d no encontrada", keyabuscar);
                else {
                    printf("\n--------EL BUSCADO--------\n");
                    printf("%d. De: %s, Para: Mi\nMsj: %s\nRecibido el %s\n", aux->key, aux->remitente, aux->contenido, aux->fecha);
                    
                    printf("\n------(prev)------\n");
                    if(aux->prev != NULL) {
                        printf("%d. Remitente: %s\nContenido: %s\nCon fecha del %s\n",
                            aux->prev->key, aux->prev->remitente, aux->prev->contenido, aux->prev->fecha);
                    }
                    else // Si "prev" del nodo encontrado es el primero
                        printf("Es inicio de lista, no hay previo\n");
                    
                    printf("\n------(next)------\n");
                    if(aux->next != NULL) {
                        printf("%d. Remitente: %s\nContenido: %s\nCon fecha del %s\n",
                            aux->next->key, aux->next->remitente, aux->next->contenido, aux->next->fecha);
                    }
                    else // Si "next" del nodo encontrado es el ultimo
                        printf("Es fin de lista, no hay siguiente\n");
                }

                getchar(); getchar();
            break;
            case 3:
                printf("\nLlave a eliminar: ");
                scanf("%d", &keyabuscar);
                
                // "buscar" devuelve NULL si no es encontrada o la direccion del nodo si se encontro
                aux = buscar(&head, keyabuscar);

                if(aux == NULL)
                    printf("\nLlave %d no encontrada, no se ha borrado nada\n", keyabuscar);
                else {
                    // se envia head y la direccion del nodo encontrado
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
                getchar(); getchar();
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
        
    // head debe apuntar al nuevo nodo
    (*apuhead) = nuevo;

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
    /* Si el elemento a borrar es el mismo que el que apunta head
    entonces, al borrar head debe apuntar al next del elemento a borrar.*/
    if(aborrar == *apuhead) {
        *apuhead = aborrar->next;
    /* De lo contrario, si el elemento a borrar no es el mismo que el que apunta head,
    el previo del elemento a borrar en su miembro next apuntara a lo que apunta el next del elemento a borrar */
    } else {
        (aborrar->prev)->next = aborrar->next;
    }
    
    /* Si el siguiente del elemento a borrar no es nulo, entonces,
    este mismo nodo en su miembro previo apuntara al previo del elemento a borrar */
    if(aborrar->next != NULL) {
        (aborrar->next)->prev = aborrar->prev;
    }

    free(aborrar); // Libera el espacio que se reservo para el nodo que ya no esta ligado.
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

    getchar(); getchar();
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
