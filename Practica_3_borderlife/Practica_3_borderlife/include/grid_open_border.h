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
* @file grid_open_border.h
*/
#ifndef _GRID_WITH_OPEN_BORDER_
#define _GRID_WITH_OPEN_BORDER_

#include "cell.h"
#include <vector> /// vector
#include <fstream>
// #include "grid.h"

/*
Al Tener header guards la clase cell no se define otra vez, por ello hay que
presentarle de manera manual la clase Cell
*/
class Cell;

/**
 * @brief Clase Grid que sirve para crear una matriz llena de células
 */
class GridWithOpenBorder : public Grid {

 public:

  // /// Constructor
  // GridWithOpenBorder(){};
  // GridWithOpenBorder(const int& rows, const int& cols, std::vector<std::tuple<int,int,char>>& living_cells);
  // ~GridWithOpenBorder();

  /// Métodos
  const int GetRows(){return rows_;};
  const int GetCols(){return cols_;};

  // Cell& GetCell(int&, int&);
  const Cell& GetCell(int&, int&) const override;

  /// Operadores
  friend std::ostream& operator<<(std::ostream& os, GridWithOpenBorder& grid);

 private:
  int rows_{0}; /// número de filas 
  int cols_{0}; /// número de columnas
  Cell** matrix_; /// puntero que apunta a vector de vectores de cell

};

#endif