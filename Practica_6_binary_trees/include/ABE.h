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
* @file ABE.h
*/

#ifndef _ABE_H_
#define _ABE_H_

#include "../include/AB.h"

template<class Key>
class ABE : public AB<Key> {
 public:
  /// Constructor
  ABE(NodeB<Key>* node = NULL) : AB<Key>::AB(node) {};

  /// Métodos
  virtual bool Insert(const Key& key) override;
  virtual bool Search(const Key& key) const override;
  virtual bool Inorden() const override;
  // operator>>(std::ostream& os) const;

};

#endif // _ABE_H_