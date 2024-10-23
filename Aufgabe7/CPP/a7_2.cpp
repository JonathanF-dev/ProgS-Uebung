#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

int main() {
  const int N = 2;

  std::vector<double> v(N);
  int i = 1;

  std::transform(v.begin(), v.end(), v.begin(),
    [&i](double e) {
      return 1.0 / i++;
    }
  );

  double s = std::accumulate(v.begin(), v.end(), 0.0,
    [] (double e1 , double e2) {
      return e1  +  e2 ;
    }
  );

  std::cout <<  s  <<  std::endl;

  return 0;
}
