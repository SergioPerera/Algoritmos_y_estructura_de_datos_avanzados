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
* @file hashtable.cc
*/

#ifndef _HASHTABLE_
#define _HASHTABLE_
#include "../include/sequence.h"
#include "../include/dispersion_function.h"
#include "../include/exploration_function.h"

/**
 * @brief Clase encargada de generar la tabla hash y operar con ella
 * 
 * @tparam Key, cualquier tipo de dato
 */
template<class Key>
class HashTable {
 public:
  /// Constructor
  HashTable(int& table_size, DispersionFunction<Key>* fd, 
            const int& block_size = 0, 
            ExplorationFunction<Key>* fe = nullptr);
  /// Métodos
  bool Search(const Key& k) const;
  bool Insert(const Key& k);

 private:
  unsigned table_size_{0};
  unsigned block_size_{0};
  DispersionFunction<Key> *fd_;
  ExplorationFunction<Key> *fe_;
  std::vector<Sequence<Key>*> table_;
  // Sequence<Key>** table_;
};

/**
 * @brief Construct a new Hash Table< Key>:: Hash Table object
 * 
 * @tparam Key, cualquier tipo de valor
 * @param table_size tamaño de la tabla
 * @param fd función de dispersión
 * @param block_size tamaño del bloque 
 * @param fe función de exploración
 */
template<class Key>
HashTable<Key>::HashTable(int& table_size, 
                          DispersionFunction<Key>* fd, 
                          const int& block_size, 
                          ExplorationFunction<Key>* fe) :
                          table_size_ (table_size),
                          block_size_ (block_size),
                          fd_ (fd) {
  /// Rellenamos los atributos privados necesarios para la tabla Hash menos fe_
  // table_size_ = table_size;
  // block_size_ = block_size;
  // fd_ = fd;
  table_.resize(block_size_);

  /**
   * @brief Construimos un objeto List si fe_ es nulo, porque eso significa que
   * el usuario no ha introducido la función de exploración, por lo tanto, 
   * tenemos que tomar como predeterminada la función de dispersión abierta
   * 
   * En caso contrario construimos la tabla con objetos Block, ya que son de 
   * tamaño fijo y asiganmos la función de exploración
   */
  if (fe_ == nullptr) {
    for (int i{0}; i < table_size_; i++) {
      table_[i] = new List<Key>();
    }
  }
  else{
    fe_ = fe;
    for (int i{0}; i < table_size_; i++) {
      table_[i] = new Block<Key>(block_size_);
    }
  }
}

/**
 * @brief Función que busca en la tabla la key introducida por el usuario
 * 
 * @tparam Key, cualquier tipo de valor
 * @param k key que introduce el usuario
 * @return true si se ha encontrado el valor
 * @return false si no se ha encontrado el valor
 */
template<class Key>
bool HashTable<Key>::Search(const Key& k) const {

}

/**
 * @brief Método encargado de que se introduzca un valor dentro de la tabla
 * 
 * @tparam Key, cualquier tipo de valor
 * @param k, key introducida por el usuario
 * @return true si ha sido insertada la key
 * @return false si no ha sido insertada la key
 */
template<class Key>
bool HashTable<Key>::Insert(const Key& k){
  
}




#endif