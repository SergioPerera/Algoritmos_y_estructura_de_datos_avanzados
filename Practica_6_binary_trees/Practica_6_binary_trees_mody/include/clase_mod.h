
#include <iostream>

class Mod {
 public:
  Mod(const int& key = 0, const std::string& in_name = "") : clave(key), name(in_name) {};
  int clave;
  std::string name;
  bool operator==(const Mod& other) const;
  bool operator[](const Mod& other) const;
  
  friend std::ostream& operator<<(std::ostream& out, const Mod& other);
};

bool Mod::operator==(const Mod& other) const {
  return ((clave == other.clave) && (name == other.name));
}


std::ostream& operator<<(std::ostream& out, const Mod& other) {
  return out << other.name << ": " << other.clave << " ";
}


