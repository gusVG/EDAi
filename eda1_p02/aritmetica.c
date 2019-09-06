#include <stdio.h>

void imprimeCaracteres( char *ptrLaCadena );

int main() {
    char cadena[] = "CARACTERES DE UNA CADENA";

printf( "La cadena es:\n" );
imprimeCaracteres( cadena );
	printf( "\n" );

	return 0;
}

// Recorre un arreglo hasta encontrar el caracter nulo
void imprimeCaracteres(char *ptrLaCadena ) {
	while ( *ptrLaCadena != '\0' ) {
		printf( "%c", *ptrLaCadena );
		ptrLaCadena++;
	}
}
