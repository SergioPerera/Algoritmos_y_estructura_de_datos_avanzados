/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica: Árbol binario equilibrado
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 10/05/2022
* @file node.h
*/

#ifndef _NODOB_H_
#define _NODOB_H_

#include <iostream>

template<class Key>
class NodeB {
 public:
  /// Constructor
  NodeB() : data_(0), left_(NULL), right_(NULL) {};
  NodeB(const Key& key, NodeB<Key>* left = NULL, NodeB<Key>* right = NULL) : 
      data_(key), left_(left), right_(right) {};

  /// Getters
  NodeB<Key>* GetRightSon() { return right_; };
  NodeB<Key>* GetLeftSon() { return left_; };
  Key GetData() { return data_; };

  /// Setters
  void SetRightSon(NodeB<Key>* right) { right_ = right; };
  void SetLeftSon(NodeB<Key>* left) { left_ = left; };
  void SetData(Key data) { data_ = data; }; 

 private:
  Key data_;
  NodeB<Key>* left_;
  NodeB<Key>* right_;
};

#endif // _NODOB_H_