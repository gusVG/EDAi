#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef struct pub {
    int key;
    char contenido[20];
    char fecha[20];
    struct pub *next;
}publicacion;

void insertar(publicacion **);
publicacion * buscar(publicacion **, int);
int borrar(publicacion **, int);
int estavacia(publicacion *);
void imprimir(publicacion **);
void obtenerfecha(char *);

int main() {
    // system("color F0");
    publicacion *head = NULL;
    publicacion *aux = 0; // variable que almacena lo devuelto por la funcion buscar
    // "codigo" va a servir para retornar una especificacion de la operacion borrar, ver en funcion
    int keyabuscar = 0, codigo;
    int opc = 0;

    while(1){
        system("clear"); // system("cls"); // para Windows
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
                    printf("\nLlave encontrada con valores: %d, %s, %s", aux->key, aux->contenido, aux->fecha);
                    if (aux->next != NULL) // Si "next" del nodo encontrado no es el ultimo
                        printf("\nY su siguiente es: %d, %s, %s", aux->next->key, aux->next->contenido, aux->next->fecha);
                    else
                        printf("\nYa es fin de lista, no hay siguiente");
                }

                getchar(); getchar();
            break;
            case 3:
                printf("\nLlave a eliminar: ");
                scanf("%d", &keyabuscar);

                codigo = borrar(&head, keyabuscar);

                if(codigo == 0)
                    printf("\nLlave %d no encontrada, no se ha borrado nada\n", keyabuscar);
                else if(codigo == 1)
                    printf("\nLlave %d encontrada, se ha borrado el elemento\n", keyabuscar);
                else if(codigo == 2)
                    printf("\nNo hay que borrar\n");

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

void insertar(publicacion **apuhead) {
    char *ptrArrCadenas[ ] = { "\0", "#Love", "#Instagood", "#Photooftheday", "#Beautiful", "#Happy", "#Art",
        "#Picoftheday", "#Fashion", "#tbt", "#cute", "#Like4like", "#me", "#Instalike", "#Smile", "#Photography", "#instagram",
        "#beauty", "#girl", "#fun", "#photo", "#amazing", "#likeforlike", "#instalike", "#Selfie", "#smile", "#me",
        "#lifestyle", "#model", "#follow4follow", "#music", "#friends", "#motivation", "#like", "#food", "#inspiration", "#Repost",
        "#followme", "#style", "#follow", "#instadaily", "#travel", "#life", "#cute", "#fitness", "#nature"};
    static int llave = 1;

    publicacion *anterior = NULL;
    anterior = *apuhead; // anterior apunta al mismo lugar que head
    *apuhead = (publicacion*)calloc(1, sizeof(publicacion)); // head apunta al nuevo elemento

    (*apuhead) -> key = llave;
    strcpy((*apuhead) -> contenido, ptrArrCadenas[llave % 45]); // uso de funcion de la libreria string
    obtenerfecha( (*apuhead) -> fecha );

    (*apuhead) -> next = anterior; // el nuevo elemento apunta a anterior
    llave++;
}

publicacion * buscar(publicacion ** apuhead, int keyabuscar) {
    publicacion *mueve = NULL;
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

int borrar(publicacion **apuhead, int elemento_a_borrar) {
    publicacion *actual = NULL;
    publicacion *previo = NULL;
    actual = *apuhead;

    if(estavacia(*apuhead))
        return 2; // Devolvera 2 si la lista esta vacia

    // Buscando la llave hasta el ultimo elemento
    while(actual->key != elemento_a_borrar) {
        if(actual->next == NULL) {
            return 0; // Devolvera 0 si no se encontro el elemento
        } else {
            //Se guarda la posicion de partida y la siguiente con previo y actual
            previo = actual;
            actual = actual->next;
        }
    }

    if(actual == *apuhead) {
        *apuhead = (*apuhead)->next;
    } else {
        previo->next = actual->next;
    }

    free(actual); // Libera el espacio que se reservo para el nodo que ya no esta ligado.
    return 1; // Devolvera 1 si se pudo borrar (encontrado el elemento)
}

// Devuelve 1 si la lista esta vacia y 0 si no
int estavacia(publicacion *head) {
    return head == NULL ? 1 : 0;
}

void imprimir(publicacion ** apuhead) {
    if(estavacia(*apuhead)) {
        printf("\nLa estructura esta vacia\n\n");
    } else {
        publicacion *mueve = NULL;
        mueve = *apuhead; // variable para moverse a traves de los nodos

        printf("\n");
        while(mueve != NULL) {
            printf("%d: %s\n%s ->\n\n", mueve->key, mueve->contenido, mueve->fecha);
            mueve = mueve->next;
        }
    }

    getchar(); getchar();
}

// Se copia la fecha actual al miembro "fecha" del nodo creado
void obtenerfecha( char * buffer ) {
    time_t timer;
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 20, "%d-%m-%Y %H:%M:%S", tm_info);
}
