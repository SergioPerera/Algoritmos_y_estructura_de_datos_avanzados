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
#include "../include/vehicle.h"

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
                          fd_ (fd),
                          fe_ (fe){
  /// Rellenamos los atributos privados necesarios para la tabla Hash menos fe_
  table_.resize(table_size_);

  /**
   * @brief Construimos un objeto List si fe_ es nulo, porque eso significa que
   * el usuario no ha introducido la función de exploración, por lo tanto, 
   * tenemos que tomar como predeterminada la función de dispersión abierta
   * 
   * En caso contrario construimos la tabla con objetos Block, ya que son de 
   * tamaño fijo y asiganmos la función de exploración
   */
  if (fe_ == nullptr) {
    for (ulong i{0}; i < table_size_; i++) {
      table_[i] = new List<Key>();
    }

  }
  else{
    fe_ = fe;
    for (ulong i{0}; i < table_size_; i++) {
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
  /**
   * @brief Hacemos esta comparación para ver si estamos en el caso de que la 
   * tabla tenga bloques de tamaño fijo
   * 
   * Sino hacemos la búsqueda para las tablas de tamaño variable
   */
  if (block_size_ !=0) {
    unsigned pos = fd_->operator()(k);
    for(ulong i{1}; i < table_size_; i++) {
      if(table_[pos]->Search(k) == true){return true;}
      else {
        /**
         * @brief Necesitamos mirar la siguiente posición, que está en función 
         * de la función de exploración, por ello hacemos uso de ella y le 
         * hacemos el módulo para obtener posiciones dentro de la tabla
         */
        pos = (pos + fe_->operator()(k,i)) % table_size_;
      }
      return false;
    }
  }
  else {
    return ((table_[fd_->operator()(k)]->Search(k) == true) ? true : false);
  }
  return (false);
};

/**
 * @brief Método encargado de que se introduzca un valor dentro de la tabla
 * 
 * @tparam Key, cualquier tipo de valor
 * @param k, key introducida por el usuario
 * @return true si ha sido insertada la key
 * @return false si no ha sido insertada la key
 */
template<class Key>
bool HashTable<Key>::Insert(const Key& k) {
    /**
   * @brief Hacemos esta comparación para ver si estamos en el caso de que la 
   * tabla tenga bloques de tamaño fijo
   * 
   * Sino hacemos la inserción para las tablas de tamaño variable
   */
  if (block_size_ !=0) {
    auto pos = (*fd_)(k);
    for (ulong i{1}; i < table_size_; i++) {
      /**
       * @brief En caso que insertemos algo y ya esté dentro retornamos false
       * sino, comprobamos si se puede insertar, en caso afirmativo lo hacemos
       * en caso negativo, buscamos otra posición
       */
      if (table_[pos]->Search(k) == true) {return false;}
      else if (table_[pos]->Insert(k) == true) {
        std::cout << "Se ha introducido en el bloque n " << pos << std::endl;
        return true;
      }
      else {
        pos = (pos + fe_->operator()(k, i)) % table_size_;
      }

    }
  }
  else {
    if (table_[fd_->operator()(k)]->Search(k) == true) {return false;};
    if (table_[fd_->operator()(k)]->Insert(k) == true) {
      std::cout << "Se ha introducido en el bloque n " << fd_->operator()(k)  << std::endl;
      return true;};
    return false;
  }
  return false;
}




#endif