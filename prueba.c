#include "todo.h"

int main( int argc, char *argv[] )  {

   if( argc == 2 ) {
      printf("el argumento es: %s\n", argv[1]);

      FILE *fp = fopen(argv[1], "r+");

      fprintf(fp, "%s\n", "holis xDxd");
   }
   else if( argc > 2 ) {
      printf("Demasiados argumentos.\n");
   }
   else {
      printf("Se espera al menos un argumento.\n");
   }

   return 0;
}