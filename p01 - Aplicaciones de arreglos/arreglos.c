#include <stdio.h>

void imprimirArreglo( int [ ] );

int main () {
    int a[ 6 ] = { 2, 3, 5, 7, 11, 13 };    
    imprimirArreglo( a );

    return 0;
}

void imprimirArreglo( int arreglo[ ] ) {
    int i = 0;
    for ( i; i < 9; i++ )
        printf( "a[%d] = %d\n", i, arreglo[ i ] );
}