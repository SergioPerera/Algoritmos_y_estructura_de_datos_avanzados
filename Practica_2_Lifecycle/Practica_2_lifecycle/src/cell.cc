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
Cell::Cell(State* initial_state, std::pair<int, int>& initial_position) {
  state_ = initial_state;
  position_ = initial_position;

  // std::cout << position_.first << "          " << position_.second << std::endl;
}

/**
 * @brief Método encargado de contar las células adyacentes y vivas de la célula
 * actual
 * 
 * @param grid matriz de células
 * @return int Retorna el número de células vivas
 */
int Cell::NeighborsAlive(const Grid& grid) {
  // /// Reiniciamos neighbours_ para que cuando hagamos varias iteraciones no se
  // /// sumen entre ellas
  // neighbours_ = 0;
  // int x = position_.first;
  // int y = position_.second;

  // /// Miramos las coordenadas adyacentes
  // for (int i : {-1, 0, 1}) {
  //   for (int j : {-1, 0, 1}) {
  //     if ((x != x + i) || (y != y + j)) {
  //       int neightbour_x = x + i;
  //       int neightbour_y = y + j;
  //       if (grid.GetCell(neightbour_x, neightbour_y).GetState() == 1 ){
  //         neighbours_++;
  //       };
  //     }
  //   }
  // }
  return(state_->neighbors(grid, position_.first, position_.second));
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  os << cell.GetState();
  return(os);
}

/**
 * @brief Método encargado de que la célula se actualice según los vecinos vivos 
 * que tenga
 * 
 */
void Cell::UpdateState() {
  state_->nextState();
}