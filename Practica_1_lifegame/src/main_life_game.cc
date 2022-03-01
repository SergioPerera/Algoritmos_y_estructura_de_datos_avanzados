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

#include <iostream> /// std::cout << ...
#include <regex> /// regex_match, regex_search, ...

int main (int argc, char *argv[]){

  CommandLineArguments arguments(argc, argv);

  /// Recogemos las posiciones de las células vivas en un vector de posiciones
  std::vector<std::pair<int,int>> alive_cells_positions;
  /// Hacemos un for para solicitar ls coordenadas de cada célula viva
  for (int i{0}; i < arguments.alive_cells; i++) {

    std::string coordinates;
    std::cout << "Introduzca las coordenadas de la célula viva "<< i <<" [fil,col]: ";
    std::cin >> coordinates;

    if (!regex_match (coordinates, std::regex("([0-9]+),([0-9]+)"))) {
      std::cout << "  Coordenadas incorrectas, se escribe de la forma: fil,col\n"
                << "  La primera fila 0, idem para las columnas" << std::endl;
      i--;
    }
    else {

      /// Recogemos las coordenadas
      int alive_row {0};
      int alive_col{0};

      std::regex regexp("(\\d+),(\\d+)");
      /// smatch recoge las coincidencias dentro de los paréntesis 
      std::smatch m;
      std::regex_search(coordinates, m, regexp);
      alive_row = std::stoi(m[0]);
      alive_col = std::stoi(m[2]);

      /// Comprobamos que las coordenadas estén dentro de la matriz
      if (alive_col > arguments.cols || alive_row > arguments.rows){
        std::cout << "  Las coordenadas tienen que estar comprendidas entre:\n"
                  << "  Filas [0," << arguments.rows << "], usted puso: " << alive_row << "\n"
                  << "  Columnas [0," << arguments.cols << "], usted puso: " << alive_col << std::endl; 
        i--;
      }
      else{
        std::pair<int,int> alive_position{ alive_row, alive_col};
        alive_cells_positions.emplace_back(alive_position);
      }
    }
  }
                                                                        // for (long unsigned int i{0}; i < alive_cells_positions.size(); i ++){
                                                                        //   std::cout << i << " " << alive_cells_positions[i].first << " " << alive_cells_positions[i].second << std::endl;
                                                                        // }

  


  return(0);
}