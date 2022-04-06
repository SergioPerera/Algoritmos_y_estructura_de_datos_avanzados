#include <iostream> 
#include "../include/sequence.h"
#include "../include/dispersion_function.h"
#include "../include/hashtable.h"

int main () {
  /**
   * @brief Solicitamos primero el tamaño de la tabla y luego comprobamos que el
   * número sea mayor que 0
   * 
   */
  std::cout << "Introduzca tamaño de la tabla: ";
  int table_size{0};
  std::cin >> table_size;

  /// Control de error
  while (table_size < 1) { 
    std::cout << "La tabla tiene que tener mínimo tamaño 1 " << std::endl;
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
    std::cout << "Se tiene que elegir una de las opciones disponibles" << std::endl;
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

  std::cout << "Seleccione el tipo de dispersión: \n"
            << "[A]bierta\n"
            << "[C]errada\n"
            << ">> ";
  char fd_type_selection;
  std::cin >> fd_type_selection;

  /// Comprobamos errores
  while (fd_type_selection != 'A' && fd_type_selection != 'C') {
    std::cout << "Tiene que seleccionar una de las opcciones disponibles" << std::endl;
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
      std::cout << "El bloque tiene que tener tamaño mínimo 1" << std::endl;
      std::cout << "Introduzca el tamaño del bloque: ";
      std::cin >> block_size;
    }

    /**
     * @brief Ahora solicitamos al usuario que función de exploración quiere
     * utilizar y luego comprobamos que haya elegido una de las elecciones 
     * disponibles
     */
    
    std::cout << "Introduzca la función de exploración a utilizar:\n"
              << "[L]ineal"
              << "[C]uadrática"
              << "[D]oble dispersión"
              << "[R]edispersión"
              << ">> ";
    char fe_selection;
    std::cin >> fe_selection;

    /// Manejo de errores
    while (fe_selection != 'M' && fe_selection != 'S' && fe_selection != 'P') {
      std::cout << "Se tiene que elegir una de las opciones disponibles" << std::endl;
      std::cout << "Introduzca la función de exploración a utilizar:\n"
              << "[L]ineal"
              << "[C]uadrática"
              << "[D]oble dispersión"
              << "[R]edispersión"
              << ">> ";
      std::cin >> fe_selection;
    }
  }

  return(0);
}