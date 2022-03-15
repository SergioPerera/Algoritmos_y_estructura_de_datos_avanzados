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
* @file functions.h
*/

#ifndef _MAIN_LIFE_GAME_H
#define _MAIN_LIFE_GAME_H
#include <vector> /// std::vector 
#include <unistd.h> /// getopt
#include <regex> /// regular expressions
#include <iostream> /// std::cout << ...
/**
 * @brief Struct engargada de recoger los argumenos por línea de comandos.
 * Con esto podemos trabajar con los argumentos por línea de comandos y
 * permite una mejor modularidad en caso e meter nueos argumentos
 * 
 */
struct CommandLineArguments {

  int cols{0}; /// Número de columnas de la matriz visible
  int rows{0}; /// Número de filas de la matriz visible
  int alive_cells{0}; /// Número de células vivas
  int turns{0}; /// Número de iteraciones o turnos del juego

  /// Función encargada de recoger y comprobar los argumentos
  CommandLineArguments(int argc, char* argv[]); 
};
void manual();
std::vector<std::pair<int,int>> AliveCellsCoordinates (const CommandLineArguments& arguments);
#endif