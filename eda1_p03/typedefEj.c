#include <stdio.h>

struct estudiante {
   char *nombre;
   char *apPaterno;
   char *apMaterno;
};
//El nuevo tipo de dato definido se
//llama: struct estudiante

typedef struct estudiante elestudiante;

int main( ) {
    elestudiante alumno2;

    alumno2.nombre = "Mengano";
    alumno2.apPaterno = "DePadre";
    alumno2.apMaterno = "YDeMadre";

    printf("Todo: %s %s %s",
		alumno2.nombre,
		alumno2.apPaterno,
		alumno2.apMaterno);

   return 0;
}
