#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

int main(int argc, char *argv[]){
  printf("0x%08"PRIx32"\n", 11);
  printf("%*llx\n", 34444);
  return 0;
}
