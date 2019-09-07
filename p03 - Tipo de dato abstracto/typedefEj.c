#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    char* identificador;
} Punto;

typedef struct {
    Punto puntos[4];
    int perimetro;
    int area;
} Rectangulo;

int calculaArea(int, int);
int calculaPerimetro(int, int);

// esta funcion me devuelve los puntos a calcular
Punto calculaPuntoSupDer(Punto, Punto);
Punto calculaPuntoInfIzq(Punto, Punto);

int main(){
    Rectangulo miRectangulo;
    Rectangulo* apuRect;
    int i, base, altura;

    apuRect = &miRectangulo;

    printf("Dame X1: ");
    scanf("%d", &miRectangulo.puntos[0].x);
    printf("\nDame Y1: ");
    scanf("%d", &miRectangulo.puntos[0].y);
    printf("\nDame X2: ");
    scanf("%d", &miRectangulo.puntos[2].x);
    printf("\nDame Y2: ");
    scanf("%d", &miRectangulo.puntos[2].y);

    miRectangulo.puntos[1] = calculaPuntoSupDer(miRectangulo.puntos[0], miRectangulo.puntos[2]);
    miRectangulo.puntos[3] = calculaPuntoInfIzq(miRectangulo.puntos[0], miRectangulo.puntos[2]);

    base = miRectangulo.puntos[2].x - miRectangulo.puntos[0].x;
    altura = miRectangulo.puntos[2].y - miRectangulo.puntos[0].y;

    miRectangulo.area = base * altura;
    miRectangulo.perimetro = 2 * base + 2 * altura;

    system("cls");
    for(i=0; i<4; i++) {
      printf("Punto %d: (%d, %d)\n", i+1, apuRect->puntos[i].x, apuRect->puntos[i].y);
    }

    printf("\nArea = %d: ", apuRect->area);
    printf("\nPerimetro = %d: ", apuRect->perimetro);

    return 0;
}


Punto calculaPuntoSupDer(Punto pun1, Punto pun2){
    Punto resultante;
    resultante.x = pun2.x;
    resultante.y = pun1.y;

    return resultante;
}

Punto calculaPuntoInfIzq(Punto pun1, Punto pun2){
    Punto resultante;
    resultante.x = pun1.x;
    resultante.y = pun2.y;

    return resultante;
}
