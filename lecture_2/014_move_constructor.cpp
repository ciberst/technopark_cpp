#include <iostream>

class Alpha {
private:
    std::size_t sz;
    double *d;
public:
    Alpha();
    Alpha(const Alpha &a);
    Alpha(Alpha &&a);
    ~Alpha();
};

Alpha::Alpha() : sz(0), d(NULL) {
    std::cout << "Alpha()" << std::endl;
}

Alpha::~Alpha() {
    std::cout << "~Alpha()" << std::endl;
    delete []d;
}

Alpha::Alpha(const Alpha &a) : sz(a.sz) {
    std::cout << "Alpha(const Alpha &a)" << std::endl;
    d = new double[sz];
    for (std::size_t i = 0; i < sz; ++i) {
        d[i] = a.d[i];
    }
}

Alpha::Alpha(Alpha &&a) : sz(a.sz) {
    std::cout << "Alpha(Alpha &&a)" << std::endl;
    d = a.d;
    a.d = nullptr;
    a.sz = 0;
}

Alpha foo(Alpha arg) {
   return arg;
}

void bar(Alpha arg) {
}

int main(int argc, char *argv[]) {
    std::cout << "Alpha alp1 = foo(Alpha())" << std::endl;
    Alpha alp1 = foo(Alpha());

    std::cout << "\nfoo(alp1)" << std::endl;
    foo(alp1);

    std::cout << "\nfoo(std::move(alp1))" << std::endl;
    foo(std::move(alp1));

    std::cout << "\nAlpha alp2 = alp1" << std::endl;
    Alpha alp2 = alp1;

    std::cout << "\nAlpha alp3(alp1)" << std::endl;
    Alpha alp3(alp1);

    std::cout << "\nAlpha alp4 = std::move(alp1)" << std::endl;
    Alpha alp4 = std::move(alp1);

    std::cout << "\nAlpha alp5(std::move(alp1))" << std::endl;
    Alpha alp5(std::move(alp1));

    std::cout << "\nbar(alp2)" << std::endl;
    bar(alp2);

    std::cout << "\nbar(std::move(alp2))" << std::endl;
    bar(std::move(alp2));

    std::cout << "end of scope" << std::endl;
    return 0;
}
