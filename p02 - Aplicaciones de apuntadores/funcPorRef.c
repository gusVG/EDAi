#include<stdio.h>
void pasarValor( int );
void pasarReferencia( int * );

int main(){
  int numero = 55;
  int *ap;
  ap = &numero;

  printf("Pasar referencia de: %d\n", numero);
  pasarReferencia(ap);
  printf("Pasar valor: %d\n", numero);
  pasarValor(*ap);

  printf("Valor final: %d\n", *ap);
  return 0;
}

void pasarValor( int equis ){
  printf("%d\n", equis);
  equis = 128;
  printf("%d\n", equis);
}

void pasarReferencia( int *equis ){
  printf("%d\n", *equis);
  *equis = 128;
  printf("%d\n", *equis);
}
