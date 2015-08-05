#include<iostream>
//#include<memory>
#include<string>

using namespace std;

int flag = 0;
//typedef unsigned int size_t;

void operator delete(void* p, int i)
{
    flag = 1;
}

void* operator new(size_t s, int i)
{
    return new char[s];
}

class A{
    public:
        A(){
            //throw -37;
        }
        ~A(){
            //throw -20;
        }
};

class B{
    public:
        B(){
            //throw -37;
        }
        ~B(){
            throw -20;
        }
};
int main()
{
    char *buf = new char[sizeof(string)];
    string *p = new (buf) string("hi");
    string *q = new string("Hi");

    cout<<sizeof(string)<<endl;
    cout<<reinterpret_cast<void*>(buf)<<endl;
    cout<<p<<endl;
    cout<<q<<endl;

    try {
        A* p = new(1234) A;
        //delete p;
        p->~A();
    }
    catch (Exception e){
        cout<<i<<endl;
    }
    if(flag == 1)
    {
        cout<<"1"<<endl;
        return 1;
    }
    else
    {
        cout<<"0"<<endl;
        return 0;
    }
    delete q;
    delete []buf;
    return 0;
}
