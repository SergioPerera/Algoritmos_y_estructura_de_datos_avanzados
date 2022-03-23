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
* @file grid.cc
*/

#include "../include/grid.h"
#include "../include/state.h"
#include "../include/state_dead.h"
#include "../include/state_alive.h"


#include <iostream>
#include <tuple>

#include <bits/stdc++.h> /// std::count
#define DEBUG 0
/**
 * @brief Construct a new Grid:: Grid object. Vamos a crear un objeto grid con 
 * memoria dinámica haciendo uso de new y punteros. Tanto a las filas como a las
 * columnas le vamos a sumar 2 de manera que la matriz es de (2+row)x(2+col).
 * Hacemos esto para que las células en los bordes y en las esquinas tengan
 * células muertas adyacentes. Trabajaremos dentro de las dimensiones colxrow
 * 
 * @param rows filas de la matriz 
 * @param cols columnas de la matriz
 * @param living_cells posiciones de las células vivas
 */
GridWithOpenBorder::GridWithOpenBorder(const int& rows, const int& cols, std::vector<std::tuple<int,int,char>>& living_cells) {

  /// Hacemos esto por lo descrito anteriormente
  rows_ = rows + 2;
  cols_ = cols + 2;
  /*
  * Creamos un vector y dentro de cada una de las posiciones creamos otro vector
  * y lo rellenamos a medida que las creamos con células muertas
  */
  /// Creamos las filas
  matrix_ = new Cell* [rows_];
  for (int i{0}; i < rows_; i++) {

    /// Creamos las columnas
    matrix_[i] = new Cell [cols_]; 

    /// Rellenamos las columnas con células con distintos estados
    for(int j{0}; j < cols_; j++) {
      /// Coordenadas actuales de la matriz
      std::pair<int,int> matrix_coordinates{i,j};

      /// Creamos la célula muerta
      State* initial_state{new State_dead};
      Cell dead_cell{initial_state, matrix_coordinates};
      matrix_[i][j] = dead_cell;
    }
  }

  ///Introducimos las células de distinto tipo que ha especificado el usuario
  for (long unsigned int k{0}; k < living_cells.size(); k++) {

    int i = std::get<0>(living_cells[k]);
    int j = std::get<1>(living_cells[k]);
    switch(std::get<2>(living_cells[k])) {
      case ' ' : {
        matrix_[i][j].SetState(new State_dead);
      }
      break;
      case 'A' : {
        matrix_[i][j].SetState(new State_alive);
      }
      break;
    }
  }
}

/**
 * @brief Destroy the Grid:: Grid object. Liberamos el objeto grid de memoria
 * 
 */
GridWithOpenBorder::~GridWithOpenBorder(){
  /// Liberamos la memoria ocupada por matrix_
  /*
  * Primero tendríamos que borrar los vectores que contienen vectores y, por 
  * último borrar el vector que contenía los vectores anteriormente dichos
  */
  for (int i{0}; i < rows_; i++) {
    delete [] matrix_[i];
  }
  delete [] matrix_; 
}

/**
 * @brief Función que devuelve la célula en modo lectura
 * 
 * @param row Filas
 * @param col Columnas
 * @return const Cell& 
 */
const Cell& GridWithOpenBorder::GetCell(int& row, int& col) const {
  return(matrix_[row][col]);
}

Cell& GridWithOpenBorder::GetCell(int& row, int& col) {
  return(matrix_[row][col]);
}

/**
 * @brief Operador para imprimir por pantalla
 * 
 * @param os parámetro std::ostream
 * @param grid objeto grid para imprimir
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, GridWithOpenBorder& grid) {
  // os << std::endl;
  // for (int i{1}; i < grid.GetRows() - 1; i++) {
  //   for(int j{1}; j < grid.GetCols() - 1; j++) {
  //     os << grid.GetCell(i,j).GetState()->getState() << " ";
  //   }
  //   os << std::endl;
  // }
  grid.PrintMatrix(os);
  return(os);
}

void GridWithOpenBorder::PrintMatrix (std::ostream& os) {
  os << std::endl;
  for (int i{1}; i < GetRows() - 1; i++) {
    for(int j{1}; j < GetCols() - 1; j++) {
      os << GetCell(i,j).GetState()->getState() << " ";
    }
    os << std::endl;
  }
}



