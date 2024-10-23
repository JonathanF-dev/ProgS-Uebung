#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

class Transformer {
public:
  Transformer(int& i) : i_(i) {}

  double operator()(double e) {
    return 1.0 / static_cast<double>(i_++);
  }
private:
  int& i_;
};

class Accumulator {
public:
  Accumulator() {}

  double operator()(double e1, double e2) {
    return e1 + e2;
  }
};

int main() {
  const int N = 2;

  std::vector<double> v(N);
  int i = 1;

  std::transform(v.begin(), v.end(), v.begin(), Transformer(i));

  double s = std::accumulate(v.begin(), v.end(), 0.0, Accumulator());

  std::cout <<  s  <<  std::endl;

  return 0;
}
