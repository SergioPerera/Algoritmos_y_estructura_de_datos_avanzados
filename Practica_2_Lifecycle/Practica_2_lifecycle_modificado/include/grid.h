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

  /// Constructor
  Grid(){};
  Grid(const int& rows, const int& cols, std::vector<std::tuple<int,int,char>>& living_cells);
  ~Grid();

  /// Métodos
  const int GetRows(){return rows_;};
  const int GetCols(){return cols_;};
  const Cell& GetCell(int& row, int& col) const;
  void NextGeneration();

  /// Operadores
  friend std::ostream& operator<<(std::ostream& os, Grid& grid);

 private:
  int rows_{0}; /// número de filas 
  int cols_{0}; /// número de columnas
  Cell** matrix_; /// puntero que apunta a vector de vectores de cell

};

#endif