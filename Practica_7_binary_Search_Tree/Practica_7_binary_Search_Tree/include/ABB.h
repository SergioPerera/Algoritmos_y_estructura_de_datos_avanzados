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
* @file ABB.h
*/

#ifndef _ABB_H_
#define _ABB_H_

#include "../include/AB.h"
#include "../include/node.h"

#include <queue>
/**
 * @brief Clase Árbol Binario Equilibrado (ABB), que sirve para generar un 
 * objeto árbol binario equilibrado, heredando métodos de la clase AB
 * 
 * @tparam Key 
 */ 
template<class Key>
class ABB : public AB<Key> {
 public:
  /// Constructor
  ABB(NodeB<Key>* node = NULL) : AB<Key>::AB(node) {};

  /// Métodos
  bool Insert(const Key& key) override;
  bool Search(const Key& key) const override;

  bool InsertEquilibratedBranch(const Key& key, NodeB<Key>* node);
  int BranchSize(NodeB<Key>* node) const;  
  
  // template<typename Key>
  bool SearchDataPreorder(NodeB<Key>* nodo, const Key& data) const;
  bool InsertBranch(NodeB<Key>* &node, const Key& data) const;

  bool Delete(const Key& data) override;
  bool DeleteData(NodeB<Key>* &node, const Key& data) const;
  void ReplaceDeleted(NodeB<Key>* &deleted, NodeB<Key>* &node) const;

};
template<typename Key>
void ABB<Key>::ReplaceDeleted(NodeB<Key>* &deleted, NodeB<Key>* &node) const { 
  if (node->GetRightSon() != NULL) 
    ReplaceDeleted(deleted, node->GetRightSonReferenced());
  else {
    deleted->SetData(node->GetData());
    deleted = node;
    node = node->GetLeftSon();  
  }
}


template<typename Key>
bool ABB<Key>::Delete(const Key& data) { 
  bool deleted{false};
  if (Search(data)) {
    deleted = DeleteData(this->root_, data);
  }
  return deleted;
}

template<typename Key>
bool ABB<Key>::DeleteData(NodeB<Key>* &node, const Key& data) const { 
  // if (nodo == NULL) return NULL ;
  // if (clave_dada < nodo->clave) EliminarRama(nodo->izdo, clave_dada);
  // else if (clave_dada > nodo->clave) EliminarRama(nodo->dcho, clave_dada);
  // else {  //clave_dada == nodo->clave
  //   nodoBB* Eliminado = nodo;
  //   if (nodo->dcho == NULL) nodo = nodo->izdo;
  //   else if (nodo->izdo == NULL) nodo = nodo->dcho;
  //   else 
  //     sustituye(Eliminado, nodo->izdo);

  //   delete (Eliminado);
  // }

  // if (sust->dcho != NULL) 
  //   sustituye(eliminado, sust->dcho);
  // else {
  //    eliminado->Info = sust->Info ;
  //    eliminado->Clave = sust->Clave ;
  //    eliminado = sust ;
  //    sust = sust->izdo ;
  bool deleted_flag{false};
  if (node == NULL) return false;
  if (data < node->GetData()) DeleteData(node->GetLeftSonReferenced(), data);
  else if (data < node->GetData()) {
    DeleteData(node->GetRightSonReferenced(), data);
    deleted_flag = true;
  } 
  else {
    NodeB<Key>* deleted = node;
    if (node->GetRightSonReferenced() == NULL) 
      node = node->GetLeftSonReferenced();
    else if (node->GetLeftSonReferenced() == NULL) 
      node = node->GetRightSonReferenced();
    else {
      ReplaceDeleted(deleted, node->GetLeftSonReferenced());
      deleted_flag = true;
    }
    delete deleted;
  }
  return(deleted_flag);
}


/**
 * @brief Función que se encarga de medir la longitud de la rama
 * 
 * @tparam Key 
 * @param node Nodo a insetar
 * @return int 
 */
template<typename Key>
int ABB<Key>::BranchSize(NodeB<Key>* node) const {
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
bool ABB<Key>::Insert(const Key& data) {
  bool inserted = false;
  if (Search(data) == false) {
    if (this->root_ == NULL) {
      this->root_ = new NodeB<Key>(data);
      inserted = true;
    }
    else {
      inserted = InsertBranch(this->root_, data);
    }
  }
  return inserted;
}

template<typename Key>
bool ABB<Key>::InsertBranch(NodeB<Key>* &node, const Key& data) const {
  bool inserted {false};
  if (node == NULL) {
    node = new NodeB<Key>(data, NULL, NULL);
    inserted = true;
  }
  else if (data < node->GetData()) {
    inserted = InsertBranch(node->GetLeftSonReferenced(), data);
  }
  else {
    inserted = InsertBranch(node->GetRightSonReferenced(), data);
  } 
  return (inserted);
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
bool ABB<Key>::InsertEquilibratedBranch(const Key& data, NodeB<Key>* node) {
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
bool ABB<Key>::SearchDataPreorder(NodeB<Key>* node, const Key& data) const {
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
bool ABB<Key>::Search(const Key& data) const {
  bool result{false};
  result = this->SearchDataPreorder(this->root_, data);
  return result;
}
#endif // _ABB_H_