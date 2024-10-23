#include <iostream>

const int j = 10;

void f() {
  int x = j;
  int j = 20;

  std::cout << x << std::endl;
  std::cout << j << std::endl;
}

int main() {
  f();
  return 0;
}
