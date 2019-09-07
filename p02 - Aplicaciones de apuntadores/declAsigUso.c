#include <stdio.h>

int main() {
    int anio = 2019;
    int *ptrAnio = NULL;
    ptrAnio = &anio;

    printf( "Valor de anio es %d", anio );
    printf( "\nDirección de anio es %x", &anio );
    printf( "\nValor de ptrAnio es %p", ptrAnio );
    printf( "\nValor al que apunta ptrAnio es %d", *ptrAnio );

    return 0;
}
