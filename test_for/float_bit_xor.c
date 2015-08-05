#include<stdio.h>

int main(int argc, char const* argv[])
{
    float a = 2.3;
    float b = 3.2;
    float *c = &a;
    float *d = &b;
    
    int *e = (int*)c;
    int *f = (int*)d;

    *e ^= *f;
    *f ^= *e;
    *e ^= *f;

    c = (float*)e;
    d = (float*)f;
    printf("%f\n%f", a, b);
    return 0;
}
