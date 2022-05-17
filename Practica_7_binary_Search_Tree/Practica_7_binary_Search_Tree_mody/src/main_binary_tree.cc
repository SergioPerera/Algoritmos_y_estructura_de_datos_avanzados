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
#include "../include/ABB.h"
#include "../include/main_functions.h"
#include "../include/dummy.h"
#include <regex>
#define KEY Dummy
unsigned Dummy::counter;

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
  AB<Dummy>* arbol = new ABE<Dummy>();                                                                                                                                                                                                                                                   
  AB<Dummy>* arbol1 = new ABB<Dummy>();                                                                                                                                                                                                                                                  
  for(int i=0; i < 100; i++) {                                                                                                                                                                                                                                                           
    Dummy k (rand()%1000);                                                                                                                                                                                                                                                               
    arbol->Insert(k);                                                                                                                                                                                                                                                                  
    arbol1->Insert(k);                                                                                                                                                                                                                                                                 
  }                                                                                                                                                                                                                                                                                      
  for(int i= 0; i < 10; i++) {                                                                                                                                                                                                                                                           
    Dummy::counter = 0;                                                                                                                                                                                                                                                                 
    Dummy k (rand()%1000);                                                                                                                                                                                                                                                               
    arbol->Search(k);                                                                                                                                                                                                                                                                    
    std::cout << "Se te esta buscando la clave " << k << std::endl;                                                                                                                                                                                                                      
    std::cout << "Equilibrado " << Dummy::counter << " " << std::endl;                                                                                                                                                                                                                  
    Dummy::counter = 0;                                                                                                                                                                                                                                                                 
    arbol1->Search(k);                                                                                                                                                                                                                                                                   
    std::cout << "Binario de Busqueda " << Dummy::counter << " " << std::endl << std::endl;                                                                                                                                                                                             
  }
  std::cout << arbol << std::endl;
  std::cout << arbol1 << std::endl;

//   /// Creammos el arbol binario y luego pasa a ser un árbol binario equilibrado
//   AB<KEY>* binary_tree{NULL};
//   bool ABB_selected = false;
//   while (true) {
//     std::cout << "Seleccione una opción: "
//               << "\n[0] Salir"
//               << "\n[1] Árbol binario equilibrado"
//               << "\n[2] Árbol binario de búsqueda"
//               << GREEN << "\n>>>>> ";
//     int option{0};
//     std::cin >> option;
//     std::cout << RESET << std::endl;
//     if (std::regex_match(std::to_string(option), std::regex("[0-2]"))) {
//       switch (option) {
//         case 0:
//           exit(EXIT_SUCCESS);
//           break;
//         case 1:
//           binary_tree = new ABE<KEY>();
//           break;
//         case 2:
//           binary_tree = new ABB<KEY>();
//           ABB_selected = true;
//           break;
//         default:
//           break;
//       }
//       break; /// Break encargado de parar el bucle
//     } else {
//       std::cout << RED << "Error: Opción incorrecta" << RESET << std::endl;
//       continue;
//     }
//   }

//   std::string option;
//   while (true) {
//     /// Imprimimos el menú
//     PrintMenu(ABB_selected);
//     /// Solicitamos al usuario la opción del menú
//     std::cin >> option;
//     std::cout << RESET;
//     /// Comprobamos que el usuario ha escogido una opción válida
//     if ((ABB_selected == true) && (!regex_match(option, std::regex("[0-4]")))){
//       std::cout << RED << "Error: Opción no válida1\n\n" << RESET << std::endl;  
//     }
//     else if((ABB_selected == false) && (!regex_match(option, std::regex("[0-3]")))) {
//       std::cout << RED << "Error: Opción no válida2\n\n" << RESET << std::endl;  
//     }
//     else {
//       /**
//        * @brief Construct a new switch object para ejecutar la opción
//        * 
//        */
//       switch (std::stoi(option)) {
//         case 0:
//           exit(EXIT_SUCCESS);
//           break;
//         case 1: {
//           std::string key;
//           while (true) {
//             std::cout << "Introduzca la clave a insertar: ";
//             std::cin >> key;
//             if (!regex_match(key, std::regex("^[1-9]*[0-9]$"))) {
//               std::cout << RED << "Error: Clave no válida\n\n" << RESET 
//               << std::endl;                                                            /// Posible fallo si se cambia la key por algo que no sean números enteros
//             }
//             else { break; }
//           }
//           Dummy d{std::stoi(key)};
//           if (binary_tree->Insert(d)) {
//             std::cout << GREEN << "Clave insertada correctamente\n" << RESET 
//                       << std::endl;
//           }
//           else {
//             std::cout << RED << "Error: Clave ya existente\n" << RESET << std::endl;
//           }
//           std::cout << binary_tree << std::endl;
//           break;
//         }
//         case 2: {
//           std::string key;
//           while (true) {
//             std::cout << "Introduzca la clave a buscar: ";
//             std::cin >> key;
//             if (!regex_match(key, std::regex("^[1-9]*[0-9]$"))) {
//               std::cout << RED << "Error: Clave no válida\n\n" << RESET 
//                         << std::endl;                                                 /// Posible fallo si se cambia la key por algo que no sean números enteros
//             }
//             else { break; }
//           }
//           if (binary_tree->Search(std::stoi(key))) {
//             std::cout << GREEN << "La clave " << key 
//                       << " se encuentra en el árbol"
//                       << RESET << std::endl;
//           }
//           else {
//             std::cout << RED << "La clave " << key 
//                       << " no se encuentra en el árbol"
//                       << RESET << std::endl;
//           }
//           break;
//         }
//         case 3:
//           binary_tree->Inorden();
//           break;
//         case 4: {
//           std::string key;
//           while (true) {
//             std::cout << "Introduzca la clave a eliminar: ";
//             std::cin >> key;
//             if (!regex_match(key, std::regex("^[1-9]*[0-9]$"))) {
//               std::cout << RED << "Error: Clave no válida\n\n" << RESET 
//                         << std::endl;                                                 /// Posible fallo si se cambia la key por algo que no sean números enteros
//             }
//             else { break; }
//           }
//           if (binary_tree->Delete(std::stoi(key)) ) {
//             std::cout << GREEN << "La clave " << key 
//                                << " ha sido eliminada árbol"
//                                << RESET << std::endl;
//           }
//           else {
//             std::cout << RED << "Error: Clave no encontrada\n" << RESET 
//                       << std::endl;
//           }
//           std::cout << binary_tree << std::endl;
//           break;
//         }
//         default:
//           std::cout << RED << "Error_default: Opción no válida\n\n" 
//                     << RESET << std::endl;
//           break;
//       }
//     }
//   }



  return(0);
}

