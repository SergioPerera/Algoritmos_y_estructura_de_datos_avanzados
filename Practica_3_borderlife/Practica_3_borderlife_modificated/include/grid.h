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
  virtual Cell& GetCell(int&, int&) =0;
  virtual const Cell& GetCell(int&, int&) const =0;
  virtual void PrintMatrix(std::ostream& os) =0;

  /// Operadores
  friend std::ostream& operator<<(std::ostream& os, Grid& grid) { 
    grid.PrintMatrix(os);
    return(os);
  }

  virtual void ShowNeighbors(int& x, int& j) =0;
  /// Modificación
  /// Destructor
  // virtual ~Grid();
 protected: 
  Cell** matrix_; /// puntero que apunta a vector de vectores de cell
  int rows_{0}; /// número de filas 
  int cols_{0}; /// número de columnas
  int rows_less{0}; /// número de filas 
  int cols_less{0}; /// número de columnas
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
  void PrintMatrix(std::ostream& os) override;
  friend std::ostream& operator<<(std::ostream& os, GridWithOpenBorder& grid);

  void ShowNeighbors(int& x, int& j) override {};

};

/**
 * @brief Clase para matriz normal
 * 
 */
class GridWithPeriodicBorder : public Grid {
 public:

  /// Constructor
  GridWithPeriodicBorder(){};
  GridWithPeriodicBorder(const int& rows, const int& cols, std::vector<std::tuple<int,int,char>>& living_cells);
  ~GridWithPeriodicBorder();

  /// Métodos
  const int GetRows(){return rows_;};
  const int GetCols(){return cols_;};

  Cell& GetCell(int&, int&) override;
  const Cell& GetCell(int&, int&) const override;

  /// Operadores
  void PrintMatrix(std::ostream& os) override;
  friend std::ostream& operator<<(std::ostream& os, GridWithPeriodicBorder& grid);

  void ShowNeighbors(int& x, int& j) override {};

};

/**
 * @brief Clase para matriz normal
 * 
 */
class GridWithReflectiveBorder : public Grid {
 public:

  /// Constructor
  GridWithReflectiveBorder(){};
  GridWithReflectiveBorder(const int& rows, const int& cols, std::vector<std::tuple<int,int,char>>& living_cells);
  ~GridWithReflectiveBorder();

  /// Métodos
  const int GetRows(){return rows_;};
  const int GetCols(){return cols_;};

  Cell& GetCell(int&, int&) override;
  const Cell& GetCell(int&, int&) const override;

  /// Operadores
  void PrintMatrix(std::ostream& os) override;
  friend std::ostream& operator<<(std::ostream& os, GridWithReflectiveBorder& grid);

  void ShowNeighbors(int& x, int& j) override;
};
#endif