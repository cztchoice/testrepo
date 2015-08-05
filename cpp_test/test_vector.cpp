#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

class A{
    // int a;
    //C++类中添加了虚函数之后，会多加上一个指向虚表的指针，所以类大小会增加 一个地址的大小
    // 64位系统增加 8
    virtual void b() = 0;
    virtual void c() = 0;
    virtual void d() = 0;
};
int main(int argc, char *argv[]){
    // vector<int> a;
    // // reserve 只是分配内存，如果直接像下述引用将会产生不确定的结果
    // // a.reserve(20);
    // a.resize(20);
    // a[10] = 3;
    // cout<<a[10]<<endl;

    cout<<sizeof(A)<<endl;
}