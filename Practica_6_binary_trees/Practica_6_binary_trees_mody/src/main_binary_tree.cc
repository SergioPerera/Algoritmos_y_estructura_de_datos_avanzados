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
#include "../include/clase_mod.h"
#include <regex>
#define KEY int

/**
 * @brief Función main que se encarga de ejecutra la estructura base del 
 * programa
 * 
 * @param argc Número de argumentos
 * @param argv Vector de argumentos
 * @return int 
 */
int main (int argc, char* argv[]) {

  /**
   * Comprobamos que no han puesto parámetros, en caso afirmativo, 
   * se muestra un mensaje de error
   */

  if (argc > 1) { 
    std::cout << RED <<  "Error: No se puede pasar parámetros" << RESET 
              << std::endl;
    exit(EXIT_FAILURE);
  }

  /// Creammos el arbol binario y luego pasa a ser un árbol binario equilibrado
  AB<KEY>* binary_tree{NULL};                                                        /// Posible fallo al usar NULL en vez de nullptr
  binary_tree = new ABE<KEY>;

  std::string option;
  while (true) {
    /// Imprimimos el menú
    PrintMenu();
    /// Solicitamos al usuario la opción del menú
    std::cin >> option;
    std::cout << RESET;
    /// Comprobamos que el usuario ha escogido una opción válida
    if(!regex_match(option, std::regex("[0-3]"))) {
      std::cout << RED << "Error: Opción no válida\n\n" << RESET << std::endl;  
    }
    else {
      /**
       * @brief Construct a new switch object para ejecutar la opción
       * 
       */
      switch (std::stoi(option)) {
        case 0:
          exit(EXIT_SUCCESS);
          break;
        case 1: {
          std::string key;
          while (true) {
            std::cout << "Introduzca la clave a insertar: ";
            std::cin >> key;
            if (!regex_match(key, std::regex("^[1-9]*[0-9]$"))) {
              std::cout << RED << "Error: Clave no válida\n\n" << RESET 
              << std::endl;                                                            /// Posible fallo si se cambia la key por algo que no sean números enteros
            }
            else { break; }
          }
          if (binary_tree->Insert(std::stoi(key))) {
            std::cout << GREEN << "Clave insertada correctamente\n" << RESET 
                      << std::endl;
          }
          else {
            std::cout << RED << "Error: Clave ya existente\n" << RESET << std::endl;
          }
          std::cout << binary_tree << std::endl;
          break;
        }
        case 2: {
          std::string key;
          while (true) {
            std::cout << "Introduzca la clave a buscar: ";
            std::cin >> key;
            if (!regex_match(key, std::regex("^[1-9]*[0-9]$"))) {
              std::cout << RED << "Error: Clave no válida\n\n" << RESET 
                        << std::endl;                                                 /// Posible fallo si se cambia la key por algo que no sean números enteros
            }
            else { break; }
          }
          if (binary_tree->Search(std::stoi(key))) {
            std::cout << GREEN << "La clave " << key 
                      << " se encuentra en el árbol"
                      << RESET << std::endl;
          }
          else {
            std::cout << RED << "La clave " << key 
                      << " no se encuentra en el árbol"
                      << RESET << std::endl;
          }
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

  AB<Mod>* mod_tree{NULL};                                                        /// Posible fallo al usar NULL en vez de nullptr
  mod_tree = new ABE<Mod>;
    Mod d{3, ""};
    mod_tree->Insert(d);

    if (mod_tree->Search(d)) {
      std::cout << mod_tree << "\n\n";
      mod_tree->operator[](d).name = "X";
      std::cout << mod_tree << "\n";
    }

  return(0);
}

