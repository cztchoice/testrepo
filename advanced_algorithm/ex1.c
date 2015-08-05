/* 
 * Calculate 2*sqrt(2), 精准值: 2.828427125
 * PPT P-20
 */
#include<stdio.h>

#include"uniform.h"

double darts(long n)
{
    long k = 0;
    int i = 0;
    double x = 0, y = 0;
    uniform_init();
    for(i = 0;i < n;i++)
    {
        x = uniform_double(0, 1);
        /*y = uniform_double(0, 1);*/
        y = x;
        /*printf("%f %f\n", x, y);*/
        if(x*x + y*y <= 1)
            k++;
    }
    uniform_close();
    /*printf("%ld\n", k);*/
    return 4.0*k/n;
}
int main(int argc, char *argv[])
{
    long n = 10000000;
    if(argc > 1)
        n = atol(argv[1]);
    printf("%f\n", darts(n));
    return 0;
}
