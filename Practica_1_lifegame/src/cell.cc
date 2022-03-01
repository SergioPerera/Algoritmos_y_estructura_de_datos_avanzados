/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica del juego de la vida
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 24/02/2022
* @file cell.cc
*/

#include "../include/cell.h"
#include <iostream>
/**
 * @brief Construct a new Cell:: Cell object
 * 
 * @param initial_state Estado inicial
 * @param initial_position Posición dentro de la matriz de células 
 */
Cell::Cell(state& initial_state, std::pair<int, int> initial_position) {
  state_ = initial_state;
  position_ = initial_position;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  switch(cell.GetState()){
    case 1:
      os << "x";
    break;
    case 0:
      os << "o";
    break;
  }
  return(os);
}
