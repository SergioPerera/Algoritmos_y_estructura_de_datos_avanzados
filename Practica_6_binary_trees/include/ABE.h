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
#include "../include/node.h"

#include <queue>

template<class Key>
class ABE : public AB<Key> {
 public:
  /// Constructor
  ABE(NodeB<Key>* node = NULL) : AB<Key>::AB(node) {};

  /// Métodos
  bool Insert(const Key& key) override;
  bool Search(const Key& key) const override;
  void Inorden() const override {AB<Key>::Inorden();};

  bool InsertEquilibratedBranch(const Key& key);

  template<typename T>
  friend std::ostream& operator<<(std::ostream& out, const AB<T>* const in_node); /// posible fallo por poner key

};

template<typename Key>
bool ABE<Key>::InsertEquilibratedBranch(const Key& data) {

}


template<typename Key>
bool ABE<Key>::Insert(const Key& data) {
  
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const AB<T>* const in_node) {
  std::queue<std::pair<NodeB<T>*, T>> q; /// Posible fallo por poner T en vez de int
  q.push(std::make_pair(in_node -> root_, 0));

  std::pair<NodeB<T>, T> aux {in_node->root_, 0};/// Posible fallo por poner T en vez de int
  NodeB<T>* node;
  T level {0};
  T current_level{0};
  q.push(aux);
  while (!q.empty()) {
    aux = q.front();
    q.pop();

    if (level > current_level) {
      current_level = aux.second;
    }
    if (aux.first == nullptr) out << "[.]";
    else {
      out << "[" << aux.first->GetData() << "]";
      q.push(std::make_pair(aux.first->GetLeftSon(), aux.second + 1));
      q.push(std::make_pair(aux.first->GetRightSon(), aux.second + 1));
    }
  }
  return out;
}

#endif // _ABE_H_