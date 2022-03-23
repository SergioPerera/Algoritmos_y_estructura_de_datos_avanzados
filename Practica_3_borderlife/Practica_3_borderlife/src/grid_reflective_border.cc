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
* @file grid_periodic_border.cc
*/

#include "../include/grid.h"
#include "../include/state.h"
#include "../include/state_dead.h"
#include "../include/state_alive.h"


#include <iostream>
#include <tuple>

#include <bits/stdc++.h> /// std::count
#define EXTRA_SIZE  2
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
GridWithReflectiveBorder::GridWithReflectiveBorder(const int& rows, const int& cols, std::vector<std::tuple<int,int,char>>& living_cells) {

  /// Hacemos esto por lo descrito anteriormente
  rows_ = rows + EXTRA_SIZE;
  cols_ = cols + EXTRA_SIZE;
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
GridWithReflectiveBorder::~GridWithReflectiveBorder(){
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
 * @brief Función que devuelve la célula en modo lectura, de manera que cuando
 * se acceda al borde, GetCell lo de vuele como si fuera periódico
 * 
 * @param row Filas
 * @param col Columnas
 * @return const Cell& 
 */
const Cell& GridWithReflectiveBorder::GetCell(int& row, int& col) const {
  int real_rows = rows_ - EXTRA_SIZE;
  int real_cols = cols_ - EXTRA_SIZE;
  int periodic_row{row};
  int periodic_col{col};
  /**
   * Al ser la matriz de n+2,m+2 (filas y columnas respectiamente) al estar en 
   * las posiciones 0,x | x,0 o m,x | x,m nos encontraríamos fuera de la matriz
   * por lo tanto hacemos row -1 y col -1 para que al sumarle las dimensiones 
   * "reales" de la matriz, estemos dentro de esta y al ser un borde reflectivo, 
   * calculamos el periódico del periódico y tenemos la célula relfejada
   */
  if (row > rows_ - EXTRA_SIZE|| row <= 0 || col > cols_ - EXTRA_SIZE|| col <= 0) {
                                                            std::cout << "Estoy fuera de la matri en la célula " << row << " " << col << std::endl;

    for (int i{0}; i < 1; i++) {
      row = row - 1 + real_rows;
      col = col - 1 + real_cols;
      periodic_row = (row%real_rows) + 1;
      periodic_col = (col%real_cols) + 1;
    }
  }
  return(matrix_[row][col]);
}

Cell& GridWithReflectiveBorder::GetCell(int& row, int& col) {
  return(matrix_[row][col]);
}

/**
 * @brief Operador para imprimir por pantalla
 * 
 * @param os parámetro std::ostream
 * @param grid objeto grid para imprimir
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, GridWithReflectiveBorder& grid) {

  grid.PrintMatrix(os);
  return(os); 
}

/**
 * @brief Método para poder imprimir por pantalla la matriz cuando se intenta 
 * imprimir mediante herencia, puesto que el operador << de la clase base tiene 
 * que llamar a algún método virtual para que este lo imprima
 * 
 * @param os 
 */
void GridWithReflectiveBorder::PrintMatrix (std::ostream& os) {
  os << std::endl;
  for (int i{0}; i < GetRows() - 0; i++) {
    for(int j{0}; j < GetCols() - 0; j++) {
      os << GetCell(i,j).GetState()->getState() << " ";
    }
    os << std::endl;
  }
}



