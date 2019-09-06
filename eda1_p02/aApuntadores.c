#include <stdio.h>
 
int main () {

   int  anio;
   int  *ptrAnio;
   int  **pPtrAnio;

   anio= 2018;
   ptrAnio= &anio;
   pPtrAnio = &ptrAnio;
   printf( "Valor de anio = %d\n", anio ); //2018
   printf( "Valor disponible en *ptrAnio = %d\n", *ptrAnio );
   printf( "Valor disponible en **pPtrAnio = %d\n", **pPtrAnio);

   return 0;
}
