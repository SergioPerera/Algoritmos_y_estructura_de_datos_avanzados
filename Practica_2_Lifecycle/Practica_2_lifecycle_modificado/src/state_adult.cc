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
#include "../include/state_larva.h"


#include <iostream>

int State_adult::neighbors(const Grid& grid, int x, int y) {


  for (int i : {-1, 1}) {
    for (int j : {-1, 1}) {
      if ((x != x + i) || (y != y + j)) {

        int posx = x + i;
        int posy = y + j;
        if (grid.GetCell(posx,posy).GetState()->getState() == 'A'){
          adults_++;
        }
        if (grid.GetCell(posx,posy).GetState()->getState() == 'H'){
          eggs_++;
        }
        if (grid.GetCell(posx,posy).GetState()->getState() == 'L'){
          larvas_++;
        }
        if (grid.GetCell(posx,posy).GetState()->getState() == 'P'){
          pupas_++;
        }
        if (grid.GetCell(posx,posy).GetState()->getState() == ' '){
          dead_++;
        }
      }
    }
  }
  return (0);
}

State* State_adult::nextState() {
  int mayor_number_cell{adults_};
  if(larvas_ > mayor_number_cell) { mayor_number_cell = larvas_;};
  if(eggs_ > mayor_number_cell) { mayor_number_cell = eggs_;};
  if(pupas_ > mayor_number_cell) { mayor_number_cell = pupas_;};

  if (adults_ >= 1) {
    return(new State_egg);
  }
  else if(dead_ == 4) {
    return (new State_dead);
  }
  else if(larvas_ > eggs_ && larvas_ > pupas_  ) {
    return (new State_larva);
  }
  else if(eggs_ > larvas_ && eggs_ > pupas_ ) {
    return (new State_egg);
  }
  else if(pupas_ > larvas_ && pupas_ > eggs_  ) {
    return (new State_egg);
  }
  else {
    return(new State_dead);
  }
}