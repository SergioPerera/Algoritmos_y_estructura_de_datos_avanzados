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

  bool InsertEquilibratedBranch(const Key& key, NodeB<Key>* node);
  int BranchSize(NodeB<Key>* node) const;  
  
  // template<typename Key>
  bool SearchDataPreorder(NodeB<Key>* nodo, const Key& data) const;
};



template<typename Key>
int ABE<Key>::BranchSize(NodeB<Key>* node) const {
  if (node == NULL) return 0; 
  return 1 + BranchSize(node->GetLeftSon()) + BranchSize(node->GetRightSon());
}

template<typename Key>
bool ABE<Key>::Insert(const Key& data) {
  bool inserted = false;
  if (Search(data) == false) {
    if (this->root_ == NULL) {
      this->root_ = new NodeB<Key>(data);
      inserted = true; // Insertado
    }
    else {
      inserted = InsertEquilibratedBranch(data, this->root_);
    }
  }
  return inserted;
}


template<typename Key>
bool ABE<Key>::InsertEquilibratedBranch(const Key& data, NodeB<Key>* node) {
  bool inserted{false};
  if (this->BranchSize(node->GetLeftSon()) <= this->BranchSize(node->GetRightSon())) {
    if (node->GetLeftSon() != NULL) {
      inserted = this->InsertEquilibratedBranch(data, node->GetLeftSon());
    }
    else { 
      node->SetLeftSon(new NodeB<Key>(data, NULL, NULL));

      inserted = true;
    }
  }
  else {
    if (node->GetRightSon() != NULL) {
      InsertEquilibratedBranch(data, node->GetRightSon()); 
    }
    else{
      node->SetRightSon(new NodeB<Key>(data, NULL, NULL));
      inserted = true;
    }
  }
  return inserted;
}



template<typename Key>
bool ABE<Key>::SearchDataPreorder(NodeB<Key>* node, const Key& data) const {
  bool result{false};
  if (node != nullptr) {
    if (data == node->GetData()) result = true;
    else {
      result = this->SearchDataPreorder(node->GetLeftSon(), data);
      if (!result) result = this->SearchDataPreorder(node->GetRightSon(), data);
    }
  }
  return result;
}

template<typename Key>
bool ABE<Key>::Search(const Key& data) const {
  bool result{false};
  result = this->SearchDataPreorder(this->root_, data);
  return result;
}
#endif // _ABE_H_