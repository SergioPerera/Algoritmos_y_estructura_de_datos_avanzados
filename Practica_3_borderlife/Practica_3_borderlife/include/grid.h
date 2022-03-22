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
* @file grid.h
*/
#ifndef _GRID_H_
#define _GRID_H_

#include "cell.h"
#include <vector> /// vector
#include <fstream>

/*
Al Tener header guards la clase cell no se define otra vez, por ello hay que
presentarle de manera manual la clase Cell
*/
class Cell;
/**
 * @brief Clase Grid que sirve para crear una matriz llena de células
 */
class Grid {

 public:
  // /// Operadores
  /// Métodos
  void NextGeneration();
  // friend std::ostream& operator<<(std::ostream& os, Grid& grid);

  /// Destructor
  virtual ~Grid();
  // virtual Cell& GetCell(int&, int&) =0;
  virtual const Cell& GetCell(int&, int&) const =0;

//  protected: 
//   int rows_{0}; /// número de filas 
//   int cols_{0}; /// número de columnas
//   Cell** matrix_; /// puntero que apunta a vector de vectores de cell
};

#endif