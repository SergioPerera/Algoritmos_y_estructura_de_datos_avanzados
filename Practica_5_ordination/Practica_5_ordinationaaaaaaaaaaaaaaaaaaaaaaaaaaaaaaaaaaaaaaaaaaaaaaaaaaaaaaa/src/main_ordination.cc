/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica sort algorithms
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 26/04/2022
* @file main_ordination.cc
*/

#include "../include/sequence.h"
#include <iostream>
#include "../include/clase.h"
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
    std::string num_elements{0};
    std::cout << "Introduzca el número de elementos: ";
    std::cin >> num_elements;
  
    /// Comprobamos que se haya puesto bien el número de elementos
    if (!regex_match(num_elements, std::regex("^[1-9]+$"))) {
      std::cout << RED << "El número de elementos debe ser un número mayor que 0\n" 
                << RESET << std::endl;
    }
    else{ sequence_length = std::stoi(num_elements); break; }
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
    for (int i{0}; i < sequence_length; i++) {
      std::cout << "Introduzca los elementos de la secuencia: ";
      std::string in_seq;
      std::cin >> in_seq;
      int integer_seq = std::stoi(in_seq);
      if (!regex_match(in_seq, std::regex("^[1-9]+[0-9]+$"))){
        std::cout << RED << "Error, el elemento debe ser un número\n" 
                  << RESET << std::endl;
        i--;
      }
      else if (integer_seq < 1000 || integer_seq > 9999) {
        std::cout << RED << "Error, el elemento debe estar entre 1000 y 9999\n" 
                  << RESET << std::endl;
        i--;
      }
      else {
        sequence.emplace_back(std::stoi(in_seq));
      }
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
  std::cout << "\nVector original: " << seq << "\n" << std::endl;
  seq.Sort();

  while(true) {
    std::cout << "_______________________________________" << RESET << "\n" <<std::endl;
    /// Solicitamos al usuario el algoritmo
    std::cout << "Seleccione el algoritmo a ejecutar: \n"
              << "[S]eleccción \n"
              << "[Q]uickSort \n"
              << "[I]ncrementos Decrecientes \n"
              << "[H]eapSort \n"
              << "[R]adixSort \n"
              << "[q]uit \n"
              << ">> ";
  
    std::cin >> algorithm;
    if (algorithm[0] == 'q') {break;}
  
    /// Comprobamos que se haya puesto bien el algoritmo
    if (!regex_match(algorithm, std::regex("^[SQIHR]$"))) {
  
      std::cout << RED << "Error, algoritmo no válido\n" << RESET 
                << std::endl;
    }else{
      seq.SetSort(algorithm);
      seq.Sort();

    }
  }

}