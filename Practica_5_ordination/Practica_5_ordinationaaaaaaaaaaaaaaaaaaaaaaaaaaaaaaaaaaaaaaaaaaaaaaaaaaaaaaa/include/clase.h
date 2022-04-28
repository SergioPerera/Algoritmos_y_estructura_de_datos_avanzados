#include <string>
#include <iostream>

class Libro {
  public:
  Libro(unsigned u = 0) { isbn_ = u;};
  Libro() {};
  static unsigned count;

  operator unsigned(){
    unsigned u;
    u = std::stoi(isbn_);
    return u;
  };
  bool operator==(Libro lib) const {
    std::string temp{lib.GetISBN()};
    if (isbn_ == temp) {
      return true;
    }
    return false;
  }

  bool operator>=(Libro lib) const {
    if (isbn_ >= lib.GetISBN()) {
      return true;
    }
    return false;
  }

  bool operator<=(Libro lib) const {
    if (isbn_ <= lib.GetISBN()) {
      return true;
    }
    return false;
  }

  bool operator<(Libro lib) const {
    if (isbn_ < lib.GetISBN()) {
      return true;
    }
    return false;
  }

  bool operator>(Libro lib) const {
    if (isbn_ > lib.GetISBN()) {
      return true;
    }
    return false;
  }

  void SetISBN(std::string i) {
    isbn_ = i;
  }
  std::string GetISBN() {
    return(isbn_);
  }
  Libro& operator=(std::string a) {
    isbn_ = a;
    return *this;
  }
  Libro& operator=(Libro& l) { 
    isbn_ = l.GetISBN();
    count++;
    return(*this);
   }

  // int operator*(std::string str) const {
  //   return(isbn_*str);
  // }

  // int operator/(const int& juisjuis) const {
  //   return(eggs/juisjuis);
  // }

  // int operator+(const int& juisjuis) const {
  // return(eggs+juisjuis);
  // }

  // int operator-(const int& juisjuis) const {
  // return(eggs-juisjuis);
  // }

  friend std::ostream& operator<<(std::ostream& os, Libro& lib) {
    os << lib.GetISBN() << " ";
    return(os); 
  }
  private:
  std::string isbn_;
};