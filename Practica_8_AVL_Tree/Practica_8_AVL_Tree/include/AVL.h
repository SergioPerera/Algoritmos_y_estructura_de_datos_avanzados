/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica: Árbol binario equilibrado
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 24/05/2022
* @file AVL.h
*/

#ifndef _AVL_H_
#define _AVL_H_
#include "../include/ABB.h"

template<class Key>
class AVL : public ABB<Key> {
 public:
  AVL(bool traza = false, NodoAVL<Key>* nodo = nullptr);
  bool Insert(const Key& data) override;
  bool Delete(const Key& data) override;

  void SetRoot(NodoAVL<Key>* root);
  NodoAVL<Key>*& GetRoot(void);
  NodoAVL<Key>* GetRoot(void) const;
  
 private:
  bool traza_{false};
  // void Rotacion_II(NodoAVL<Key>* &nodo);
  // void Rotacion_DD(NodoAVL<Key>* &nodo);
  // void Rotacion_ID(NodoAVL<Key>* &nodo);
  // void Rotacion_DI(NodoAVL<Key>* &nodo);
  // void InsertaBal(NodoAVL<Key>* &root, NodoAVL<Key>* &nuevo, bool& crece);
  // void InsertReBalanceaIzda(NodoAVL<Key>* &nodo);
  // void InsertReBalanceaDcha(NodoAVL<Key>* &nodo);
  // void DeleteBranch(NodoAVL<Key>* &nodo, const Key& data, bool& decrece);
  // void Replace(NodoAVL<Key>* &eliminado, NodoAVL<Key>* &sust, bool& decrece);
  // void DeleteReBalanceaIzda(NodoAVL<Key>* &nodo);
  // void DeleteReBalanceaDcha(NodoAVL<Key>* &nodo);
};






#endif // _AVL_H_