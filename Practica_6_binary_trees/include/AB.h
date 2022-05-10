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

template<class Key>
class AB {
 public:
  /// Constructor
  AB(NodeB<Key>* node = NULL) : root_(node) {};

  /// Métodos
  virtual bool Insert(const Key& key) = 0;
  virtual bool Search(const Key& key) const = 0;
  virtual void Inorden() const = 0;
  // operator>>(std::ostream& os) const;
 private:
 protected:
  NodeB<Key>* root_;
  int BranchSize(NodeB<Key>* node) const;
};

template<typename Key>
void AB<Key>::Inorden() const {
  if (root_ == NULL) return;
  std::cout << Inorden(root_ -> GetLeftSon()) << " ";
  std::cout << root_.GetData() << " ";
  std::cout << Inorden(root_.GetRightSon()) << "";
}

template<typename Key>
int AB<Key>::BranchSize(NodeB<Key>* node) const {
  if (node == NULL) return 0; 
  return 1 + BranchSize(node->left_) + BranchSize(node->right_);
}

#endif // _AB_H_