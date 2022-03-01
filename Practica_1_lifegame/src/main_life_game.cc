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
* @file main_life_game.cc
*/
#include <iostream>
#include "../include/cell.h"
#include "../include/grid.h"
#include "../include/functions.h"

int main (int argc, char *argv[]){

  CommandLineArguments arguments(argc, argv);
  // int cols{0};
  // int rows{0};

  // /// Recogemos las dimensiones de la matriz
  // std::cout << "Introduzca el número de columnas: ";
  // std::cin >> cols;
  // std::cout << "Introduzca el número de filas: ";
  // std::cin >> rows;

  // /// Recogemos el número de células vivas inicialmente
  // int alive_cells{0};
  // std::cout << "Introduzca el númeo de células vivas inicialmente: ";
  // std::cin >> alive_cells;

  // /// Comprobamos que hayan puesto células
  // if (alive_cells < 1) {
  //   std::cout << "Tiene que haber al menos una célula viva" << std::endl;
  //   exit(EXIT_FAILURE);
  // }

  // /// Recogemos las posiciones de las células vivas
  // std::vector<std::pair<int,int>> alive_cells_positions;
  // for (int i{0}; i < alive_cells; i++) {

  //   int alive_col{0};
  //   int alive_row{0};

  //   std::cout << "Introduzca la fila de la célula viva: ";
  //   std::cin >> alive_row;

  //   std::cout << "Introduzca la fila de la columna viva: ";
  //   std::cin >> alive_col;

  //   if(alive_col > cols || alive_row > rows) {
  //     std::cout << "Ha introducido una posición no existente" << std::endl;
  //     i--;
  //   }
  //   else {
  //     std::pair<int,int> alive_position{ alive_row, alive_col};
  //     alive_cells_positions.emplace_back(alive_position);
  //   }
  // }

  // int iterations{0};
  // std::cout << "Introduzca el número de turnos: ";
  // std::cin >> iterations;
  // if (iterations < 1 ) {
  //   std::cout << "Tiene que haber al menos una iteración" << std::endl;
  //   exit(EXIT_FAILURE);
  // }

  return(0);
}