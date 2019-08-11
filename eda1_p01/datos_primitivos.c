#include <stdio.h>
#include <stdlib.h>
 
int main() { 
    char cadena1[] = "cadena";
    char cadena2[] = { 'c', 'a', 'd', 'e', 'n', 'a' };
    printf("%d\n", sizeof( char ) );
    printf("%d\n", sizeof( int ) );
    printf("%d\n", sizeof( float ) );
    printf("%d\n", sizeof( double ) );
    
    printf("%d\n", sizeof( cadena1 ) );
    printf("%d", sizeof( cadena2) );
    return 0; 
}
