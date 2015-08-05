#include <iostream>
 
class C {
    public:
  C() {}
  C(const C&) { std::cout << "A copy was made.\n"; }
};
 
C f() {
  return C();
}
 
int main() {
  std::cout << "Hello World!\n";
  C obj = f();
}
