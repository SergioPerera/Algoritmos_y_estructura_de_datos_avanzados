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
#define EXTRA_SIZE  0
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
  rows_less = rows;
  cols_less = cols;
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
        matrix_[i - 1][j - 1].SetState(new State_dead);
      }
      break;
      case 'A' : {
        matrix_[i - 1][j - 1].SetState(new State_alive);
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
                                              int debugrow = row;
                                              int debugcol = col;
  /**
   *   Al sumar a la posición fuera de la matriz obtenemos una coordenada que al
   * hacer la divisón entera es la coordenada en el otro lado de la matriz 
   */
  if (row > rows_ - 1|| row <= 0 || col > cols_ - 1|| col <= 0) {
    row += rows_;
    col += cols_; 

    periodic_row = row%rows_;
    periodic_col = col%cols_;

    std::cout << "Estoy en la célula " << debugrow << " " << debugcol << " Y la periódica es: " << periodic_row << " " << periodic_col << std::endl;
  }

  return(matrix_[periodic_row][periodic_col]);
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
  for (int i{0}; i < GetRows() ; i++) {
    for(int j{0}; j < GetCols() ; j++) {
      os << GetCell(i,j).GetState()->getState() << " ";
    }
    os << std::endl;
  }
}



