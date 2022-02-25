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
* @file grid.h
*/
#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
/**
 * @brief Clase Grid que sirve para crear una matriz llena de células
 */
class Grid {

 public:

  /// Constructor
  Grid(int& cols, int& rows, std::vector<std::pair<int,int>>& living_cells);

 private:
  int rows_{0};
  int cols_{0};

};
#endif