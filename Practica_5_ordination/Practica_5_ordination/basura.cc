#include <iostream>
class RamdomClass { 
public:
  RamdomClass() {};
  bool operator==(const int& juisjuis) const {
    if (pp_ == juisjuis) {
      return true;
    }
    return false;
  }
private:
int pp_{69};
};

int main() {
  int plol{69};
  int nlol{0};

  RamdomClass r;

  if (r == nlol) {
    std::cout << "igual" << std::endl;
  }
  else {
    std::cout << "no igual" << std::endl;
  }

  
}