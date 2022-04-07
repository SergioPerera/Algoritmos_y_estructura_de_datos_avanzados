#include <iostream> 
#include "../include/sequence.h"
#include "../include/dispersion_function.h"
#include "../include/exploration_function.h"
#include "../include/hashtable.h"

#define RED     "\033[31m"      /// red
#define RESET   "\033[0m"       /// Reset 
#define GREEN   "\033[32m"       /// green


int main () {
  /**
   * @brief Solicitamos primero el tamaño de la tabla y luego comprobamos que el
   * número sea mayor que 0
   */
  std::cout << "Introduzca tamaño de la tabla: ";
  int table_size{0};
  std::cin >> table_size;

  /// Control de error
  while (table_size < 1) { 
    std::cout << RED <<"La tabla tiene que tener mínimo tamaño 1 " << RESET << std::endl;
    std::cout << "Introduzca tamaño de la tabla: ";
    std::cin >> table_size;
  }

  /**
   * @brief Preguntamos al usuario que función quiere usar y comprobamos que haya
   * elegido una de las opciones disponibles
   * 
   */
  std::cout << "\nSelecciona la función de dispersión: \n"
            << "[M]ódulo\n"
            << "[S]uma\n"
            << "[P]seudoaleatoria\n" 
            << ">> ";
  char fd_selection;
  std::cin >> fd_selection;

  while (fd_selection != 'M' && fd_selection != 'S' && fd_selection != 'P') {
    std::cout << RED << "Se tiene que elegir una de las opciones disponibles" << RESET<< std::endl;
    std::cout << "Selecciona la función de dispersión: \n"
              << "[M]ódulo\n"
              << "[S]uma\n"
              << "[P]seudoaleatoria\n" 
              << ">> ";
    std::cin >> fd_selection;
  }


  /**
   * @brief Ahora creamos el puntero de la función de dispersión y luego le 
   * asignamos el objeto en función de la elección del usuario
   * 
   */
  DispersionFunction<ulong>* fd;
  switch(fd_selection) {
    case 'M' : 
      fd = new FdModule<ulong>(table_size);
      break;
    case 'S':
      fd = new FdBasedOnSum<ulong>(table_size);
      break;
    case 'P':
      fd = new FdPseudoRamdom<ulong>(table_size);
      break;
  }

  /**
   * @brief Ahora solicitamos al usuario que elija una función de dispersión, si
   * abierta o cerrada
   */

  std::cout << "\nSeleccione el tipo de dispersión: \n"
            << "[A]bierta\n"
            << "[C]errada\n"
            << ">> ";
  char fd_type_selection;
  std::cin >> fd_type_selection;

  /// Comprobamos errores
  while (fd_type_selection != 'A' && fd_type_selection != 'C') {
    std::cout << RED <<  "Tiene que seleccionar una de las opcciones disponibles" << RESET << std::endl;
    std::cout << "Seleccione el tipo de dispersión: \n"
          << "[A]bierta\n"
          << "[C]errada\n"
          << ">> ";
    std::cin >> fd_type_selection;
  }
  int block_size {0};
  ExplorationFunction<ulong>* fe = nullptr;
  /**
   * @brief En el caso de que estemos en dispersión cerrada, solicitaremos al 
   * usuario que selecciones la función de exploración a usar junto con la función 
   * de dispersión seleccionada anteriormente
   */
  if (fd_type_selection == 'C') {
    /**
     * @brief Solicitamos al usuario el tamaño de bloque y luego hacemos una 
     * comprobación para saber si es mayor que 0
     */
    std::cout << "Introduzca el tamaño del bloque: ";
    std::cin >> block_size;

    while (block_size < 1) { 
      std::cout << RED << "El bloque tiene que tener tamaño mínimo 1" << RESET<< std::endl;
      std::cout << "Introduzca el tamaño del bloque: ";
      std::cin >> block_size;
    }

    /**
     * @brief Ahora solicitamos al usuario que función de exploración quiere
     * utilizar y luego comprobamos que haya elegido una de las elecciones 
     * disponibles
     */
    
    std::cout << "\nIntroduzca la función de exploración a utilizar:\n"
              << "[L]ineal\n"
              << "[C]uadrática\n"
              << "[D]oble dispersión\n"
              << "[R]edispersión\n"
              << ">> ";
    char fe_selection;
    std::cin >> fe_selection;

    /// Manejo de errores
    while (fe_selection != 'L' && 
           fe_selection != 'C' && 
           fe_selection != 'D' && 
           fe_selection != 'R') {

      std::cout << RED << "\nSe tiene que elegir una de las opciones disponibles" << RESET << std::endl;
      std::cout << "Introduzca la función de exploración a utilizar:\n"
              << "[L]ineal\n"
              << "[C]uadrática\n"
              << "[D]oble dispersión\n"
              << "[R]edispersión\n"
              << ">> ";
      std::cin >> fe_selection;
    }
    switch(fe_selection) {
      case 'L':
        fe = new FeLineal<ulong>();
      break;
      case 'C':
        fe = new FeQuadratic<ulong>();
      break;
      case 'D':
        fe = new FeDoubleDispersion<ulong>();
      break;
      case 'R':
        fe = new FeRedispersion<ulong>();
      break;
    }
  }

 /**
  * @brief Ahora creamos el tablero y ya el usuario podrá interactual con él
  * 
  * @return HashTable<ulong> 
  */
  HashTable<ulong> table(table_size, fd, block_size, fe);
  char input;

  while (input != 'q') {
    /**
     * @brief Hacemos que el usuario elija una opción y en caso de que no sea
     * una opción válida manejamos el error
     */
    std::cout << "\nSeleccione la opción a realizar\n"
              << "[a]ñadir\n"
              << "[b]uscar\n"
              << "[q]uitar\n"
              << ">> ";
    std::cin >> input;

    if (input == 'q') {break;};
    /// Manejo de errores
    while (input != 'a' && input != 'b' && input != 'q') { 
      std::cout << RED << "Se tiene que elegir una de las opciones disponibles" << RESET<< std::endl;
      std::cout << "\nSeleccione la opción a realizar\n"
        << "[a]ñadir\n"
        << "[b]uscar\n"
        << "[q]uitar\n"
        << ">> ";
      std::cin >> input;
    }

    std::cout << "\nIntroduzca el valor a insertar o buscar: ";
    ulong in_value{0};
    std::cin >> in_value;

    switch(input) {
      case 'a': {
        bool inserted;
        inserted = table.Insert(in_value);
        if (inserted == true) {std::cout << GREEN << "Valor insertado" << RESET << std::endl;}
        else {std::cout << RED << "El valor no pudo ser insertado" << RESET << std::endl;}
      }
      break;
      case 'b': {
        bool finded;
        finded = table.Search(in_value);
        if (finded) {std::cout << GREEN << "Valor encontrado" << RESET << std::endl;}
        else {std::cout << RED << "El valor no pudo ser encontrado" << RESET << std::endl;}
      }
      break;
    }
  }

  return(0);
}