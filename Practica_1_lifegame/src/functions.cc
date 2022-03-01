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
// #include <stdio.h> 
#include <unistd.h> /// getopt
#include <regex> /// regular expressions
#include <iostream>

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
}
