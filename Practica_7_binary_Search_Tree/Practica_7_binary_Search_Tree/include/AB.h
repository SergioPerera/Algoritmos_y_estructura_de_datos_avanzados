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
* @file AB.h
*/

#ifndef _AB_H_
#define _AB_H_
#include <queue>
#include <iostream>
#include "../include/main_functions.h"

/**
 * @brief Clase abstracta Árbol Binario (AB), que sirve para generar un objeto
 * árbol binario
 * 
 * @tparam Key 
 */
template<class Key>
class AB {
 public:
  /// Constructor
  AB(NodeB<Key>* node = NULL) : root_(node) {};

  /// Métodos
  virtual bool Insert(const Key& key) = 0;
  virtual bool Search(const Key& key) const = 0;
  // virtual void Inorden(const NodeB<Key>* nodo) const = 0;
  void Inorden() const { this->Inorden_I(this->root_);};
  void Inorden_I(const NodeB<Key>* node) const;
  NodeB<Key>* GetRootAB() { return root_; }
  template<typename T>
  friend std::ostream& operator<<(std::ostream& out, const AB<T>* const in_node); /// posible fallo por poner key
 private:
 protected:
  NodeB<Key>* root_;
  NodeB<Key>* GetRoot() { return root_; }
};


/**
 * @brief Función que se encarga de imprimir los datos del árbol 
 * siguiendo el algoritmo de inorden
 * 
 * @tparam Key 
 * @param node 
 */
template<typename Key>
void AB<Key>::Inorden_I(const NodeB<Key>* node) const {
  if (node == NULL) return;
  this->Inorden_I(node->GetLeftSon());
  std::cout << node->GetData() << " ";
  this->Inorden_I(node->GetRightSon());
}

/**
 * @brief Operador de salida para imprimir los datos del árbol haciendo un 
 * recorrido por niveles
 * 
 * @tparam T 
 * @param out variable que contiene el árbol listo para ser impeso por pantalla
 * @param in_node Nodo raíz del árbol
 * @return std::ostream& 
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const AB<T>* const in_node) {
  // std::queue<std::pair<NodeB<T>*, T>> q; /// Posible fallo por poner T en vez de int
  // std::pair<NodeB<T>*, T> aux {in_node->root_, 0};/// Posible fallo por poner T en vez de int
  // T current_level{0};
  // q.push(aux);
  // while (!q.empty()) {
  //   aux = q.front();
  //   q.pop();

  //   if (aux.second > current_level) {
  //     current_level = aux.second;
  //     out << "\n";
  //   }
  //   if (aux.first == nullptr){ 
  //     out << YELLOW << "[.]";   
  //   }
  //   else {
  //     out << YELLOW << "[" << aux.first->GetData() << "]";
  //     q.push(std::make_pair(aux.first->GetLeftSon(), aux.second + 1));
  //     q.push(std::make_pair(aux.first->GetRightSon(), aux.second + 1));
  //   }
  // }
  // out << RESET;
  // return out;

  std::queue<std::pair<NodeB<T>*, int>> aux_queue;
  std::pair<NodeB<T>*, int> aux_pair{in_node->root_, 0};
  int current_level{0};
  aux_queue.push(aux_pair);
  while (!aux_queue.empty()) {
    aux_pair = aux_queue.front(); ///< Guardamos la parte inicial de la cola, luego la borramos
    aux_queue.pop();
    if (aux_pair.second > current_level) {
      current_level = aux_pair.second;
      out << "\n";
    }
    if(aux_pair.first != nullptr) {
      out << "[" << aux_pair.first->GetData() << "]";
      aux_queue.push(std::make_pair(aux_pair.first->GetLeftSon(), aux_pair.second + 1));
      aux_queue.push(std::make_pair(aux_pair.first->GetRightSon(), aux_pair.second + 1));
    }
    else out << "[.]";
    // if (aux_pair.first == nullptr) out << "[.]";
    // else {
    //   out << "[" << aux_pair.first->GetData() << "]";
    //   aux_queue.push(std::make_pair(aux_pair.first->GetLeftSon(), aux_pair.second + 1));
    //   aux_queue.push(std::make_pair(aux_pair.first->GetRightSon(), aux_pair.second + 1));
    // }
  }
  return out;
}

#endif // _AB_H_