/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica del ciclo de la vida
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 15/03/2022
* @file state_egg.cc
*/


#include "../include/state_egg.h"
#include "../include/state_dead.h"
#include "../include/state_larva.h"

#include <iostream>

int State_egg::neighbors(const Grid& grid, int x, int y) {

  // int larvas_{0};
  // int eggs_{0};

  for (int i : {-1, 0, 1}) {
    for (int j : {-1, 0, 1}) {
      if ((x != x + i) || (y != y + j)) {
        int posx = x + i;
        int posy = y + j;
        if (grid.GetCell(posx,posy).GetState()->getState() == 'L'){
          larvas_++;
        }
        if (grid.GetCell(posx,posy).GetState()->getState() == 'H'){
          eggs_++;
        }
                                                            //  std::cout << " ñaaaaaaaaaa-"<< grid.GetCell(posx,posy).GetState()->getState() << "-" <<  x + i  << " " << y + j << " " << larvas_ << " " << eggs_ << std::endl;
      }
    }
  }
  return (0);
}

State* State_egg::nextState() {
  std::cout << "->" << larvas_ << " " << eggs_ << std::endl;
  if (larvas_ > eggs_ ) {
    std::cout << "retorno muerta " << std::endl;
    return(new State_dead);
  }
  else {
    std::cout << "retorno larva " << std::endl;
    return(new State_larva);
  }
}