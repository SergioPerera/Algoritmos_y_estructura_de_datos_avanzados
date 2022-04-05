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
//############################ Class fdModule ##################################
//##############################################################################

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
  while ( k > 0) {
    aux = k;
    num_sum += aux;
    k /= 10;
  }
  return (num_sum % table_size_);
}


//##############################################################################
//######################### Class fdPseudoRamdom ###############################
//##############################################################################

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
}