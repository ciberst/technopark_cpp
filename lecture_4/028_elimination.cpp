#include <iostream>

struct A {};  // sizeof(A) == 1

struct B : public A {  // sizeof(B) == 4
  int a;
};

struct C : public A {  // sizeof(C) == 8;
  A a;
  int var;
};

struct D : public A {  // sizeof(D) == ?
  B b;
  int a;
};

struct E {  // sizeof(C) == 4;
  int var;
  [[no_unique_address]] A a;  // since C++20
};

int main() {
  std::cout << sizeof(A) << std::endl;
  std::cout << sizeof(B) << std::endl;
  std::cout << sizeof(C) << std::endl;
  std::cout << sizeof(D) << std::endl;
  std::cout << sizeof(E) << std::endl;

  return 0;
}
