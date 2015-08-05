#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLEN 1024

#define char_u unsigned char
typedef struct png_header {
  unsigned char header[8];
}png_header;

int main(int argc, char *argv[]){
  if (argc != 2) {
    fprintf(stderr, "usage: %s %s\n", argv[0], "infile");
    exit(1);
  }
  FILE *infile, *outfile;
  infile = fopen(argv[1], "rb");
  int rc;
  png_header *buf = (png_header*)malloc(sizeof(png_header));
  rc = fread(buf, sizeof(png_header), 1, infile);
  printf("%d\n", rc);
  if (rc != 1){
    fprintf(stderr, "This is not a file!!\n");
  }
  else if(buf->header[0] != 0x89 || buf->header[1] != 0x50 || buf->header[2] != 0x4E || buf->header[3] != 0x47 || buf->header[4] != 0x0D || buf->header[5] != 0x0A || buf->header[6] != 0x1A || buf->header[7] != 0x0A) {
    fprintf(stderr, "This is not png file!!\n");
  }
  else {
    fprintf(stdout, "This is a png file!\n");
  }

  fclose(infile);
  fclose(outfile);
  
  return 0;
}
