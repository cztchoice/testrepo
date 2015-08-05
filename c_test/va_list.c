#include <stdarg.h>
#include <stdio.h>

void test_va_list(char * fmt, ...){
    char a[1000];
    va_list ap;
    //This is a fixed usage, 
    //the code between va_start and va_end decides how to deal with the args
    va_start(ap, fmt);
    vsnprintf(a, 1000, fmt, ap);
    va_end(ap);

    printf("%s\n", a);
}

int test_va_int(int n, ...){
    va_list ap;
    int sum = 0;
    //This is a fixed usage, 
    //the code between va_start and va_end decides how to deal with the args
    va_start(ap, n);
    for(int i = 0; i < n; i++){
        int temp = va_arg(ap, int);
        sum += temp;
    }
    va_end(ap);

    return sum;
}

int main(int argc, char const *argv[])
{
    test_va_list("%s %d", "abc", 4);
    printf("%d\n", test_va_int(4, 1, 2, 4, 7));
    return 0;
}