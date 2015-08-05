#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[30] = "abc def  gggg   ";
    char * tok = NULL;
    tok = strtok(str, " ");
    while (tok) {
        printf("Token %lu: %s\n", strlen(tok), tok);
        tok = strtok(NULL, " ");
    }
    return 0;
}