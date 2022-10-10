#include <iostream>

class NonVirtual {
 public:
  NonVirtual() { std::cout << "ctor NonVirtual::NonVirtual()" << std::endl; }
  ~NonVirtual() { std::cout << "dtor NonVirtual::~NonVirtual()" << std::endl; }
};

class Object {
 public:
  Object() { std::cout << "ctor Object::Object()" << std::endl; }
  virtual ~Object() { std::cout << "dtor Object::~Object()" << std::endl; }

  virtual void foo() const { std::cout << "Object::foo()" << std::endl; }
};

class Clickable : public virtual Object {
 public:
  Clickable() { std::cout << "ctor Clickable::Clickable()" << std::endl; }
  ~Clickable() override {
    std::cout << "dtor Clickable::~Clickable()" << std::endl;
  }
  void foo() const override { std::cout << "Clickable::foo()" << std::endl; }
};

class Rectangle : public virtual Object {
 public:
  Rectangle() { std::cout << "ctor Rectangle::Rectangle()" << std::endl; }
  ~Rectangle() override {
    std::cout << "dtor Rectangle::~Rectangle()" << std::endl;
  }
  void foo() const override { std::cout << "Rectangle::foo()" << std::endl; }
};

class Button : public NonVirtual, public Rectangle, public Clickable {
 public:
  Button() { std::cout << "ctor Button::Button()" << std::endl; }
  ~Button() override { std::cout << "dtor Button::~Button()" << std::endl; };
  void foo() const override { std::cout << "Button::foo()" << std::endl; }
};

int main() {
  Object* object = new Button();
  object->foo();
  delete object;
  return 0;
}