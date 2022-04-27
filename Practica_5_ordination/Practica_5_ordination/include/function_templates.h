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
* @file function_templates.h
*/
bool traza = true;

#include <iostream>
template<typename T>
void Selection(std::vector<T>& v, int x) {
  T aux; ///< Valor a poner en la parte ordenada en cada iteracion
  for (int i{0}; i < (x - 1); ++i) {
    int min_pos{i};
    for (int j{i + 1}; j < x; ++j) {
      if (v[j] < v[min_pos]) {
        min_pos = j;
        aux = v[min_pos];
      }
    }

    v[min_pos] = v[i];
    v[i] = aux;

    if (traza) {
      /// mostramos el vtor por pantalla tras hacer la iteracion del algoritmo
      for (auto j: v) std::cout << j << " ";
      std::cout << std::endl;
    }
  }
}
