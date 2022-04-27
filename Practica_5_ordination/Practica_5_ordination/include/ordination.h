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
* @file ordination.h
*/

#ifndef _ORDINATION_H_
#define _ORDINATION_H_
#define RED     "\033[31m"      /// red
#define RESET   "\033[0m"       /// Reset
#define BLUE   "\033[34m"      /// blue
#define WHITE_BACKGROUND   "\033[47m"      /// green

#include <vector>
#include "../include/function_templates.h"

  //############################################################################
  //########################### Clase base #####################################
  //############################################################################
template<class Key>
class Ordination {
  public:
  Ordination() {};
  virtual void Sort(std::vector<Key> v, int seq_length)=0;
};


  //############################################################################
  //######################### Clases hijas #####################################
  //############################################################################ç

template<class Key>
class SelectionSort : public Ordination<Key> {

 public:
  void Sort(std::vector<Key> v, int seq_length) override {
    Selection<Key>(v, seq_length);

    /// Imprimimos el vector ordenado
    std::cout << BLUE << "\nVector copia ordenado por selección: ";
    for (ulong i{0}; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }

    std::cout << RESET << "\n" << std::endl;
  }
};

template<class Key>
class QuickSort : public Ordination<Key> {

 public:
  QuickSort(Key ini, Key fin) { ini_ = ini; fin_ = fin; };
  void Sort(std::vector<Key> v, int seq_length) override { 
    FunctionQuickSort(v, ini_, fin_);

    /// Imprimimos el vector ordenado
    std::cout << BLUE << "\nVector copia ordenado por QuickSort: ";
    for (ulong i{0}; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }

    std::cout << RESET << "\n" << std::endl;
  }
 private:
  Key ini_;
  Key fin_;
};

template<class Key>
class IncrementDecrement : public Ordination<Key> {

 public:
  void Sort(std::vector<Key> v, int seq_length) override {}
};

template<class Key>
class HeapSort : public Ordination<Key> {

 public:
  void Sort(std::vector<Key> v, int seq_length) override {
    FunctionHeapSort(v, seq_length);
  
    /// Imprimimos el vector ordenado
    std::cout << BLUE << "\nVector copia ordenado por HeapSort: ";
    for (ulong i{0}; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }
    std::cout << RESET << "\n" << std::endl;
  }
};

template<class Key>
class RadixSort : public Ordination<Key> {

 public:
  void Sort(std::vector<Key> v, int seq_length) override {
    FunctionRadixSort(v, seq_length);

        /// Imprimimos el vector ordenado
    std::cout << BLUE << "\nVector copia ordenado por RadixSort: ";
    for (ulong i{0}; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }
    std::cout << RESET << "\n" << std::endl;
  }
};

#endif // _ORDINATION_H_