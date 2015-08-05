#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*typedef struct t{*/
  /*int a;*/
/*}t;*/
int main(int argc, char *argv[]){

  int i = 4;
  /*printf("hello world");*/
  /*printf("%2zu\n", sizeof(t));*/
  /*printf("%2d\n", i);*/

  /*unsigned long a = strlen(NULL);*/
  unsigned long a = strlen("\0");
  printf("%lU\n", a);
  printf("%s\n", NULL);

  return 0;
}
