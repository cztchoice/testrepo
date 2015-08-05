#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    FILE *fp;
    int c;

    fpos_t first;
    fpos_t end;
    fp = fopen( "file", "r+" );
    if( fp != NULL ) {
      fgetpos(fp, &first);
      c = fgetc(fp);
      fsetpos(fp, &first);
      fputc('d', fp);
      /*fflush(fp);*/
    }
      fclose( fp );
    
    return EXIT_FAILURE;
}

