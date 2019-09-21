/**
 * \mainpage Referencia Tale, una guia
 * \author Gustavo Vergara Gonzaga para EDAi - FI - UNAM
 * \date Septiembre-2019
 * Programa que muestra una manera de como podria estar *
 * funcionando la referencia TAIL de una cola circular  *
 * al realizar una insercion, si hay espacios libres    *
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 7
#define LIM 30

int main(){
    int arreglo[TAM];
    int numeroLimite = LIM, i = 1;

    for(i; i < numeroLimite; i++)
        arreglo[ (i-1) % TAM ] = i;

    printf("ESTADO FINAL DEL ARREGLO:\n\n");
    for(i = 0; i < TAM; i++)
        printf("%d\t", arreglo[ i ]);
    printf("\n");

    return 0;
}
