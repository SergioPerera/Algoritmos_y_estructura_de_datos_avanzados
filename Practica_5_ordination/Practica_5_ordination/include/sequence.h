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
* @file sequence.h
*/

#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include "../include/ordination.h"

template<class Key>
class Sequence {
 public:
  /// Constructor
  Sequence() {};
  Sequence(int sequence_length, std::vector<Key> v, std::string& algorithm);

  /// Operadores
  friend std::ostream& operator<<(std::ostream& os, const Sequence& sq) {
    for (ulong i = 0; i < sq.sequence_.size(); i++) {
      os << sq.sequence_[i] << " ";
    }
    return(os);
  }

  /// Métodos
  void SetSort();
  void Sort() { sort_ -> Sort(sequence_, sequence_length_); };
 private:
  std::vector<Key> sequence_;
  int sequence_length_;
  Ordination<Key>* sort_;
};


template <class Key>
Sequence<Key>::Sequence(int sequence_length, std::vector<Key> v, 
                        std::string& algorithm) {
  sequence_length_ = sequence_length;
  sequence_ = v;
  switch(algorithm[0]) {
    case 'S':
      sort_ = new SelectionSort<Key>();
      break;
    case 'Q':
      sort_ = new QuickSort<Key>(0, sequence_length - 1);
      break;
    case 'I':
      sort_ = new IncrementDecrement<Key>();
      break;
    case 'H':
      sort_ = new HeapSort<Key>();
      break;
    case 'R':
      sort_ = new RadixSort<Key>();
      break;
  }
}
#endif // _SEQUENCE_H_