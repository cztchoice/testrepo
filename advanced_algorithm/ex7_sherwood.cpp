/*
 * Execise 6:搜索有序表
 * Name: 陈志韬
 * StuID: SA12011089
 */
#include<iostream>
#include<cassert>
#include<cmath>
#include<cstdio>
using namespace std;
extern "C"{
#include"uniform.h"
}
typedef int calcType;
const int ARRAY_LENGTH = 10;

/*
 * 有序表的样式如下：
 * 设两个数组val[1..n]和ptr[1..n]及head构成一个有序的静态链表：
 * val[head] <= val[ptr[head]] <= val[ptr[ptr[head]]] <= ... <=
 * val[ptr(n-1)[head]]
 * 即：
 * ptr[i] {  给出下一个关键字的下标  if val[i]非最大关键字
 *        {  -1                      if val[i]是最大关键字
 */

//全局存储的val ptr表，方便其他函数使用
static calcType *val, *ptr;

void swap(int & a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void printVal(int n)
{
    cout<<"i: \t";
    for(int i = 0; i < n; i++)
        cout<<i<<"\t";
    cout<<endl;
    cout<<"val: \t";
    for(int i = 0; i < n; i++)
        cout<<val[i]<<"\t";
    cout<<endl;
    cout<<"ptr: \t";
    for(int i = 0; i < n; i++)
        cout<<ptr[i]<<"\t";
    cout<<endl;
}
//return the head num
int init(int n)
{
    int head = 0;
    val = new calcType[n + 1];
    ptr = new calcType[n + 1];

    int i = 0;
    for (i = 0; i < n; i++) {
        val[i] = i;
        ptr[i] = i + 1;
    }
    ptr[n-1] = -1;
    printVal(n);

    int k, l;
    for (i = 0; i < n/2; i++) {
        k = uniform_long(0, n - 1);
        l = uniform_long(0, n - 1);

        cout<<k<<"\t"<<l<<endl;
        if(k == l || ptr[k] == -1 || ptr[l] == -1) continue;
        swap(val[ptr[k]], val[ptr[l]]);

        swap(ptr[ptr[k]], ptr[ptr[l]]);
        swap(ptr[k], ptr[l]);
    }
    return head;
}
bool checkVal(int head, int n)
{
    int i = head;
    int count = 0;
    while(i != n)
    {
        if(val[i] != count) 
        {
            cout<<i<<"\tcount "<<count<<"!= val[i] "<<val[i]<<endl;
            return false;
        }
        i = ptr[i];
        count++;
    }
    if(count < n) return false;
    return true;

}

void destory_data()
{
    delete []val;
    delete []ptr;
}
//返回-1时代表没有找到，以下函数相同
int search(calcType x, int head)
{
    int i = head;
    while(i != -1 && x > val[i] )
    {
        //cout<<i<<" "<<ptr[i]<<endl;
        i = ptr[i];
    }
    return i;
}

int A(calcType x, int head)
{
    return search(x, head);
}

int B(calcType x, int head, int n)
{
    int i = head;
    int j;
    int max = val[i];
    calcType y;
    for(j = 0; j < (int)sqrt(n); j++)
    {
        y = val[j]; 
        if(y > max && y <= x)
        {
            i = j;
            max = y;
        }
    }
    return search(x, i);
}
int C(calcType x, int head, int n)
{
    int i = head;
    int j;
    int max = val[i];
    calcType y;
    int k;
    for(k = 0; k < (int)sqrt(n); k++)
    {
        j = uniform_long(0, n - 1);
        y = val[j]; 
        if(y > max && y <= x)
        {
            i = j;
            max = y;
        }
    }
    return search(x, i);
    return 0;
}
int D(calcType x, int head, int n)
{
    long i = uniform_long(head, n - 1);
    calcType y = val[i];
    if(x < y)
        return search(x, head);
    else if(x > y)
        return search(x, ptr[i]);
    else
        return i;
}
void printResult(int result, int n)
{
    if(result == -1)
        cout<<"Not found"<<endl;
    else
    {
        cout<<result<<"\t"<<val[result]<<endl;
    }
}
int main(int argc, char const* argv[])
{
    int x = 5;
    int n = ARRAY_LENGTH;
    if(argc > 1)
        x = atoi(argv[1]);
    if(argc > 2)
        n = atoi(argv[2]);
    int result = -1;
    uniform_init();
    
    int head = init(n);
    cout<<head<<endl;

    printVal(n);
    if(!checkVal(head, n))
    {
        cout<<"Value generate error!!"<<endl;
        return 1;
    }
    cout<<"readyA"<<endl;
    result = -1;
    result = A(x,head);
    printResult(result, n);

    cout<<"readyB"<<endl;
    result = -1;
    result = B(x,head, n);
    printResult(result, n);

    cout<<"readyC"<<endl;
    result = -1;
    result = C(x,head, n);
    printResult(result, n);

    cout<<"readyD"<<endl;
    result = -1;
    result = D(x,head, n);
    printResult(result, n);
    uniform_close();
    destory_data();
    return 0;
}
