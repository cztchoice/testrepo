#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    //第一个参数传入以KB为单位的内存大小
    //第二个参数传入每次跨越的长度stride
    int size = 1024; //KB
    int stride = 32;
    int temp = 0;
    int i = 0;
    if(argc >= 2)
        size = atoi(argv[1]);
    if(argc >= 3)
        stride = atoi(argv[2]);
    printf("%d %d\n", size, stride);
    int byte_size = size * 1024;//From KB to Byte
    int array_size = (size * 1024) / sizeof(int);
    int *mem = (int*)malloc(byte_size);
    memset(mem, 0, byte_size);
    for(i = 0; i < array_size; i += stride)
        temp = mem[i];
    return 0;
}
