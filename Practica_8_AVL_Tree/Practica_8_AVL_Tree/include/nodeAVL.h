/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica: Árbol binario equilibrado
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 24/05/2022
* @file nodeAVL.h
*/

#ifndef _NODEAVL_H_
#define _NODEAVL_H_

#include "../include/node.h"

/**
 * @brief Clase encargada de crear objetos nodeAVL
 * 
 * @tparam Key 
 */
template<class Key>
class NodeAVL : public NodeB<Key> {
 public:
  NodeAVL() {};
  NodeAVL(const Key& data, NodeAVL<Key>* left = NULL, NodeAVL<Key>* right = NULL)
          : NodeB<Key>::NodeB(), balance_(0) {};

  int GetBalance() {return balance_;};
  NodeAVL<Key>* GetLeftSon() const;
  NodeAVL<Key>* GetRigthSon() const;
  NodeAVL<Key>*& GetLeftSonReferenced();
  NodeAVL<Key>*& GetRigthSonReferenced();

  void SetBal(const int& bal) { balance_ = bal; };

  void SetLeftSon(NodeAVL<Key>* left = NULL) {
    this->NodeB<Key>::SetLeftSon(left);
  };
  void SetRightSon(NodeAVL<Key>* right = NULL) {
    this->NodeB<Key>::SetRightSon(right);
  };

  NodeAVL<Key>& operator=(const NodeAVL<Key>& node);
  template<typename T>
  friend std::ostream& operator<<(std::ostream& out, const NodeAVL<T>& nodo);

 private:
  int balance_; 
};


/**
 * @brief Getter del hijo izquierdo
 * 
 * @tparam Key 
 * @return NodeAVL<Key>* 
 */
template<typename Key>
NodeAVL<Key>* NodeAVL<Key>::GetLeftSon() const {
  return reinterpret_cast<NodeAVL<Key>*>(this->NodeB<Key>::GetLeftSon());
}

/**
 * @brief Getter del hijo derecho
 * 
 * @tparam Key 
 * @return NodeAVL<Key>* 
 */
template<typename Key>
NodeAVL<Key>* NodeAVL<Key>::GetRigthSon() const {
  return reinterpret_cast<NodeAVL<Key>*>(this->NodeB<Key>::GetRigthSon());
}

/**
 * @brief Getter del hijo izquierdo referenciado
 * 
 * @tparam Key 
 * @return NodeAVL<Key>*& 
 */
template<typename Key>
NodeAVL<Key>*& NodeAVL<Key>::GetLeftSonReferenced() {
  return reinterpret_cast<NodeAVL<Key>*&>(this->NodeB<Key>::GetLeftSonReferenced());
}

/**
 * @brief Getter del hijo derecho referenciado
 * 
 * @tparam Key 
 * @return NodeAVL<Key>*& 
 */
template<typename Key>
NodeAVL<Key>*& NodeAVL<Key>::GetRigthSonReferenced() {
  return reinterpret_cast<NodeAVL<Key>*&>(this->NodeB<Key>::GetRigthSonReferenced());
}

/**
 * @brief Operador de asignación
 * 
 * @tparam Key 
 * @param node
 * @return NodeAVL<Key>& 
 */
template<typename Key>
NodeAVL<Key>& NodeAVL<Key>::operator=(const NodeAVL<Key>& node) {
  SetBal(node.GetBalance());
  SetData(node.GetData());
  SetLeftSon(node.GetLeftSon());
  SetRightSon(node.GetRigthSon());
}

/**
 * @brief Operador de salida
 * 
 * @tparam T 
 * @param out 
 * @param node 
 * @return std::ostream& 
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const NodeAVL<T>& node) {
  return out << node.data_;
}

#endif