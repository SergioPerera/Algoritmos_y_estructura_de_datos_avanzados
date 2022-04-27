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
    Selection<Key>(v, v.size());

    /// Imprimimos el vector ordenado
    std::cout << "Vector copia ordenado: ";
    for (ulong i{0}; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;
  }
};

template<class Key>
class QuickSort : public Ordination<Key> {

 public:
  void Sort(std::vector<Key> v, int seq_length) override {}
};

template<class Key>
class IncrementDecrement : public Ordination<Key> {

 public:
  void Sort(std::vector<Key> v, int seq_length) override {}
};

template<class Key>
class HeapSort : public Ordination<Key> {

 public:
  void Sort(std::vector<Key> v, int seq_length) override {}
};

template<class Key>
class RadixSort : public Ordination<Key> {

 public:
  void Sort(std::vector<Key> v, int seq_length) override {}
};






#endif // _ORDINATION_H_