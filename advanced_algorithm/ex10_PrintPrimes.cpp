/*
 * FileName: ex10_PrintPrimes.cpp
 * 打印1万以内的素数，与确定性算法相比较，并给出100~10000以内的错误比例
 */
#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;

extern "C"{
#include"uniform.h"
}

bool Btest(long long a, long long n)
{
    long long s = 0;
    long long t = n - 1;
    assert(t%2 == 0);
    do {
        s++;
        t /= 2;
    } while (t%2 == 0);

    long long x = 1;
    //防止损坏t
    long long k = t;
    long long i;
    a = a%n;
    while(k--) {
        x = (x*a) % n;
    }
    if (x == 1 || x == n - 1) {
        return true;
    }
    //必须要以0开始，然后运算这么多次，
    for (i = 0; i < s - 1 ; i++) {
        x = x % n;
        x = (x * x) % n;
        if(x == n-1)
            return true;
    }
    return false;
}
bool millRob(long long n)
{
    //这儿生成的是从2开始的
    long long a = uniform_long(2, n - 2);
    return Btest(a, n);
}
bool repeatMillRob(long long n, long long k)
{
    for(long long i = 0; i < k; i++)
    {
        if(false == millRob(n))
            return false;
    }
    return true;
}
bool testPrimes(long long n)
{
    long long i;
    for (i = 2; i <= (long)sqrt(n) + 1; i++) {
        if(n%i == 0)
            return false;
    }
    return true;
}
void printPrimes(const long long begin, const  long long n)
{
    long long i = begin;
    long long count_judge_primes = 0;
    long long fault = 0;
    if (i % 2 == 0) {
        i++;
    }
    //只取偶数进行比较
    for(;i < n; i += 2)
    {
        assert(i%2 != 0);
        bool result_rob = repeatMillRob(i, (long)log2(i));
        bool result_test = testPrimes(i);
        if(result_rob)
        {
            count_judge_primes++;
            cout<<i<<" ";
        }
        if(result_test != result_rob)
        {
            fault++;
            cout<<"Wrong Primes Num: "<<i<<endl;
        }
    }
    long long count_primes = 0;
    for(i = begin; i < n; i++)
        if(testPrimes(i))
            count_primes++;
    cout<<endl;
    cout<<"The number of choosing Primes: "<<count_judge_primes<<endl<<"Faults in them: "<<fault<<endl;
    cout<<"The number of Primes calculate by exhastion: "<<count_primes<<endl;
}


int main(int argc, char const* argv[])
{
    long long n = 10000;
    if (argc > 1) {
        n = atol(argv[1]);
        n = (n > 100) ? n : 10000;
    }
    uniform_init();
    //cout<<n<<endl;
    printPrimes(100, n);
    uniform_close();
    return 0;
}
