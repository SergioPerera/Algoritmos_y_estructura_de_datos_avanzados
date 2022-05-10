#include<iostream>

class loco {
  public:
  void Func(std::string str = "valor por defecto") : str_(str) {};
  private:
  std::string str_;
};


int main () {

  return(0);
}