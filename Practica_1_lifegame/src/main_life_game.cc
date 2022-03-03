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

#include "../include/cell.h"
#include "../include/grid.h"
#include "../include/functions.h"

int main (int argc, char *argv[]){

  CommandLineArguments arguments(argc, argv);

  /// Recogemos las posiciones de las células vivas en un vector de posiciones
  std::vector<std::pair<int,int>> alive_cells_positions;
  alive_cells_positions = AliveCellsCoordinates(arguments);

  /// Creamos la matriz de células 
  Grid grid{arguments.rows, arguments.cols, alive_cells_positions};

  std::cout << grid << std::endl;

  /// Haremos las turn iteraciones 
  for(int k{0}; k < arguments.turns; k++) {
    // /*
    // * Hacemos un bucle que recorra todas las células, menos los bordes para que
    // * cuenten las células vecinas que tienen
    // */
    // for (int i{1}; i < grid.GetRows() - 1; i++) {
    //   for(int j{1}; j < grid.GetCols() - 1; j++) {
    //     /// Cogemos la célula y hacemos que mire sus vecinos
    //     std::cout << i << "----------------------------" << j << std::endl;
    //     Cell cell_cpy = grid.GetCell(i,j);
    //     cell_cpy.NeighborsAlive(grid);
    //   }
    // }
  
   /*
    * Hacemos un bucle que recorra todas las células, menos los bordes para que
    * cada célula actualice su estado
    */
  }

  return(0);
}