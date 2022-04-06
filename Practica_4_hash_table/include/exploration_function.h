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
* @file exploration_function.cc
*/
#ifndef _EXPLORATION_
#define _EXPLORATION_
//##############################################################################
//###################### Class ExplorationFunction #############################
//##############################################################################

/**
 * @brief Esta clase almacena la sobrecarga del operador de las distintas 
 * funciones de exploración
 * 
 * @tparam Key 
 */
template<class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

//##############################################################################
//########################## Class FeLineal ####################################
//##############################################################################

/**
 * @brief Función lineal que retorna el número de exploración siguiente
 * 
 * @tparam Key 
 */
template<class Key>
class FeLineal: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const { return i; }
};

//##############################################################################
//########################## Class FeQuadratic #################################
//##############################################################################

/**
 * @brief Función cuadrática que retorna el número de exploración al cuadrado
 * 
 * @tparam Key 
 */
template<class Key>
class FeQuadratic: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const { return i*i; }
};


//##############################################################################
//#################### Class FeDoubleDispersion ################################
//##############################################################################

template<class Key>
class FeDoubleDispersion: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const;
};

template<class Key>
unsigned FeDoubleDispersion<Key>::operator()(const Key& k, unsigned i) const {
  int num_sum{0};
  int aux {0};
  while ( k > 0) {
    aux = k;
    num_sum += aux;
    k /= 10;
  }
  return (num_sum * i);
}

//##############################################################################
//######################## Class FeRedispersion ################################
//##############################################################################

template<class Key>
class FeRedispersion: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const;
};


template<class Key>
unsigned FeRedispersion<Key>::operator()(const Key& k, unsigned i) const {
  int num_sum{0};
  int aux {0};
  while ( k > 0) {
    aux = k;
    num_sum += aux;
    k /= 10;
  }
  return (num_sum * i);
}

/// Hacer un srand a la i y luego elegir una función de exploración con un switch

#endif