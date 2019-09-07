#include <stdio.h>

struct estudiante {
   int nCuenta;
   char sexo;
   float promedio;
   int cal[3];
};

int main( ) {
    struct estudiante alumno2 = { 981, 'F', 9.6, { 8, 10, 9 } };
    struct estudiante alumno1;

    alumno1.nCuenta = 123;
    alumno1.sexo = 'M';
    alumno1.promedio = 8.5;
    alumno1.cal[0] = 8;
    alumno1.cal[1] = 9;
    alumno1.cal[2] = 10;

    printf("Su promedio: %.2f", alumno1.promedio);
    printf("\nSu promedio: %.2f", alumno2.promedio);

    return 0;
}
