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
#include <stdio.h> 
#include <unistd.h>
#include <regex>
#include <iostream>

void manual() {
    std::cout << "Se usa de la siguiente maneraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
}
/**
 * @brief Construct a new Command Line Arguments:: Command Line Arguments object
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
  int c;
  while ( (c = getopt(argc, argv, "hd:at")) != -1) {
  
    switch (c) {
      case 'h': 
        manual();
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
        cols = std::stoi(m[0]);
        rows = std::stoi(m[2]);
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

//   if (optind < argc) {
//     for (; optind < argc; ++optind) {

//       other_arguments.push_back(argv[optind]);
//     }
//   }
}
