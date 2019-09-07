#include <stdio.h>

int suma (int a, int b) {
  return a+b;
}

int resta (int a, int b) {
  return a-b;
}
void main() {
	// puntero a función con dos parámetros enteros
	// que devuelve un entero
int (*funcion) (int,int);
	int x = 0;
	
funcion = suma; // ‘funcion’ apunta a ‘suma’
	x = funcion( 4, 3 ); // x = suma( 4, 3 )
	printf( "%d\n", x ); // imprime 7
	
funcion = resta; // ‘funcion’ apunta a ‘resta’
	x = funcion( 4, 3 ); // x = resta( 4, 3 ) 
	printf( "%d", x ); // imprime 1
}
