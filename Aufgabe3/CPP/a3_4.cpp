#include <iostream>
#include <string>

int main() {
  int j = 10;
  {
    int j = 20;
  }
  std::cout << j << std::endl;
  return 0;
}
