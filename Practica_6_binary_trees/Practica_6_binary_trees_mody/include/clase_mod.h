
#include <iostream>
#ifndef _MOD_H
#define _MOD_H
class Mod {
 public:
  Mod(const int& key = 0, const std::string& in_name = "") : clave(key), name(in_name) {};
  int clave;
  std::string name;
  bool operator==(const Mod& other) const;
  bool operator>(const Mod& other) const { return clave > other.clave;}
  // Add operator+
  Mod operator+(const Mod& other) const { 
    return Mod(clave + other.clave, name + other.name);
  }

  bool operator[](const Mod& other) const;

  
  friend std::ostream& operator<<(std::ostream& out, const Mod& other);
};

bool Mod::operator==(const Mod& other) const {
  return ((clave == other.clave) && (name == other.name));
}


std::ostream& operator<<(std::ostream& out, const Mod& other) {
  if (other.name.empty()){
    return out << other.clave << ":N";
  }else{
    return out << other.clave << ":" << other.name;
  }
}


#endif // _MOD_H