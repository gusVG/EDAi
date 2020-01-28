#include <stdio.h>
#include <stdlib.h>
 
int main() { 
    char cadena1[] = "cadena";
    char cadena2[] = { 'c', 'a', 'd', 'e', 'n', 'a' };
    printf("Char = %ld\n", sizeof( char ) );
    printf("Int = %ld\n", sizeof( int ) );
    printf("Float = %ld\n", sizeof( float ) );
    printf("Double = %ld\n", sizeof( double ) );
    
    printf("cadena1 = %ld\n", sizeof( cadena1 ) );
    printf("cadena2 = %ld", sizeof( cadena2) );
    return 0; 
}