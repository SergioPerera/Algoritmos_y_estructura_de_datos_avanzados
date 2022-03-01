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
  Grid(int& rows, int& cols, std::vector<std::pair<int,int>>& living_cells);
  ~Grid();

  /// Métodos
  const Cell& getCell(int row, int col) const;
	void NextGeneration();

 private:
  int rows_{0}; /// número de filas 
  int cols_{0}; /// número de columnas
  int** matrix; /// puntero que apunta a vector de vectores de enteros 

};

#endif