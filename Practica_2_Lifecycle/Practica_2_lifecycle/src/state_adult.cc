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
* @file state_adult.cc
*/

#include "../include/state_adult.h"

#include "../include/state_egg.h"
#include "../include/state_dead.h"
#include "../include/state_pupa.h"

#include <iostream>

int State_adult::neighbors(const Grid& grid, int x, int y) {

  // int adults_{0};

  for (int i : {-1, 0, 1}) {
    for (int j : {-1, 0, 1}) {
      if ((x != x + i) || (y != y + j)) {
                                                           // std::cout << " ñaaaaaaaaaa-"<< grid.GetCell(x,y).GetState()->getState() << "-" <<  x << " " << y<< " " << adult_adyacent_cells_ << std::endl;
        int posx = x + i;
        int posy = y + j;
        if (grid.GetCell(posx,posy).GetState()->getState() == 'A'){
          adults_++;
        }
      }
    }
  }
  return (0);
}

State* State_adult::nextState() {
  std::cout << "->" << adults_ << std::endl;
  if (adults_ >= 1) {
    std::cout << "Retorno huevo" << std::endl;
    return(new State_egg);
  }
  else {
    std::cout << "Retorno dead" << std::endl;

    return(new State_dead);
  }
}