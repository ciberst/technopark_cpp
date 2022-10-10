#include <iostream>

namespace {
class A {
 public:
  A() { std::cout << "ctor A()" << std::endl; }
  explicit A(int a) : a_(a) { std::cout << "ctor A() from int" << std::endl; }
  ~A() { std::cout << "dtor ~A() : a_ == " << a_ << std::endl; }
  virtual void foo() { std::cout << std::endl << std::endl; }
  int a_{0};
};

class B : public A {
 public:
  B() : a(5) { std::cout << "ctor B()" << std::endl; }
  ~B() { std::cout << "dtor ~B()" << std::endl; }
  A a;
};

class Alpha {
 public:
  Alpha() { std::cout << "ctor Alpha()" << std::endl; }
  ~Alpha() { std::cout << "dtor ~Alpha()" << std::endl; }
};

class C :  public Alpha, public B {
 public:
  C() { std::cout << "ctor C()" << std::endl; }
  ~C() { std::cout << "dtor ~C()" << std::endl; }
};

class D {
 public:
  D() { std::cout << "ctor D()" << std::endl; }
  ~D() { std::cout << "dtor ~D()" << std::endl; }
  C c;
};
} // namespace 


int main() {
  D d; 

  return 0;
}
