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

template<class Key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const Key& k) const = 0;
};

//##############################################################################
//##############################Class fdModule##################################
//##############################################################################

template<class Key>
class FdModule: public DispersionFunction<Key> {
 public:
  fdModule(const unsigned n): tableSize(n){}
  unsigned operator()(const Key& k) const override { return k % table_size_; }
 private:
  unsigned table_size_;
};


//##############################################################################
//##############################Class fdModule##################################
//##############################################################################

template<class Key>
class FdBasedOnSum : public DispersionFunction<Key> {
 public:
  FdBasedOnSum(const unsigned n): tableSize(n){}
  unsigned operator()(const Key& k) const;
 private:
  unsigned table_size_;
};


template<class Key>
unsigned FdBasedOnSum<Key>::operator()(const Key& k) const {
  int num_sum{0};
//   int number = k;
  int aux {0};
  while ( number > 0) {
    aux = key;
    num_sum += aux;
    key /= 10;
    
  }
}
