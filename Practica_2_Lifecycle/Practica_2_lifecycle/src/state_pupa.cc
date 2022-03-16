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
* @file state_pupa.cc
*/



#include "../include/state_egg.h"
#include "../include/state_dead.h"
#include "../include/state_larva.h"
#include "../include/state_pupa.h"
#include "../include/state_adult.h"

#include <iostream>

int State_pupa::neighbors(const Grid& grid, int x, int y) {

  int larvas_{0};
  int eggs_{0};
  int adults_{0};
  int pupas_{0};

  for (int i : {-1, 0, 1}) {
    for (int j : {-1, 0, 1}) {
      if ((x != x + i) || (y != y + j)) {
                                                           // std::cout << " ñaaaaaaaaaa-"<< grid.GetCell(x,y).GetState()->getState() << "-" <<  x << " " << y<< " " << adult_adyacent_cells_ << std::endl;
        int posx = x + i;
        int posy = y + j;
        if (grid.GetCell(posx,posy).GetState()->getState() == 'L'){
          larvas_++;
        }
        if (grid.GetCell(posx,posy).GetState()->getState() == 'H'){
          eggs_++;
        }
        if (grid.GetCell(posx,posy).GetState()->getState() == 'A'){
          adults_++;
        }
        if (grid.GetCell(posx,posy).GetState()->getState() == 'P'){
          pupas_++;
        }
      }
    }
  }
}

State* State_pupa::nextState() {
  if (larvas_ > eggs_ && larvas_ > pupas_ && larvas_ > adults_) {
    return(new State_dead);
  }
  else {
    return(new State_pupa);
  }
}