/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica hashtable
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 5/04/2022
* @file sequence.cc
*/

#ifndef _SEQUENCE_
#define _SEQUENCE_

#include<vector>

/**
 * @brief Clase abstracta que define los métodos comunes
 * 
 * @tparam Key 
 */
template<class Key>
class Sequence {
 public:
  /// Métodos
  /// Retorna true si el elemento está dentro
  virtual bool Search(const Key& key);
  /// Retorna true si el valor es insertado, false si no
  virtual bool Insert(const Key& key);
  /// Retorna true si está llena, sino, false
  virtual bool IsFull() const;
};


//##############################################################################
//#################################Class List###################################
//##############################################################################

/**
 * @brief Clase lista, esto implica que la sequence es de tamaño infinito
 * 
 * @tparam Key 
 */
template<class Key>
class List : public Sequence<Key> {
 public:
  List(){}
  bool Search(const Key& key) override;
  bool Insert(const Key& key) override;
  bool IsFull() const override {return(false);};

 private:
  std::vector<Key> list_;
};


/**
 * @brief Método que sirve para encontrar un elemento, si este está dentro será
 * devuelto un true, si no lo está será devuelto un false
 * 
 * @tparam Key 
 * @param key. Se busca este elemento dentro de Sequence
 * @return true si el elemento es encontrado
 * @return false si el elemento no está 
 */
template<class Key>
bool List<Key>::Search(const Key& key) {
  bool found = false;
  for(int i{0}; i < list_.size(); i ++) {
    if (list_[i] == key) {
      found = true;
      break;
    }
  }
  return (found);
}

/**
 * @brief Función que sirve para introducir elementos dentro de la lista
 * 
 * @tparam Key 
 * @param key 
 * @return true si el elemento ha sido introducido
 * @return false si el elemento no ha sido introducido
 */
template<class Key>
bool List<Key>::Insert(const Key& key) {  
  bool inserted = false;
  if (Search(key) == false) {
    list_.emplace_back(key);
    inserted = true;
  }
  return (inserted);
}


//##############################################################################
//################################Class Block###################################
//##############################################################################

template<class Key>
class Block : public Sequence<Key> {
 public:
  Block();
  Block(int block_size) : block_size_(block_size) {};
  bool Search(const Key& key) override;
  bool Insert(const Key& key) override;
  bool IsFull() const override {return((block_.size() == block_size_) ? true : false);};

 private:
  unsigned block_size_{0};
  std::vector<Key> block_;
};


/**
 * @brief Primero se comprueba si el tamaño del bloque al introducir no sea mayor
 * que el tamaño especificado
 * 
 * @tparam Key 
 * @param key 
 * @return true si el elemento ha sido introducido
 * @return false si el elemento no ha sido introducido
 */
template<class Key>
bool Block<Key>::Insert(const Key& key) {  
  bool inserted = false;
  if (block_.size() != block_size_) {
    if (Search(key) == false) {
      block_.emplace_back(key);
      inserted = true;
    }
  }
  return (inserted);
}

/**
 * @brief Busca el elemento para ver si está dentro de la secuencia
 * 
 * @tparam Key 
 * @param key 
 * @return true si el elemento ha sido encontrado
 * @return false si el elemento no ha sido encontrado
 */
template<class Key>
bool Block<Key>::Search(const Key& key) {  
  bool found = false;
  for(int i{0}; i < block_.size(); i ++) {
    if (block_[i] == key) {
      found = true;
      break;
    }
  }
  return (found);
}
#endif