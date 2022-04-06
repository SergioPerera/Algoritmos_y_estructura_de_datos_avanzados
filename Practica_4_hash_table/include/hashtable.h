/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica hashtable
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 5/04/2022
* @file hashtable.cc
*/

#ifndef _HASHTABLE_
#define _HASHTABLE_
#include "../include/sequence.h"
#include "../include/dispersion_function.h"
#include "../include/exploration_function.h"

template<class Key>
class HashTable {
 public:
 private:
  unsigned table_size_{0};
  DispersionFunction<Key> *fd_;
  ExplorationFunction<Key> *fe_;
  unsigned block_size_{0};
  Sequence<Key>** table_;
};






#endif