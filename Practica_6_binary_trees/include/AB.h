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
  // virtual void Inorden(const NodeB<Key>* nodo) const = 0;
  void Inorden(const NodeB<Key>* nodo) const;

  // operator>>(std::ostream& os) const;
 private:
 protected:
  NodeB<Key>* root_;
  NodeB<Key>* GetRoot() { return root_; }  
  // int BranchSize(NodeB<Key>* node) const;
};



template<typename Key>
void AB<Key>::Inorden(const NodeB<Key>* node) const {
  if (node == NULL) return;
  std::cout << Inorden(node->GetLeftSon()) << " ";
  std::cout << node.GetData() << " ";
  std::cout << Inorden(node->GetRightSon()) << "";
}


#endif // _AB_H_