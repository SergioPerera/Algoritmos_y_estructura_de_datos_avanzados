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
  while ( (c = getopt(argc, argv, "h:dat")) != -1) {
  
    switch (c) {
      case 'h': 
        manual();
              break;
      case 'd': {

        /// Comprobamos que se hayan itroducido las dimensiones 
        /// de manera NúmeroxNúmero
        if (!regex_match (optarg, std::regex("\\d+x\\d+"))) {
          throw std::invalid_argument("Dimensión incorrecta");
        }

        /// Recogemos las dimensiones
        std::regex regexp("\\d+"); 
        std::smatch m;
        std::string argument_str{optarg};
        std::regex_search(argument_str, m, regexp);
        cols = std::stoi(m[0]);
        rows = std::stoi(m[1]);
        
        if (cols < 1 || rows < 2) {
          throw std::invalid_argument("Las dimensiones tienen que ser mayores que 0");
        }
        std::cout << "Cols: " << cols << " Rows: " << rows << std::endl;
      }
      break;
      case 'p':
        // if (!regex_match (optarg, std::regex("\\d+"))) {
        //   throw std::invalid_argument("Número de puerto inválido");
        // }
        // s.clear();
        // s = argv[5];
        // if (!regex_match (s, std::regex("\\d+"))) {
        //   throw std::invalid_argument("Número de puerto inválido");
        // }
        // conn_port =  std::stoi(argv[5]);
        // local_port = std::atoi(optarg);   

              break;
      case 'c':
        // ip = optarg;
        // /// Comprobación de errores
        // if (argc > 6 || argc < 6) {
        //   throw std::invalid_argument("Faltan o sobran argumentos");
        // }
        // /// Comprobamos si la ip es válida
        // if (!ip.empty()) {
        //   struct sockaddr_in sa;
        //   int result = inet_pton(AF_INET, ip.c_str(), &(sa.sin_addr));
        //   if (result != 1) {
        //     throw std::invalid_argument("Número de ip no válido");
        //   }
        // }
              break;
      case '?':
        throw std::invalid_argument("Argumento de línea de comandos desconocido");
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
