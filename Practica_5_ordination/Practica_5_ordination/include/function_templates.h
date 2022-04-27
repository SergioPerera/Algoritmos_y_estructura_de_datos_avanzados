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
  int min;
  for (int i = 0; i < x - 1; i++) {
    min = i;
    for (int j = i+1; j < x; j++) {
      if (v[j] < v[min]) {
        min = j;
      }
    }
    T x = v[min];
    v[min] = v[i];
    v[i] = x;
    
    if (traza) {
      /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
      std::cout << "Iteración(" << i+1 << "): ";
      for (auto j: v) std::cout << " " <<  j << " ";
      std::cout << std::endl;
    }
  }
}


template<typename T>
void FunctionQuickSort(std::vector<T>& v, T ini, T fin) {

  T i = ini;
  T f = fin;
  T p = v[(i+f)/2];

  while (i <= f) {
    while (v[i] < p) 
      i++;
    while (v[f] > p)
      f--;
    if (i <= f) {
      T aux = v[f];
      v[f] = v[i];
      v[i] = aux;
      i++;
      f--;
    }
  }
  if (traza) {
    /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
    std::cout << "Iteración(" << i+1 << "): ";
    for (auto j: v) std::cout << " " <<  j << " ";
    std::cout << std::endl;
  }
  if (ini < f) {
    QuickSort(v, ini, f);
  }
  if (i < fin) {
    QuickSort(v, i, fin);
  }

  
}

