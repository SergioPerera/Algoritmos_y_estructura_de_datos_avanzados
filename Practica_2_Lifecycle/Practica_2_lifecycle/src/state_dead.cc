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
* @file state_dead.cc
*/

#include "../include/state_dead.h"
#include <iostream>

int State_dead::neighbors(const Grid& grid, int x, int y) {

  adult_adyacent_cells_ = 0;

  for (int i : {-1, 0, 1}) {
    for (int j : {-1, 0, 1}) {
      if ((x != x + i) || (y != y + j)) {
                                                std::cout << " ñaaaaaaaaaa-"<< grid.GetCell(x,y).GetState()->getState() << "-" <<  x << " " << y<< " " << adult_adyacent_cells_ << std::endl;
        int posx = x + i;
        int posy = y + j;
        if (grid.GetCell(posx,posy).GetState()->getState() == 'A'){
          adult_adyacent_cells_++;
        }
      }
    }
  }
}

State* State_dead::nextState() {
  if (adult_adyacent_cells_ > 2 ) {
    
  }
}