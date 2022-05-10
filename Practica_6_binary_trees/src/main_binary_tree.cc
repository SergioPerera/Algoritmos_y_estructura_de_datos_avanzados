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
#define KEY int

int main (int argc, char* argv[]) {

  /**
   * Comprobamos que no han puesto parámetros, en caso afirmativo, 
   * se muestra un mensaje de error
   */

  if (argc > 1) { 
    std::cout << "Error: No se puede pasar parámetros" << std::endl;
    exit(EXIT_FAILURE);
  }

  /// Creammos el arbol binario y luego pasa a ser un árbol binario equilibrado
  AB<KEY>* binary_tree{NULL};  //// Posible fallo al usar NULL en vez de nullptr
  binary_tree = new ABE<KEY>;

  std::string option;
  while (true) {
    /// Imprimimos el menú
    PrintMenu();
  
    /// Solicitamos al usuario la opción del menú
    std::cin >> option;
  
    /// Comprobamos que el usuario ha escogido una opción válida
    if(!regex_match(option, std::regex("[0-3]"))) {
      std::cout << RED << "Error: Opción no válida\n\n" << RESET <<  std::endl;  
    }
    else {
      switch (std::stoi(option)) {
        case 0:
          exit(EXIT_SUCCESS);
          break;
        case 1: {
          std::string key;
          while (true) {
            std::cout << "Introduzca la clave a insertar: ";
            std::cin >> key;
            if (!regex_match(key, std::regex("^[1-9]+[0-9]$"))) {
              std::cout << RED << "Error: Clave no válida\n\n" << RESET << std::endl;  /// Posible fallo si se cambia la key por algo que no sean números enteros
            }
            else { break; }
          }
          binary_tree->Insert(std::stoi(key));
          break;
        }
        case 2: {
          std::string key;
          while (true) {
            std::cout << "Introduzca la clave a buscar: ";
            std::cin >> key;
            if (!regex_match(key, std::regex("^[1-9]+[0-9]$"))) {
              std::cout << RED << "Error: Clave no válida\n\n" << RESET << std::endl;  /// Posible fallo si se cambia la key por algo que no sean números enteros
            }
            else { break; }
          }
          binary_tree->Search(std::stoi(key));
          break;
        }
        case 3:
          binary_tree->Inorden();
          break;
        default:
          std::cout << RED << "Error: Opción no válida\n\n" << RESET << std::endl;
          break;
      }
    }
  }



  return(0);
}

