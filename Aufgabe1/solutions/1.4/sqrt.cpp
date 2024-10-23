#include <iostream>

#include "sqrt_lib.h"

int main() {
  double x = 0.0;
  std::cout << "Bitte geben Sie eine Zahl ein: ";
  std::cin >> x;
 
  std::cout << "Die Wurzel aus " << x << " ist " << sqrt_newton(x) << std::endl;
 
  return 0;
}