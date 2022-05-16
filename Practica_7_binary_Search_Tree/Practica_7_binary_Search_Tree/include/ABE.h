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
/**
 * @brief Clase Árbol Binario Equilibrado (ABE), que sirve para generar un objeto
 * árbol binario equilibrado, heredando métodos de la clase AB
 * 
 * @tparam Key 
 */
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
  
  bool SearchDataPreorder(NodeB<Key>* nodo, const Key& data) const;
};



/**
 * @brief Función que se encarga de medir la longitud de la rama
 * 
 * @tparam Key 
 * @param node Nodo a insetar
 * @return int 
 */
template<typename Key>
int ABE<Key>::BranchSize(NodeB<Key>* node) const {
  if (node == NULL) return 0; 
  return 1 + BranchSize(node->GetLeftSon()) + BranchSize(node->GetRightSon());
}

/**
 * @brief Función encargada de insertar un nodo nuevo, comprobando que no esté 
 * insetado ya
 * 
 * @tparam Key 
 * @param data Es el nodo que se quiere introducir
 * @return true 
 * @return false 
 */
template<typename Key>
bool ABE<Key>::Insert(const Key& data) {
  bool inserted = false;
  if (Search(data) == false) {
    if (this->root_ == NULL) {
      this->root_ = new NodeB<Key>(data);
      inserted = true;
    }
    else {
      inserted = InsertEquilibratedBranch(data, this->root_);
    }
  }
  return inserted;
}

/**
 * @brief Función que inserta un nodo de manera que mantenga el equilibrio de 
 * las ramas
 * 
 * @tparam Key 
 * @param data dato a insertar
 * @param node nodo a insertar
 * @return true 
 * @return false 
 */
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
      inserted = true;
    }
    else{
      node->SetRightSon(new NodeB<Key>(data, NULL, NULL));
      inserted = true;
    }
  }
  return inserted;
}


/**
 * @brief Buscar datos siguiendo el algoritmo de preorden
 * 
 * @tparam Key 
 * @param node nodo raíz
 * @param data dato que se buscac
 * @return true 
 * @return false 
 */
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

/**
 * @brief Función encargada de buscar un dato, llamando a la función de preorden
 * 
 * @tparam Key 
 * @param data dato que se pretende buscar
 * @return true si se ha encontrado el dato
 * @return false si no se ha encontrado el dato
 */
template<typename Key>
bool ABE<Key>::Search(const Key& data) const {
  return SearchDataPreorder(this->root_, data);
}


#endif // _ABE_H_