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
* @file dispersion_function.cc
*/
#ifndef _DISPERSION_
#define _DISPERSION_
//##############################################################################
//##################### Class DispersionFunction ################################
//##############################################################################

/**
 * @brief Clase que guarda los métodos principales de las funciones de dispersión
 * 
 * @tparam Key 
 */
template<class Key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const Key& k) const = 0;
};

//##############################################################################
//############################ Class fdModule ##################################
//##############################################################################

/**
 * @brief Función de módulo, esta usa el módulo para obtener el valor 
 * de dispersión
 * 
 * @tparam Key 
 */
template<class Key>
class FdModule: public DispersionFunction<Key> {
 public:
  FdModule(const unsigned n): table_size_(n){}
  unsigned operator()(const Key& k) const override { return k % table_size_; }
 private:
  unsigned table_size_;
};


//##############################################################################
//########################### Class fdBasedOnSum ###############################
//##############################################################################

/**
 * @brief Función basada en la suma, esta función coge la llav, suma todos sus
 * valores y luego hace la división entera entre la suma de los valores y el 
 * tamaño de la tabla. De esta manera el valor resultante es una posición dentro
 * de la tabla
 * 
 * @tparam Key 
 */
template<class Key>
class FdBasedOnSum : public DispersionFunction<Key> {
 public:
  FdBasedOnSum(const unsigned n): table_size_(n){}
  unsigned operator()(const Key& k) const;
 private:
  unsigned table_size_;
};


template<class Key>
unsigned FdBasedOnSum<Key>::operator()(const Key& k) const {
  int num_sum{0};
  int aux {0};
  ulong k_cpy{k};
  while ( k > 0) {
    aux = k_cpy;
    num_sum += aux;
    k_cpy /= 10;
  }
  return (num_sum % table_size_);
}


//##############################################################################
//######################### Class fdPseudoRamdom ###############################
//##############################################################################

/**
 * @brief Función que hace uso de un número pseudoaleatorio que luego es
 * sometido a una división entera entre el tamaño de la tabla para así conseguir
 * un valor que coincide dentro del rago de posiciones de la tabla
 * 
 * @tparam Key 
 */
template<class Key>
class FdPseudoRamdom : public DispersionFunction<Key> {
 public:
  FdPseudoRamdom(const unsigned n): table_size_(n){}
  unsigned operator()(const Key& k) const;
 private:
  unsigned table_size_;
};


template<class Key>
unsigned FdPseudoRamdom<Key>::operator()(const Key& k) const {
  srand(k);
  return (rand() % table_size_);
};

#endif