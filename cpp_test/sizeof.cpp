#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

class A{
     virtual void f();
    char a;
    int b[3];
    // char c[13];
};

int main(int argc, char *argv[]){
    cout<<sizeof(A)<<endl;
    
}