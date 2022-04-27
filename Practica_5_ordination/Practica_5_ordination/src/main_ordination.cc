/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica hashtable
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 26/04/2022
* @file main_ordination.cc
*/

#include "../include/sequence.h"
#include <iostream>
#define RED     "\033[31m"      /// red
#define RESET   "\033[0m"       /// Reset
#define KEY int

int main() {

  int sequence_length{0};
  std::vector<KEY> sequence;

  //############################################################################
  //##################### Solicitud de parámetros ##############################
  //############################################################################

  /*
   *  Hacemos un bucle para que el usuario introduzca el algoritmo y en caso de 
   * introducir un algoritmo incorrecto volver a solicitar la opción.
   */
  std::string algorithm;
  while (true) {
    /// Solicitamos al usuario el algoritmo
    std::cout << "Seleccione el algoritmo a ejecutar: \n"
              << "[S]eleccción \n"
              << "[Q]uickSort \n"
              << "[I]ncrementos Decrecientes \n"
              << "[H]eapSort \n"
              << "[R]adixSort \n"
              << ">> ";
  
    std::cin >> algorithm;
  
    /// Comprobamos que se haya puesto bien el algoritmo
    if (!regex_match(algorithm, std::regex("^[SQIHR]$"))) {
  
      std::cout << RED << "Error, algoritmo no válido\n" << RESET 
                << std::endl;
    }
    else{ break; }
  }

  /**
   *  Solicitamos al usuario el número de elementos de la secuencia y en caso de 
   * ser erróneo se vuelve a solicitar
   */
  while (true) {
    /// Solicitamos al usuario el número de elementos
    int num_elements{0};
    std::cout << "Introduzca el número de elementos: ";
    std::cin >> num_elements;
  
    /// Comprobamos que se haya puesto bien el número de elementos
    if (num_elements < 1) {
      std::cout << RED << "El número de elementos debe ser mayor que 0\n" 
                << RESET << std::endl;
    }
    else{ sequence_length = num_elements; break; }
  }

  /**
   *  Solicitamos al usuario el método de llenado del vector y en caso erróneo
   * volvemos a solicitar una opción
   */
  std::string fill_vector_option;
  while (true) {
    std::cout << "¿Desea rellenar el vector manualmente o automáticamente? \n"
              << "[M]anual \n"
              << "[A]utomatico \n"
              << ">> ";
    std::cin >> fill_vector_option;

    if (!regex_match(fill_vector_option, std::regex("^[MA]$"))) {
      std::cout << RED << "Error, opción no válida\n" << RESET << std::endl;
    }
    else{ break; }
  }

  if (fill_vector_option == "M") {
    /**
     *  Solicitamos al usuario los elementos de la secuencia
     */
    std::cout << "Introduzca los elementos de la secuencia: ";
    for (int i{0}; i < sequence_length; i++) {
      int in_seq{0};
      std::cin >> in_seq;
      sequence.emplace_back(in_seq);
    }
  }
  else if (fill_vector_option == "A") {
    /**
     *  Rellenamos el vector con números aleatorios entre 1000 y 9999
     */
    srand(time(NULL));
    for (int i{0}; i < sequence_length; i++) {
      sequence.emplace_back(rand() %(9999-1000 + 1) + 1000);
    }
  }



  //############################################################################
  //####################### Creación de objeto #################################
  //############################################################################

  /// Creamos el objeto
  Sequence<KEY> seq{sequence_length, sequence, algorithm};
  std::cout << seq << std::endl;
  seq.Sort();
  std::cout << seq << std::endl;

}