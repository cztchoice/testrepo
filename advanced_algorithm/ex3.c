/* 
 * Calculate 定积分 sin(x) 0~PI的定积分，正确值为2
 * PPT P-23
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

#include"uniform.h"

double calc(double a, double b, double c, double d, double n, double (*f)(double))
{
    assert(b >= a);
    assert(d >= c);
    long k = 0;
    long i = 0;
    double x = 0, y = 0;
    uniform_init();
    while(i++ < n)
    {
        x = uniform_double(a, b);
        y = uniform_double(c, d);
        if(y <= f(x))k++;
    }
    uniform_close();
    return (double)(b - a)*(d - c)*k/n;
}

double func(double x)
{
    double result = sin(x);
    return result;
}

int main(int argc, char *argv[])
{
    long n = 10000000;
    if(argc > 1)
        n = atol(argv[1]);
    double re = calc(0, 3.141592653, 0, 1, n, func);
    printf("%f\n", re);
    return 0;
}
