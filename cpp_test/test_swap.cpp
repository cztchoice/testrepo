#include<iostream>


void swap(int &a, int &b)
{
    a ^= b;
    b = a^b;
    a = a^b;
}

int main()
{
    int a = 10, b = 20;
    int array[2] = {10, 20};
    std::cout<<a<<" "<<b<<std::endl;
    std::cout<<array[0]<<" "<<array[1]<<std::endl;
    swap(a, b);
    swap(array[0], array[1]);
    std::cout<<array[0]<<" "<<array[1]<<std::endl;
    std::cout<<a<<" "<<b<<std::endl;
    return 0;
}
