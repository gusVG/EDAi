#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef unsigned char booleano;

int main()
{
    booleano mio = FALSE;
    printf( mio ? "si" : "no" );

    return 0;
}
