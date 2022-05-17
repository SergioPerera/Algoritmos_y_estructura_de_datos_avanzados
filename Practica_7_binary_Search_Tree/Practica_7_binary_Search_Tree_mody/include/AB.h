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
#include "../include/dummy.h"

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
  virtual bool Delete(const Key& data) = 0;

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
  NodeB<Key>*& GetRootReferenced() const { return root_; };

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
  std::queue<std::pair<NodeB<T>*, T>> q; /// Posible fallo por poner T en vez de int
  std::pair<NodeB<T>*, T> aux {in_node->root_, 0};/// Posible fallo por poner T en vez de int
  T current_level{0};
  q.push(aux);
  out << YELLOW << "\nNivel " << current_level << ": ";
  while (!q.empty()) {
    aux = q.front();
    q.pop();

    if (aux.second > current_level) {
      current_level = aux.second;
      out << YELLOW << "\nNivel " << current_level << ": ";  
    }
    if (aux.first == nullptr){ 
      out << YELLOW << "[.]";   
    }
    else {
      out << YELLOW << "[" << aux.first->GetData() << "]";
      q.push(std::make_pair(aux.first->GetLeftSon(), aux.second + 1));
      q.push(std::make_pair(aux.first->GetRightSon(), aux.second + 1));
    }
  }
  out << RESET;
  return out;
}

#endif // _AB_H_