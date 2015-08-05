#include<iostream>
#include<string>

int main(int argc, char const* argv[])
{
    std::string a = "saa";
    std::string::iterator it = a.end();

    std::cout<<*it<<std::endl;
    return 0;
}
