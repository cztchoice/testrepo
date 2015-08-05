#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[]){
    map<int, int> a;
    a[1] = 3;
    a[2] += 4;
    cout<<a[3]<<endl;
    cout<<a[1]<<" "<<a[2]<<endl;
}