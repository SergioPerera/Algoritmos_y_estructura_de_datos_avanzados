#include<iostream>
#include "../include/basura.h"


int main () {
  loco lokaso{};
  std::cout << "Creo por defecto -> " << lokaso.str_ << std::endl;

  loco loquito {"valor puesto por mi"};
  std::cout << "Creo con valor -> " << loquito.str_ << std::endl;

  return(0);
}