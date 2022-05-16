/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica: Árbol binario equilibrado
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 16/05/2022
* @file nodebb.h
*/

#ifndef _NODEBB_H_
#define _NODEBB_H_

#include <iostream>

template<class Key>
class NodeBB {
 public:
  /// Constructor
  NodeBB() : data_(0), left_(NULL), right_(NULL) {};
  NodeBB(const Key& key, NodeBB<Key>* left = NULL, NodeBB<Key>* right = NULL) : 
         data_(key), left_(left), right_(right) {};

  /// Getters
  NodeBB<Key>* GetRightSon()const { return right_; } ;
  NodeBB<Key>* GetLeftSon() const{ return left_; };
  Key GetData() const { return data_; };

  /// Setters
  void SetRightSon(NodeBB<Key>* right) { right_ = right; };
  void SetLeftSon(NodeBB<Key>* left) { left_ = left; };
  void SetData(Key data) { data_ = data; }; 

 private:
  Key data_;
  NodeBB<Key>* left_;
  NodeBB<Key>* right_;
};

#endif // _NODEBB_H_