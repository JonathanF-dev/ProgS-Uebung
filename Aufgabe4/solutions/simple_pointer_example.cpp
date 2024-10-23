
#include <iostream>

union Number {
  int i;
  float f;
};

int main() {
  /*
  int a = 2;
  int b = 4;

  int *pa = &a;
  int *pb = &b;

  std::cout << &a << std::endl;
  std::cout << &b << std::endl;
  std::cout << std::hex << (pb-pa)*sizeof(int) << std::endl;
  */
  Number n;
  n.i = 10;
  std::cout << n.f << std::endl;

  int x = 10;
  float y = x;

  std::cout << y << std::endl;

  return 0;
}
