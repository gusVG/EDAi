#include <stdio.h>

typedef struct{
  char *cara;
  char *palo;
} Carta;

int main()
{
  Carta unaCarta;
  Carta *ptrCarta;
  unaCarta.cara = "As";
  unaCarta.palo = "Copas";
  ptrCarta = &unaCarta;

  printf("%s de %s\n", unaCarta.cara, unaCarta.palo);
  printf("%s de %s\n", ptrCarta->cara, ptrCarta->palo);
  printf("%s de %s\n", ( *ptrCarta ).cara, (*ptrCarta ).palo);

  return 0;
}
