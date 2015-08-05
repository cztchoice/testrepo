#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
    string a("addfadfafdf");
    const char *c = a.c_str();
    for(int i = 0; i < strlen(c); i++){
        cout<<c[i]<<endl;
    }
    ostringstream oss;
    oss<<14<<"abdc"<<endl;
    cout<<oss.str()<<endl;
}