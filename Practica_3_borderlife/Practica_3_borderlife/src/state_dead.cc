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
#include "../include/state_alive.h"

#include <iostream>

int State_dead::neighbors(const Grid& grid, int x, int y) {


  for (int i : {-1, 0, 1}) {
    for (int j : {-1, 0, 1}) {
      if ((x != x + i) || (y != y + j)) {
        int posx = x + i;
        int posy = y + j;
        if (grid.GetCell(posx,posy).GetState()->getState() == 'A'){
          alive_cells_ ++;
        }
      }
    }
  }
  return (0);
}

State* State_dead::nextState() {
  if (alive_cells_ == 3 ) {
    return(new State_alive); ///////////////////////////////// poner el estado correspondiente;
  }
  else {
    return(new State_dead);
  }
}