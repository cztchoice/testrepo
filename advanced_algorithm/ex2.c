/* 
 * Calculate PI, 精准值：3.14159265357
 * PPT P-23
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"uniform.h"

double hitorMiss(double (*f)(double), long n)
{
    long k = 0;
    long i = 0;
    double x = 0, y = 0;
    uniform_init();
    while(i++ < n)
    {
        x = uniform_double(0, 1);
        y = uniform_double(0, 1);
        if(y <= f(x))k++;
    }
    uniform_close();
    return (double)4*k/n;
}

double func(double x)
{
    double temp = 1 - x*x;
    return sqrt(temp);
}

int main(int argc, char *argv[])
{
    long n = 10000000;
    if(argc > 1)
        n = atol(argv[1]);
    double re = hitorMiss(func, n);
    printf("%f\n", re);
    return 0;
}
