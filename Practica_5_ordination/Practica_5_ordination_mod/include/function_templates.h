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
* @file function_templates.h
*/
bool traza = true;

#include <iostream>
#include <queue>

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
      i = i + 1;
    while (v[f] > p)
      f = f - 1;
    if (i <= f) {
      T aux = v[f];
      v[f] = v[i];
      v[i] = aux;
      i = i + 1;
      f = f - 1;
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
void FunctionHeapSort(std::vector<T>& v, T x) {
  int iterator{0};
  T aux1 = 0;
  x = x - 1;
  for (int i = x / 2; i >= 0; i--) {
    T aux2 = i;
    T aux3 = x;
    Low(aux2, v, aux3);
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
    T aux4 = i - 1;
    Low(aux1, v, aux4);
    if (traza) {
      iterator++;
      /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
      std::cout << "Iteración(" << iterator << "): ";
      for (auto j: v) std::cout << " " <<  j << " ";
      std::cout << std::endl;
    }
  }
}


template<class T>
int NumCount(T integer) {
  int counter = 0;
  while (integer > 0) {
    integer /= 10;
    counter++;
  }
  return counter;
}

template<typename T>
void FunctionRadixSort(std::vector<T>& v, int x) {
  int iterator{0};
  int max_size = 0;
  for (int i{0}; i < x; i++) {
    if(NumCount(v[i]) > max_size) {
      max_size = NumCount(v[i]);
    }
  }
  std::queue<T> auxiliar[10];
  for (int i{1}; i <= max_size; i++) {
    for (int j{0}; j < x; j++) {
      int copia = v[j];
      int digito = 0;
      for (int k{0}; k < i; k++) {
        digito = copia % 10;
        copia = copia / 10;
      }
      auxiliar[digito].push(v[j]);
    }
    int contador = 0;
    T valor;
    for (int k{0}; k < 10; k++) {
      while (!auxiliar[k].empty()) {
        valor = auxiliar[k].front();
        v[contador] = valor;
        auxiliar[k].pop();
        contador++;
      }
    }

    if (traza) {
      iterator++;
      /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
      std::cout << "Iteración(" << iterator << "): ";
      for (auto j: v) std::cout << " " <<  j << " ";
      std::cout << std::endl;
    }
  }
}


int iterator{0};
template<class T>
void Deltasort(int delta, std::vector<T>& v, int x) {
  for (int i = delta; i < x; i++) {
    T x = v[i];
    T j = i;
    while ((j >= delta) && (x < v[j - delta])) {
      v[j] = v[j - delta];
      j = j - delta;
    }
    v[j] = x;
  }
  if (traza) {
    iterator++;
    /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
    std::cout << "Iteración(" << iterator << "): ";
    for (auto j: v) std::cout << " " <<  j << " ";
    std::cout << "\n" << std::endl;
  }
}

template<class T>
void FunctionIncrementDecrement(std::vector<T>& v, int x, double alfa) {
  int delta = x * alfa;
  while (delta > 0) {
    std::cout << "Delta = " << delta << std::endl;
    Deltasort(delta, v, x);
    delta = delta * alfa;
  }
}