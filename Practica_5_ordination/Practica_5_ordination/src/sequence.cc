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
* @file sequence.cc
*/

#include "../include/sequence.h"

template <class Key>
void Sequence<Key>::SetSort() {
  
}

template <class Key>
Sequence<Key>::Sequence(int sequence_length, std::vector<Key>& v, std::string& algorithm) {
  sequence_length_ = sequence_length;
  sequence_ = v;
}