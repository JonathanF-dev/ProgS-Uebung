#include <functional>
#include <iostream>

template <typename T>
std::function<T (T)> makeConverter(T factor, T offset) {
  return [=] (T input) -> T { return (offset + input) * factor; };
}

int main() {

  auto milesToKm = makeConverter(1.60936, 0.0);
  auto poundsToKg = makeConverter(0.45460, 0.0);
  auto fahrenheitToCelsius = makeConverter(0.5556, -32.0);

  // -> (1)
  std::cerr << milesToKm(10) << std::endl;
  std::cerr << poundsToKg(2.5) << std::endl;
  std::cerr << fahrenheitToCelsius(98) << std::endl;

  return 0;
}
