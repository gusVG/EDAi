#include<stdio.h>
void pasarValor( int );
void pasarReferencia( int * );

int main(){
  int numero = 55;
  int *ap;
  ap = &numero;
  
  printf("Pasar valor: %d\n", *ap);
  pasarValor(*ap);
  printf("Pasar referencia de: %d\n", *ap);
  pasarReferencia(ap);
  printf("Valor final: %d\n", *ap);
  return 0;
}
