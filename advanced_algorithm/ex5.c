/* 
 * 计算集合的势，精准值即输入的n值，默认为1,000,000,000
 * PPT P-36
 * 通过多次尝试（5次）取平均数的方式得到的结果还是挺靠谱的
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<unistd.h>

#include"uniform.h"

#define PI 3.14159265357
#define BOOL int
#define FALSE 0
#define TRUE 1
#define HASH_SIZE 100000
#define CALC_TIMES 5

double calc(long i, long j)
{
    assert(i <= j);
    long k = 0;
    long sorted_s[HASH_SIZE][10];
    long sorted_count[HASH_SIZE] = {0};
    uniform_init();
    long a = uniform_long(i, j);
    BOOL in_s = FALSE;
    long temp;
    while(!in_s)
    {
        k++;
        temp = a%HASH_SIZE;
        sorted_s[temp][sorted_count[temp]] = a;
        sorted_count[temp]++;
        a = uniform_long(i, j);
        temp = a%HASH_SIZE;
        int i = 0;
        for(i = 0;i < sorted_count[temp];i++)
        {
            if(sorted_s[temp][i] == a)
            {
                in_s = TRUE;
                break;
            }
        }

    }
    uniform_close();
    return (double)2*k*k/PI;
}

double func(double x)
{
    double result = sin(x);
    return result;
}

int main(int argc, char *argv[])
{
    long n = 1000000000;
    if(argc > 1)
        n = atol(argv[1]);
    int i = 0;
    double average = 0;
    double re;
    for(i = 0;i < CALC_TIMES;i++)
    {
        re = calc(1, n);
        average += re;
        printf("%f\n", re);
        sleep(1);
    }
    printf("Average: %f\n", average/CALC_TIMES);

    return 0;
}
