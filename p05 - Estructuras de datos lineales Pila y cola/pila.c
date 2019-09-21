/**
 * \mainpage Pila
 * \author Gustavo Vergara Gonzaga para EDAi - FI - UNAM
 * \date Septiembre-2019
 * Programa que muestra el funcionamiento de    *
 * una pila con su comportamiento y funciones   *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEM 4 /* Constante para numero de elementos de la pila */

/**
 * @struct nodo
 * @brief Estructura que servira como elemento para la pila
 * @param id Identificador del nodo
 * @param nombre Cadena como segundo miembro de nodo
 */
typedef struct{
    int id;
    char nombre[20];
}nodo;

/**
 * @fn push
 */
void push(nodo*, int*, int*);

/**
 * @fn pop
 */
void pop(nodo*, int*);

/**
 * @fn llena
 */
int llena(int*, int*);

/**
 * @fn vacia
 */
int vacia(int*);

/**
 * @fn imprimir
 */
void imprimir(nodo*, int*);

int main(){
    /*
    * TEXT    -   BACKGROUND
    * 0 = Black   8 = Gray
    * 1 = Blue    9 = Light Blue
    * 2 = Green   A = Light Green
    * 3 = Aqua    B = Light Aqua
    * 4 = Red     C = Light Red
    * 5 = Purple  D = Light Purple
    * 6 = Yellow  E = Light Yellow
    * 7 = White   F = Bright White
    */
    system("color F0");

    int opc, maximo, tope;
    nodo* pila;
    opc = 0;

    pila = (nodo*) calloc(NELEM, sizeof(nodo));
    tope = -1; // -1 funcionara como NULO
    maximo = NELEM - 1;

    while(1){
	system("cls");
	printf("MENU:\t\t1. PUSH\t\t2. POP\t\t3.Imprimir\t4.Salir");
	printf("\nOpcion: ");
	scanf("%d", &opc);

        switch(opc){
            case 1:
                push(pila, &tope, &maximo);
                getch();
            break;
            case 2:
                pop(pila, &tope);
                getch();
            break;
            case 3:
                printf("\nEstado actual de la pila:\n");
                imprimir(pila, &tope);
                getch();
            break;
            case 4:
                printf("\nHasta pronto, estado final de la pila:\n");
                imprimir(pila, &tope);
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

/**
 * @fn push
 * @brief Funcion que servira para realizar la funcion insertar
 * Se insertara un numero consecutivo para el id
 * Y un nombre de la lista de nombres
 * @param stack Apuntador a la estructura con los elementos
 * @param top Apuntador al valor de tope
 * @param max Apuntador al valor de la variable maximo
 */
void push(nodo *stack, int *top, int *max) {
    static int identificador = 1;
    char *ptrArrCadenas[ ] = { "\0", "Fulana", "Zutano", "Mengana", "Perengano", "Mengana", "Pepe",
        "Ana", "Paco", "Lupe", "Gabo", "Licha", "Moreno", "Mencha", "Pecas", "Mistral", "Galeano",
        "Juanita", "Hermann", "Ines", "Picasso", "Kahlo", "Stoker", "Mastreta", "Conan", "Curie"};

    printf("\nEstado actual de la pila:\n");
    imprimir(stack, top);
    printf("\nRealizando PUSH...\n");

    /* Pregunta si la estructura esta llena */
    if( llena(max, top) )
        printf("\n!!!Estructura llena!!! No se puede insertar\n");
    else{
        *top += 1;
        stack[*top].id = identificador;
        /* Utilizando funcion de la librearia string.h ( strcat(s1, s2) - strlen(s1) ) */
        strcpy(stack[*top].nombre, ptrArrCadenas[identificador%25]);
        identificador++;
    }
    imprimir(stack, top);
}

/**
 * @brief Funcion que servira para realizar la funcion eliminar
 * @param stack Apuntador a la estructura con los elementos
 * @param top Apuntador al valor de tope
 */
void pop(nodo* stack, int* top){
    printf("\nEstado actual de la pila:\n");
    /* Imprime la estructura */
    imprimir(stack, top);
    printf("\nRealizando POP...\n");

    /* Pregunta si la estructura esta vacia */
    if( vacia(top) )
        printf("\n!!!Estructura sin elementos!!! No se puede eliminar\n");
    else{
        stack[*top].id = 0;
        *top -= 1;
    }
    /* Imprime la estructura */
    imprimir(stack, top);
}

/**
 * @brief Funcion que verifica si la estructura esta llena
 * @param max Apuntador al valor de la variable maximo
 * @param top Apuntador al valor de tope
 * @return Devuelve 1 si es verdadero, 0 si es falso
 */
int llena(int *max, int *top){
    return *max == *top ? 1 : 0;
}

/**
 * @brief Funcion que verifica si la estructura esta vacia
 * @param top Apuntador al valor de tope
 * @return Devuelve 1 si es verdadero, 0 si es falso
 */
int vacia(int *top){
    /* Se recorre el arreglo de fin a inicio */
    return *top == -1 ? 1 : 0;
}

/**
 * @brief Funcion que imprime el estado actual de la estructura
 * @param stack Apuntador a la estructura con los elementos
 * @param top Apuntador al valor de tope
 */
void imprimir(nodo *stack, int *top) {
    int i;
    printf("\n\n");
    /* Se recorre el arreglo de fin a inicio */
    for(i = NELEM-1; i>=0; i--){
        /* Pregunta si el elemento en la posicion i es igual a 0(sin asignar) */
        if(stack[i].id == 0)
            printf("----\n");
        else {
            printf("%d - %s", stack[i].id, stack[i].nombre);
            printf( *top == i ? "\t<-Tope\n" : "\n" );
        }
    }
    /* Pregunta si la estructura esta vacia */
    if( vacia(top) )
        printf("Tope->nulo");
    printf("\n");
}
