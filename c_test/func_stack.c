#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void func(size_t a, ...) {
  size_t *p = &a;
  for (size_t i = 1; i <= a; ++i) {
    printf("%p\t", (p-i));
  }
  printf("\n");
  for (size_t i = 1; i <= a; ++i) {
    printf("%zu\t", *(size_t*)((char*)(p-i)));
  }
  printf("\n");
}

void func_va(int a, ...) {
  va_list aq;
  va_start(aq, a);
  for(int i = 0; i < a; i++){
    int temp = va_arg(aq, int);
    printf("%d\n", temp);
  }
  va_end(aq);
}

void func_addr(int a, int b, int c) {
  int *p = &a;
  for(int i = 1; i <= a; i++){

    printf("%d\t", *(p -i));
  }
  printf("\n");
  printf("%p\t%p\t%p\n", &a, &b, &c);
  printf("%p\t%p\t%p\n", p, p - 1, p - 2);
  printf("%d\t%d\t%d\n", a, b, c);
  printf("%d\t%d\t%d\n", *p, *(p - 1), *(p - 2));
}

int main(int argc, char *argv[]){
  size_t a = 3, b = 7, c = 8, d = 9;
  func(a, b, c, d);
  /*func(1, b);*/
  /*func_addr(a, b, c);*/
  /*func_va(a, b, c, d);*/
  return 0;
}
