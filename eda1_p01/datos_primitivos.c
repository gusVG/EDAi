#include <stdio.h>
#include <stdlib.h>
 
int main() { 
    char cadena1[] = "cadena";
    char cadena2[] = { 'c', 'a', 'd', 'e', 'n', 'a' };
    printf("Char = %d\n", sizeof( char ) );
    printf("Int = %d\n", sizeof( int ) );
    printf("Float = %d\n", sizeof( float ) );
    printf("Double = %d\n", sizeof( double ) );
    
    printf("cadena1 = %d\n", sizeof( cadena1 ) );
    printf("cadena2 = %d", sizeof( cadena2) );
    return 0; 
}