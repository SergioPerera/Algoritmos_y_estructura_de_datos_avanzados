/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica: Árbol binario equilibrado
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 10/05/2022
* @file main_binary_tree.cc
*/

#include "../include/node.h"
#include "../include/AB.h"
#include "../include/ABE.h"
#include "../include/main_functions.h"
#include <regex>

int main (int argc, char* argv[]) {

  /**
   * Comprobamos que no han puesto parámetros, en caso afirmativo, 
   * se muestra un mensaje de error
   */

  if (argc > 1) { 
    std::cout << "Error: No se puede pasar parámetros" << std::endl;
    exit(EXIT_FAILURE);
  }

  while (true) {
    /// Imprimimos el menú
    PrintMenu();
  
    /// Solicitamos al usuario la opción del menú
    std::string option;
    std::cin >> option;
  
    /// Comprobamos que el usuario ha escogido una opción válida
    if(!regex_match(option, std::regex("[0-3]"))) {
      std::cout << RED << "Error: Opción no válida\n\n" << RESET <<  std::endl;  
    }
    else {
      break;
    }
  }


  return(0);
}

