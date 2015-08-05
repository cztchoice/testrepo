#include<iostream>
#include<vector>

std::vector<int> b;
//This does not name a type
//b.push_back(1);

int c[10];
//This does not name a type too
//c[0] = 1;

int main()
{
    std::vector<int> a;
    a.push_back(1);

    //Here is ok
    b.push_back(1);

    //Here is ok, too
    c[0] = 1;
    int d[10];
    d[0] = 1;
    return 0;
}
