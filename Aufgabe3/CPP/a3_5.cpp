namespace A {
  struct X {};
  struct Y {};
  void f(int i) {};
  void g(X x) {};
}

namespace B {
  void f(int i) {
    f(i);         // -> Welches f() wird aufgerufen?
  }

  void g(A::X x) {
    g(x);        // -> Welches g() wird aufgerufen?
  }

  void h(A::Y y) {
    h(y);        // -> Welches h() wird aufgerufen?
  }
}

int main() {
  // Hier könnte Ihr Code stehen...
  return 0;
}
