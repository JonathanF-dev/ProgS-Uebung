
#include <iostream>
#include <cmath>

double sqrt_newton(double x) {
  const double       EPSILON  = 0.000001;
  const unsigned int MAX_ITER = 10000;

  unsigned int iter     = 0;
  double       estimate = 1.0;

  while (::fabs(estimate*estimate - x) > EPSILON && iter < MAX_ITER) {
    estimate = 0.5*(estimate + x/estimate);
    ++iter;
  }

  return estimate;
}

int main() {
  double x = 0.0;
  std::cout << "Bitte geben Sie eine Zahl ein: ";
  std::cin >> x;
 
  std::cout << "Die Wurzel aus " << x << " ist " << sqrt_newton(x) << std::endl;
 
  return 0;
}