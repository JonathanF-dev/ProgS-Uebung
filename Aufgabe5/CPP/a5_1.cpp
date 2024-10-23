
#include <iostream>

class Integer {
public:
  Integer(int i) {
    i_ = new int(i);
  }
  ~Integer() {
    delete i_;
  }

  int get_integer() const { return *i_; }

private:
  int *i_;
};

auto getAdder(int x) {
  Integer i(x);
  return [i] (int y) { return i.get_integer() + y; };
}

int main() {

  auto x = 2;
  auto f = getAdder(2);

  std::cout << f(x) << std::endl;

  return 0;
}
