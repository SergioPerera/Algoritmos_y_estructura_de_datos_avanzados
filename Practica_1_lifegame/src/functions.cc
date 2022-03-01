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
* @file functions.cc
* Referencia: https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/  ;
*/

#include "../include/functions.h"

/**
 * @brief Manual que indica como usar el programa
 * 
 */
void manual() {
    std::cout << "Para ejecutar hacer uso de ./lifegame -d NumxNum -a Num -t Num\n"
              << "Opciones:\n" 
              << "-d: Dimensión de la matriz. Tiene que ser mayor que 0 y su formato ser FilasxColumnas\n"
              << "-a: Alive cells (células vivas). Tiene que ser un número mayor que 0\n"
              << "-t: Turnos. Tiene que ser un número mayor que 0\n" 
              << "-h: Help. Muestra información del comando\n" << std::endl;
}

/**
 * @brief Construct a new Command Line Arguments:: Command Line Arguments object
 * dentro del getopt están las opciones hd:a:t:. Los 2 puntos indican que van a 
 * ir seguidos de un argumento
 * 
 * @param argc Contiene el número de comandos introducidos 
 * @param argv Contiene el contenido de los comandos
 * 
 *   Esta función va a tratar los comandos:
 *   -d que será para la dimensión de la matriz
 *   -a para indicar el número de células vivas
 *   -t para indicar el número de turnos
 *   -h para saber como usar el programa y cual es su función
 */
CommandLineArguments::CommandLineArguments(int argc, char* argv[]) {

  bool help = false; /// Flag que determina si han puesto -h
  int c; /// Salida de la función getopt
  while ( (c = getopt(argc, argv, "hd:a:t:")) != -1) {
  
    switch (c) {
      case 'h': 
        manual();
        help = true;
      break;
      case 'd': {
        /// Comprobamos que se hayan itroducido las dimensiones 
        /// de manera NúmeroxNúmero
        if (!regex_match (optarg, std::regex("([1-9]+)x([1-9]+)"))) {
          throw std::invalid_argument("Dimensión incorrecta");
        }

        /// Recogemos las dimensiones
        std::regex regexp("([1-9]+)x([1-9]+)");
        /// smatch recoge las coincidencias dentro de los paréntesis 
        std::smatch m;
        std::string argument_str{optarg};
        std::regex_search(argument_str, m, regexp);
        rows = std::stoi(m[0]);
        cols = std::stoi(m[2]);
      }
      break;
      case 'a': {
        /// Comprobamos que es un número mayor que 0
        if (!regex_match (optarg, std::regex("[1-9]+"))) {
          throw std::invalid_argument("Número de células vivas incorrecto");
        }
        alive_cells = std::stoi(optarg);
      }
      break;
      case 't': {
        /// Comprobamos que es un número mayor que 0
        if (!regex_match (optarg, std::regex("[1-9]+"))) {
          throw std::invalid_argument("Número de turnos incorrecto");
        }
        turns = std::stoi(optarg);
      }
      break;
      case '?':
        throw std::invalid_argument("Argumento de línea de comandos desconocido, pruebe ./lifegame -h");
      default:
        throw std::runtime_error("Error procesando la línea de comandos");
    }
  }

  if (argc > 7) {
    throw std::invalid_argument("Demasiados argumentos, pruebe ./lifegame -h");
  }
  else if( argc < 7 && help == false) {
    throw std::invalid_argument("Faltan argumentos, pruebe ./lifegame -h");
  }

  if (alive_cells > cols*rows) {
    throw std::invalid_argument("Número de células vivas mayor al permitido");
  }
  
}

std::vector<std::pair<int,int>> 
AliveCellsCoordinates (const CommandLineArguments& arguments) {
    /// Recogemos las posiciones de las células vivas en un vector de posiciones
  std::vector<std::pair<int,int>> alive_cells_positions;
  /// Hacemos un for para solicitar ls coordenadas de cada célula viva
  for (int i{0}; i < arguments.alive_cells; i++) {

    std::string coordinates;
    std::cout << "Introduzca las coordenadas de la célula viva "<< i <<" [fil,col]: ";
    std::cin >> coordinates;

    if (!regex_match (coordinates, std::regex("([1-9]+),([1-9]+)"))) {
      std::cout << "  Coordenadas incorrectas, se escribe de la forma: fil,col\n"
                << "  La primera fila es 1, idem para las columnas" << std::endl;
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
                  << "  Filas [1," << arguments.rows << "], usted puso: " << alive_row << "\n"
                  << "  Columnas [1," << arguments.cols << "], usted puso: " << alive_col << std::endl; 
        i--;
      }
      else{
        std::pair<int,int> alive_position{ alive_row, alive_col};
        alive_cells_positions.emplace_back(alive_position);
      }
    }
  }
                                                    //    for (long unsigned int i{0}; i < alive_cells_positions.size(); i ++){
                                                    //    std::cout << i << " " << alive_cells_positions[i].first << " " << alive_cells_positions[i].second << std::endl;
                                                    //  }

  return (alive_cells_positions);
}
