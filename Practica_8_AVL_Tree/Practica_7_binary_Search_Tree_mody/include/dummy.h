#include <fstream>
#include <iostream>
#include <time.h>
#ifndef _DUMMY_H_
#define _DUMMY_H_
class Dummy {
 public:
  static unsigned counter;
  Dummy(){key = 0;};
  Dummy(int in_key) {key = in_key;};

  friend bool operator==(const Dummy dum1, const Dummy dum2) {
    counter++;
    return dum1.key==dum2.key;
  }
  friend bool operator<(const Dummy dum1, const Dummy dum2) {
    counter++;
    return dum1.key < dum2.key;
  }
  friend bool operator>(const Dummy dum1, const Dummy dum2) {
    counter++;
    return dum1.key > dum2.key;
  }
  friend std::ostream& operator<<(std::ostream& os, const Dummy dum) {
    os << dum.key;
    return os;
  }
  friend Dummy& operator+(Dummy& dum, int n) {
    dum.key += n; 
    return dum;
  }

  int key;
};

#endif // _DUMMY_H_