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
* @file State_alive.cc
*/

#include "../include/state_alive.h"
#include "../include/state_dead.h"


#include <iostream>

/**
 * @brief Función encargada de mirar los vecinos
 * 
 * @param grid Matriz de células
 * @param x Posición x de la matriz
 * @param y POsición y de la matriz
 * @return int 
 */
int State_alive::neighbors(const Grid& grid, int x, int y) {
std::cout << "--------------------------------------------Mirando la vecindad de la célula " << x << " " << y << std::endl;
  for (int i : {-1, 0, 1}) {
    for (int j : {-1, 0, 1}) {
      if ((x != x + i) || (y != y + j)) {
        int posx = x + i;
        int posy = y + j;
        if (grid.GetCell(posx,posy).GetState()->getState() == 'A') {
          alive_cells_++;
        }
      }
    }
  }
std::cout << "Tengo estas vecinas -> " << alive_cells_ << std::endl;
  return (0);
}

/**
 * @brief Función que selecciona el estado en función de las células vivas alrededor
 * 
 * @return State* 
 */
State* State_alive::nextState() {
  if ((alive_cells_ == 2) || (alive_cells_ == 3) ) {
    return(new State_alive);
  }
  return(new State_dead);
}