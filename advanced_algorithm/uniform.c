/* 
 * 生成随机数
 */
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>

#include"uniform.h"

//本来是打算尝试用Linux系统带的random设备的，但是发现每次读一次设备实在是太耗时间了。。
#define USE_SYSTEM 0
#if USE_SYSTEM
#define RAND() random_device()
#else
#define RAND() rand()
#endif

int random_device()
{
    /*printf("used!!\n");*/
    int randomData = open("/dev/random", O_RDONLY);
    int myRandomInteger;
    read(randomData, &myRandomInteger, sizeof myRandomInteger);
    // you now have a random integer!
    /*close(randomData);*/
    return myRandomInteger;
}

void uniform_init()
{
    srand(time(0));
}

//can not reach j
long uniform_long(long i, long j)
{
    assert(i <= j);
    long result = RAND()%(j - i) + i;
    /*srand(result*time(0) + result);*/
    return result;
}

double uniform_double(double i, double j)
{
    assert(i <= j);
    double random_double = (j - i)*((double)RAND()/RAND_MAX) + i;
    /*srand((unsigned int)(random_double*time(0) + random_double));*/
    return random_double;
}

void uniform_close()
{
    //You can add something after all random generation is done.
}
