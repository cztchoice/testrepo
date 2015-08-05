#include <stdio.h>

main()
{
    int i=0, j=0;
    i=i++;

    i=i+1;
    i++;
    ++i;

    j=i+1;
    j=i++;
    j=++i;

    printf("i=%d", i);

}
