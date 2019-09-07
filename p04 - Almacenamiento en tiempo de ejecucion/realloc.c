#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arreglo, *arreglo2, num, cont;
  printf("¿Cuántos elementos tiene el
conjunto?\n");
  scanf("%d", &num);
  arreglo = (int*)malloc (num*sizeof(int));
  if(arreglo != NULL) {
    for(cont=0 ; cont < num ; cont++){
      printf("Inserte el elemento %d del
conjunto.\n",cont+1);
      scanf("%d",(arreglo+cont));
    }
    printf("Vector insertado:\n\t[");
    for (cont=0 ; cont < num ; cont++){
      printf("\t%d",*(arreglo+cont)); }
    printf("\t]\n");
    printf("Aumentando al doble.\n");
    num *= 2;
    arreglo2 = (int *)realloc(arreglo,num*sizeof(int));
    if (arreglo2 != NULL) {
      for (; cont < num ; cont++){
        printf("Inserte el elemento %d:\n", cont + 1);
        scanf("%d",(arreglo2+cont)); }
      printf("Vector insertado:\n\t[");
      for (cont=0 ; cont < num ; cont++){
        printf("\t%d",*(arreglo2+cont)); }
      printf("\t]\n");
    }
    free (arreglo);
  }
  return 0;
}
