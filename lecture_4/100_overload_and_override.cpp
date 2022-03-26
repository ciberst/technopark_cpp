#include <iostream>

class Account {
 public:
  void display(const char*) {
    std::cout << "display(const char*)" << std::endl;
  }
  void display(const int = 0) {
    std::cout << "display(const int)" << std::endl;
  }
};

class Deposit : public Account {
 public:
  void display(const std::string&) {
    std::cout << "display(const std::string&)" << std::endl;
  }
  using Account::display;
};

int main(int, char*[]) {
  Deposit t;
  t.display("Hello, World!");
  return 0;
}