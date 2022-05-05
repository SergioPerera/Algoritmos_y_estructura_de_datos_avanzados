#include <string>
#include <iostream>

#ifndef _LIBRO_H_
#define _LIBRO_H_

class Libro {
  public:
  Libro(unsigned u = 0) { isbn_ = u;};
  static unsigned count;

  operator unsigned(){
    unsigned u;
    u = std::stoi(isbn_);
    return u;
  };
  bool operator==(const Libro& lib) const {
    if (isbn_ == lib.isbn_) {
      return true;
    }
    return false;
  }

  bool operator>=(const Libro& lib) const {
    if (isbn_ >= lib.isbn_) {
      return true;
    }
    return false;
  }
  bool operator>=(const int& i) const {
    if (std::stoi(isbn_) >= i) {
      return true;
    }
    return false;
  }

  bool operator<=(const Libro& lib) const {
    if (isbn_ <= lib.isbn_) {
      return true;
    }
    return false;
  }

  bool operator<(const Libro& lib) const {
    if (isbn_ < lib.isbn_) {
      return true;
    }
    return false;
  }

  bool operator>(const Libro& lib) const {
    if (isbn_ > lib.isbn_) {
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
  Libro& operator=(const Libro& l) { 
    isbn_ = l.isbn_;
    count++;
    return(*this);
   }

  std::string operator+(int n) {
    int s = std::stoi(isbn_);
    int temp = n + s;
    std::string str;
    str += temp;
    isbn_ = str;
    return(isbn_);
  }
  std::string operator+(Libro& n) {
    int temp = std::stoi(n.isbn_) + std::stoi(isbn_);
    std::string str;
    str += temp;
    isbn_ = str;
    return(isbn_);
  }

  std::string operator-(int n) {
    int s = std::stoi(isbn_);
    int temp = n - s;
    std::string str;
    str += temp;
    isbn_ = str;
    return(isbn_);
  }
   std::string operator/(Libro& n) {
    int temp = std::stoi(n.isbn_) / std::stoi(isbn_);
    std::string str;
    str += temp;
    isbn_ = str;
    return(isbn_);
  }
  std::string operator/(int n) {
    int temp = std::stoi(isbn_) / n;
    std::string str;
    str += temp;
    isbn_ = str;
    return(isbn_);
  }

  friend std::ostream& operator<<(std::ostream& os, Libro& lib) {
    os << lib.isbn_ << " ";
    return(os); 
  }
  private:
  std::string isbn_;
};

#endif // _LIBRO_H_