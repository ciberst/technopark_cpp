#include <iostream>

struct A {};

struct B : public A {};

struct AA {
  AA() {
    //  bar();
  }
  virtual void bar() = 0;
  virtual A* test() {
    std::cout << "test - A" << std::endl;
    return new A{};
  };
};

struct BB : public AA {
  BB() { bar(); }
  virtual void foo() { std::cout << "BB" << std::endl; };
  void bar() override { std::cout << "bar" << std::endl; };
  B* test() override {
    std::cout << "test - B" << std::endl;
    return new B{};
  };
};

struct CC : public BB {
  void foo() { std::cout << "CC" << std::endl; };
};

int main() {
  //  AA* aa = new BB{};
  //  aa->test();
  return 0;
}

struct Test {
  virtual void init() = 0;
};

inline void Test::init() {}