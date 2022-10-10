#include <iostream>

class A {
 public:
  A() { std::cout << "A()" << std::endl; }
  A(const A& a) { std::cout << "A(const &a)" << std::endl; }
  A& operator=(A& a) {
    std::cout << "A &operator=(A &a)" << std::endl;
    return a;
  }
  ~A() { std::cout << "~A()" << std::endl; }
};

class B {
 public:
  B() { std::cout << "B()" << std::endl; }
  B(const B& b) { std::cout << "B(const &b)" << std::endl; }
  B& operator=(B& b) {
    std::cout << "B &operator=(B &b)" << std::endl;
    return b;
  }
  ~B() { std::cout << "~B()" << std::endl; }
};

class C {
 private:
  A a;
  B b;

 public:
  C(A& a, B& b) : a(a), b(b) { std::cout << "C()" << std::endl; }
  ~C() { std::cout << "~C()" << std::endl; }
};

// Вспомогательный класс
class Object {
 public:
  Object(int n) : n(n) { std::cout << "Object::ctor() #" << n << std::endl; }

  ~Object() { std::cout << "Object::dtor() #" << n << std::endl; }

  int n;
};

// Базовый класс
class Base {
 public:
  Base() { std::cout << "Base::ctor()" << std::endl; }

  virtual ~Base() { std::cout << "Base::dtor()" << std::endl; }

  virtual void print() = 0;
};

// Производный класс
class Derived : public Base {
 public:
  Derived() { std::cout << "Derived::ctor()" << std::endl; }

  ~Derived() override { std::cout << "Derived::dtor()" << std::endl; }

  void print() {}

  Object obj1{1};
  Object obj2{2};
};

int main(int argc, char* argv[]) {
  A a;
  B b;
  std::cout << "=== create C === " << std::endl;
  {
    C c{a, b};
    std::cout << "=== destroy C start === " << std::endl;
  }
  std::cout << "=== destroy end === " << std::endl;
  // A a;
  // B b;
  // std::cout << "C(a, b)" << std::endl;
  // C c(a, b);
  // C *pc;
  //{
  //  std::cout << "C(a, b)" << std::endl;
  //  C c(a, b);
  //  std::cout << "C(a, b)" << std::endl;
  //  pc = new C(a, b);
  //  std::cout << "end of scope" << std::endl;
  //}
  // std::cout << "destructor call" << std::endl;
  // delete pc;
  // std::cout << "end of scope" << std::endl;

  // Base* p = new Derived;
  // delete p;

  return 0;
}
