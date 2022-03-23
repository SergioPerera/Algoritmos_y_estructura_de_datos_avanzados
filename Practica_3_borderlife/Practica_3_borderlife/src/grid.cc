/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica del juego de la vida
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 22/03/2022
* @file grid.cc
*/

#include "../include/grid.h"
#define PLUS_SIZE 1
/**
 * @brief Método encargado de hacer que las propias células se actualicen
 * 
//  */
void Grid::NextGeneration() {
  /*
  * Hacemos un bucle que recorra todas las células, menos los bordes para que
  * cuenten las células vecinas que tienen
  */
  for (int i{PLUS_SIZE}; i < rows_ - PLUS_SIZE; i++) {
    for(int j{PLUS_SIZE}; j < cols_ - PLUS_SIZE; j++) {
      /// Cogemos la célula y hacemos que mire sus vecinos
      matrix_[i][j].NeighborsAlive(*this);
    }
  }
  /*
  * Hacemos un bucle que recorra todas las células, menos los bordes para que
  * cada célula actualice su estado
  */
  for (int i{PLUS_SIZE}; i < rows_ - PLUS_SIZE; i++) {
    for(int j{PLUS_SIZE}; j < cols_ - PLUS_SIZE; j++) {
      /// Cogemos la célula y hacemos que mire sus vecinos
      matrix_[i][j].UpdateState();
    }
  }
}
