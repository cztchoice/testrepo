#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const* argv[])
{
    int *a = (int *)malloc(10 * sizeof(int));
    printf("%d\n", a[5]);
    return 0;
}
