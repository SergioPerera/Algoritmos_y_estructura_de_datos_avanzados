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
#ifndef _GRID_BASE_H_
#define _GRID_BASE_H_

#include "cell.h"
#include <vector> /// vector
#include <fstream>
#include <iostream>

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
  /// Métodos
  void NextGeneration();

  const int GetRows(){return rows_;};
  const int GetCols(){return cols_;};

  /// Operadores
  friend std::ostream& operator<<(std::ostream& os, Grid& grid) {
    return(grid.PrintMatrix(os));};


  /// Destructor
  // virtual ~Grid();
  virtual Cell& GetCell(int&, int&) =0;
  virtual const Cell& GetCell(int&, int&) const =0;
  virtual std::ostream& PrintMatrix(std::ostream& os) =0;
 protected: 
  Cell** matrix_; /// puntero que apunta a vector de vectores de cell
  int rows_{0}; /// número de filas 
  int cols_{0}; /// número de columnas
};


/**
 * @brief Clase para matriz normal
 * 
 */
class GridWithOpenBorder : public Grid {
 public:

  /// Constructor
  GridWithOpenBorder(){};
  GridWithOpenBorder(const int& rows, const int& cols, std::vector<std::tuple<int,int,char>>& living_cells);
  ~GridWithOpenBorder();

  /// Métodos
  const int GetRows(){return rows_;};
  const int GetCols(){return cols_;};

  Cell& GetCell(int&, int&) override;
  const Cell& GetCell(int&, int&) const override;

  /// Operadores
  std::ostream& PrintMatrix(std::ostream& os) override;
  // friend std::ostream& operator<<(std::ostream& os, GridWithOpenBorder& grid);
};

#endif