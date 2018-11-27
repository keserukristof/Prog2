#include <iostream>

class Alma {

public:

  double* d;

  Alma(double c)
      : d(new double(c)) { }

  // copy ctor
  Alma() {
    d = nullptr;
  }

  Alma(const Alma &a) {
    d = a.d;
    std::cout << "copy ctor" << std::endl;
  }


  // move ctor
  Alma(Alma&& a) {
    a = std::move(a);
    std::cout << "move ctor" << std::endl;
  }

  //move assign
  Alma& operator= (Alma&& a) {
    if (this != &a) {
      d = a.d;
      a.d = nullptr;
      std::cout << "move assign" << std::endl;
    }
    return *this;
  }

  //copy assign
  Alma& operator=(const Alma& a) {
    if (this != &a) {
      delete d;
      d = a.d;
      std::cout << "copy assign" << std::endl;
    }
    return *this;
  }

  //dtor
  ~Alma() {
    delete d;
  }

};

Alma f(Alma a) {
  return a;
}

int main(){

    Alma a(3.14);
    Alma b = a;
    if (a.d == b.d) {
      std::cout << "copy ctor helyes" << std::endl;
    } else {
      std::cout << "copy ctor helytelen" << std::endl;
    }
    Alma c(2.12);
    a = c;
    if (a.d == c.d) {
      std::cout << "copy assign helyes" << std::endl;
    } else {
      std::cout << "copy assign helytelen" << std::endl;
    }
    Alma d(f(Alma(1.2)));
    Alma e;
    e = std::move(a);
    if (e.d == c.d && a.d == nullptr) {
      std::cout << "move assign helyes" << std::endl;
    } else {
      std::cout << "move assign helytelen" << std::endl;
    }
    return 0;

}
