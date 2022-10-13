#include <iostream>

class A {};  // sizeof == 1

class AWithVirtual {  // sizeof == ?
  virtual void bar() {}
};  

class B : public A {};  // sizeof == ?

class C : public A {  // sizeof == ?
 public:
  virtual void bar() {
     
  }
};

class G : public C {
public:
    void bar() {

    }
};

class D : public C {
 public:
  virtual void foo() {}
};

class Base1 {
 public:
  virtual void bar() {}
};

class Base2 {
 public:
  virtual void foo() {}
};

class E : public Base1, public Base2 {
 public:
  virtual void bar() {}
  virtual void foo() {}
  virtual void a() {}
};

#define PRINT_SIZE(X) std::cout << "sizeof(" #X ") = " << sizeof(X) << std::endl

int main() {
  E e;
  Base1& c = e;

  C* a = new G();

  PRINT_SIZE(A);
  PRINT_SIZE(AWithVirtual);
  PRINT_SIZE(B);
  PRINT_SIZE(C);
  PRINT_SIZE(D);
  PRINT_SIZE(E);
}