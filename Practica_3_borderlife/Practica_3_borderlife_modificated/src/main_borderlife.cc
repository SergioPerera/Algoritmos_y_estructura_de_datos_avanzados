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
  std::vector<std::tuple<int,int,char>> alive_cells_positions;
  alive_cells_positions = AliveCellsCoordinates(arguments);

  /// Creamos la matriz de células 
  Grid* grid; 

  if(arguments.normal == true) {
    std::cout << "Matriz normal\n" << std::endl;
    grid = new GridWithOpenBorder{arguments.rows, arguments.cols, alive_cells_positions};
  };
  if(arguments.periodic == true) {
    std::cout << "Matriz periódica\n" << std::endl;
    grid = new GridWithPeriodicBorder{arguments.rows, arguments.cols, alive_cells_positions};
  };
  if(arguments.mirror == true) {
    std::cout << "Matriz reflectiva\n" << std::endl;
    grid = new GridWithReflectiveBorder{arguments.rows, arguments.cols, alive_cells_positions};
  };


  std::cout << "Turno: 0" << *grid << std::endl;

  /// Haremos las turn iteraciones 
  for(int k{0}; k < arguments.turns; k++) {

    grid->NextGeneration();

    std::cout << "Turno: "<< k + 1 << *grid << std::endl;

  }

  return(0);
}