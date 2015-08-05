#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_LEN 1024

typedef struct reg_size {
    char fb;    //first byte
    char sb;    //second byte
}reg_size;

int main(int argc, char const* argv[])
{
    FILE *infile, *outfile;
    
    infile = fopen("in", "rb");
    outfile = fopen("out", "wb");

    assert(infile != NULL);
    assert(outfile != NULL);

    int rc;
    reg_size buf;

    while (rc = fread(&buf, sizeof(reg_size), 1, infile)) {
        printf("%x %x\n", buf.fb, buf.sb);
        fwrite(&buf, sizeof(reg_size), rc, outfile);
    }
    
    fclose(infile);
    fclose(outfile);

    return 0;
}
