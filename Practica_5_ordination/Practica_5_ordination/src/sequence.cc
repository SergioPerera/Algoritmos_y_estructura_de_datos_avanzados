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


// template <class Key>
// Sequence<Key>::Sequence(int sequence_length, std::vector<Key>& v, 
//                         std::string& algorithm) {
//   sequence_length_ = sequence_length;
//   sequence_ = v;
//   switch(algorithm) {
//     case "S":
//       sort_ = new SelectionSort<Key>();
//       break;
//     case "Q":
//       sort_ = new QuickSort<Key>();
//       break;
//     case "I":
//       sort_ = new IncrementDecrement<Key>();
//       break;
//     case "H":
//       sort_ = new HeapSort<Key>();
//       break;
//     case "R":
//       sort_ = new RadixSort<Key>();
//       break;
//   }
// }