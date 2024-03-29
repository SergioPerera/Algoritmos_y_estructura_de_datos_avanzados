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
#include "../include/state_egg.h"
#include "../include/state_larva.h"
#include "../include/state_adult.h"
#include "../include/state_dead.h"
#include "../include/state_pupa.h"

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
Grid::Grid(const int& rows, const int& cols, std::vector<std::tuple<int,int,char>>& living_cells) {

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
      case 'H' : {
        matrix_[i][j].SetState(new State_egg);
      }
      break;
      case 'L' : {
        matrix_[i][j].SetState(new State_larva);
      }
      break;
      case 'P' : {
        matrix_[i][j].SetState(new State_pupa);
      }
      break;
      case 'A' : {
        matrix_[i][j].SetState(new State_adult);
      }
      break;
    }
  }
}

/**
 * @brief Destroy the Grid:: Grid object. Liberamos el objeto grid de memoria
 * 
 */
Grid::~Grid(){
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
const Cell& Grid::GetCell(int& row, int& col) const {
  return(matrix_[row][col]);
}

/**
 * @brief Operador para imprimir por pantalla
 * 
 * @param os parámetro std::ostream
 * @param grid objeto grid para imprimir
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, Grid& grid) {
  
  os << std::endl;
  for (int i{1}; i < grid.GetRows() - 1; i++) {
    for(int j{1}; j < grid.GetCols() - 1; j++) {
      os << grid.GetCell(i,j).GetState()->getState() << " ";
    }
    os << std::endl;
  }
  return(os);
}

/**
 * @brief Método encargado de hacer que las propias células se actualicen
 * 
 */
void Grid::NextGeneration() {
  /*
  * Hacemos un bucle que recorra todas las células, menos los bordes para que
  * cuenten las células vecinas que tienen
  */
  for (int i{1}; i < rows_ - 1; i++) {
    for(int j{1}; j < cols_ - 1; j++) {
      /// Cogemos la célula y hacemos que mire sus vecinos
      matrix_[i][j].NeighborsAlive(*this);
    }
  }
  /*
  * Hacemos un bucle que recorra todas las células, menos los bordes para que
  * cada célula actualice su estado
  */
  for (int i{1}; i < rows_ - 1; i++) {
    for(int j{1}; j < cols_ - 1; j++) {
      /// Cogemos la célula y hacemos que mire sus vecinos
      matrix_[i][j].UpdateState();
    }
  }
}


