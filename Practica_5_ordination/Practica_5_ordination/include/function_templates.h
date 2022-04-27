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


int counter{0};
template<typename T>
void FunctionQuickSort(std::vector<T>& v, T ini, T fin) {
  counter++;
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
    std::cout << "Iteración(" << counter << "): ";
    for (auto j: v) std::cout << " " <<  j << " ";
    std::cout << std::endl;
  }
  if (ini < f) {
    FunctionQuickSort(v, ini, f);
  }
  if (i < fin) {
    FunctionQuickSort(v, i, fin);
  }
}


template<class T>
void Low(T i, std::vector<T>& v, T n) {
  while (2*i <= n) {
    T h1 = 2*i;
    T h2 = h1 + 1;
    T h;
    if (h1 == n) {
      h = h1;
    }
    else if (v[h1] > v[h2]) {
      h = h1;
    }
    else {
      h = h2;
    }
    if (v[h] <= v[i]) {
      break;
    }
    else {
      T aux = v[i];
      v[i] = v[h];
      v[h] = aux;
      i = h;
    }
  }
}

template<typename T>
void FunctionHeapSort(std::vector<T>& v, int x) {
  int iterator{0};
  x = x - 1;
  for (int i = x / 2; i >= 0; i--) {
    Low(i, v, x);
    if (traza) {
      iterator++;
      /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
      std::cout << "Iteración(" << iterator << "): ";
      for (auto j: v) std::cout << " " <<  j << " ";
      std::cout << std::endl;
    }
  }
  for (int i = x; i > 0; i--) {
    T aux = v[i];
    v[i] = v[0];
    v[0] = aux;
    Low(0, v, i-1);
    if (traza) {
      iterator++;
      /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
      std::cout << "Iteración(" << iterator << "): ";
      for (auto j: v) std::cout << " " <<  j << " ";
      std::cout << std::endl;
    }
  }
}