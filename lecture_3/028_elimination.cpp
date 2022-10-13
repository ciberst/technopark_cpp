#include <iostream>

struct Alpha {};

struct Beta : public Alpha {
  int n;
};

struct Gamma : public Alpha {
  Alpha a;  // атрибут размера 1
  int n;
};

struct Delta : public Alpha {
  Beta b;  // атрибут размера sizeof(int)
  int n;
};

struct A {
  Alpha b;
  int n;
};

struct B {
  [[no_unique_address]] Alpha b;
  int n;
};

#define PRINT_SIZE(X) std::cout << "sizeof(" #X ") = " << sizeof(X) << std::endl

int main() {
  PRINT_SIZE(Alpha);
  PRINT_SIZE(Beta);
  PRINT_SIZE(Gamma);
  PRINT_SIZE(Delta);
  PRINT_SIZE(A);
  PRINT_SIZE(B);
}