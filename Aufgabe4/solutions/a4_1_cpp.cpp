
#include <iostream> 
#include <functional>
#include <algorithm>
#include <array>

int main() {

  std::array<std::function<void ()>, 10> fa;

  for (int i = 0; i < 10; ++i) {
    int j  = 0;
    fa[i] = [j] () mutable { j++; std::cout << j << std::endl; };
  }

  std::for_each(fa.begin(), fa.end(), 
    [] (std::function<void ()> f) { f(); });

  return 0;
}