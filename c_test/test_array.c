#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10] = {[0 ... 5] = -1};
    int b[10];
    int c[10] = {1};
    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", a[i]);
        printf("%d\n", c[i]);
    }
    return 0;
}