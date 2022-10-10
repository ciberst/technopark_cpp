#include <iomanip>
#include <iostream>
#include <string>

class Integer {
 public:
  Integer() : value_(0){};
  explicit Integer(int value) : value_(value) {}
  Integer(const Integer&) = default;
  Integer(Integer&&) = default;
  ~Integer() = default;

  int value() const { return value_; }

  Integer& operator=(const Integer&) = default;
  Integer& operator=(Integer&&) = default;

  Integer& operator+=(const Integer& other) {
    value_ += other.value_;
    return *this;
  }
  Integer& operator-=(const Integer& other) {
    value_ -= other.value_;
    return *this;
  }
  Integer& operator*=(const Integer& other) {
    value_ *= other.value_;
    return *this;
  }

  Integer& operator/=(const Integer& other) {
    value_ /= other.value_;
    return *this;
  }

  bool operator[](uint8_t number_of_bit) {
    return (value_ >> number_of_bit) & 1;
  }

  const Integer& operator++() {
    ++value_;
    return *this;
  }

  const Integer operator++(int) {
    Integer old(value_);
    ++value_;
    return old;
  }

  //auto operator<=>(const Integer& lhs) const = default;

 private:
  int value_;
};

std::ostream& operator<<(std::ostream& o, const Integer& x) {
  o << x.value();
  return o;
}

bool operator==(const Integer& lhs, const Integer& rhs) {
  return lhs.value() == rhs.value();
}

bool operator!=(const Integer& lhs, const Integer& rhs) {
  return lhs.value() != rhs.value();
}

bool operator<(const Integer& lhs, const Integer& rhs) {
  return lhs.value() < rhs.value();
}

bool operator>(const Integer& lhs, const Integer& rhs) {
  return lhs.value() > rhs.value();
}

bool operator>=(const Integer& lhs, const Integer& rhs) {
  return lhs.value() >= rhs.value();
}

bool operator<=(const Integer& lhs, const Integer& rhs) {
  return lhs.value() >= rhs.value();
}

 //auto operator<=>(const Integer& lhs, const Integer& rhs) {
 //    return lhs.value() <=> rhs.value();
 //}

int main() {
  Integer i{42};

  std::cout << i;

  std::cout << " + 36 = ";
  i += Integer{36};

  std::cout << i << std::endl;

  // 101
  Integer five{5};
  for (int i = 0; i < 3; ++i)
    std::cout << five[i];
  std::cout << std::endl;

  std::cout << std::boolalpha << (Integer{42} != Integer{43}) << std::endl;
  std::cout << std::boolalpha << (Integer{42} == Integer{43}) << std::endl;
  std::cout << std::boolalpha << (Integer{42} < Integer{43}) << std::endl;
  std::cout << std::boolalpha << (Integer{42} > Integer{43}) << std::endl;

  Integer value{42};
  Integer prefix = (++value);
  value = Integer{42};
  Integer postfix = (value++);

  std::cout << prefix << " " << postfix << std::endl;

  return 0;
}