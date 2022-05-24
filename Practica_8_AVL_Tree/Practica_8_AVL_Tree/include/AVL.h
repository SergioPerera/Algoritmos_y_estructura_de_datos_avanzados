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
#include "../include/nodeAVL.h"


template<class Key>
class AVL : public ABB<Key> {
 public:
  AVL(bool traza = false, NodeAVL<Key>* nodo = nullptr);
  bool Insert(const Key& data) override;
  bool Delete(const Key& data) override;

 protected:
  void SetRoot(NodeAVL<Key>* root);
  NodeAVL<Key>*& GetRoot(void);
  NodeAVL<Key>* GetRoot(void) const;
  
 private:
  bool traza_{false};
  void Rotation_II(NodeAVL<Key>* &nodo);
  void Rotation_DD(NodeAVL<Key>* &nodo);
  void Rotation_ID(NodeAVL<Key>* &nodo);
  void Rotation_DI(NodeAVL<Key>* &nodo);
  void InsertBalance(NodeAVL<Key>* &root, NodeAVL<Key>* &nuevo, bool& crece);
  void InsertBalanceLeft(NodeAVL<Key>* &nodo);
  void InsertBlanceRight(NodeAVL<Key>* &nodo);
  void DeleteBranch(NodeAVL<Key>* &nodo, const Key& data, bool& decrece);
  void Replace(NodeAVL<Key>* &eliminado, NodeAVL<Key>* &sust, bool& decrece);
  void DeleteReBalanceaIzda(NodeAVL<Key>* &nodo);
  void DeleteReBalanceaDcha(NodeAVL<Key>* &nodo);
};

/**
 * @brief Constructor de la clase AVL
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param traza le decimos a la clase si queremos tener un seguimiento de los
 * cambios que se produciran en el arbol
 * @param nodo sera el nodo root del arbol
 */
template<typename Key>
AVL<Key>::AVL(bool traza, NodeAVL<Key>* node) : traza_(traza) {
  this->AB<Key>::SetRoot(node);
}

/**
 * @brief Metodo que se encarga de insertar un dato en el arbol
 * 
 * @tparam Key tipo de dato de los nodos del arbol
 * @param data es el dato que ira en el nodo a insertar
 * @return true el nodo se inserto correctamente en el arbol
 * @return false el nodo no se inserto correctamente en el arbol
 */
template<typename Key>
bool AVL<Key>::Insert(const Key& data) {
  NodeAVL<Key>* nuevo = new NodeAVL<Key>(data);
  bool crece{false};
  this->InsertBalance(this->GetRoot(), nuevo, crece);
  return crece;
}

/**
 * @brief Metodo que se encarga de eliminar un nodo del arbol correctamente
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el dato que ira en el nodo a insertar
 * @return true el nodo se pudo eliminar correctamente
 * @return false el nodo no se pudo eliminar o no se encuentra en el arbol
 */
template<typename Key>
bool AVL<Key>::Delete(const Key& data) {
  bool decrece{false};
  DeleteBranch(this->GetRoot(), data, decrece);
  return decrece;
}

/**
 * @brief Metodo que cambia el valor de la root del arbol
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param root nuevo nodo root del arbol
 */
template<typename Key>
void AVL<Key>::SetRoot(NodeAVL<Key>* root) {
  this->AB<Key>::SetRoot(root);
}

/**
 * @brief metodo que devuelve una referencia a la root del arbol AVl
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return NodeAVL<Key>*& es el nodo root del arbol
 */
template<typename Key>
NodeAVL<Key>*& AVL<Key>::GetRoot(void) {
  return reinterpret_cast<NodeAVL<Key>*&>(this->AB<Key>::GetRootReferenced());
}

/**
 * @brief metodo que devuelve una copia de la root del arbol AVL
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return NodeAVL<Key>* es el nodo root del arbol
 */
template<typename Key>
NodeAVL<Key>* AVL<Key>::GetRoot(void) const {
  return reinterpret_cast<NodeAVL<Key>*>(this->AB<Key>::GetRoot());
}

/**
 * @brief metodo encargado de realizar la Rotation izquierda izquierda al nodo
 * que se le pase
 * 
 * @tparam Key es el tipo de dato de los datos del arbol
 * @param nodo es el nodo a realizarle la Rotation izquierda izquierda
 */
template<typename Key>
void AVL<Key>::Rotation_II(NodeAVL<Key>* &nodo) {
  NodeAVL<Key>* nodo1 = reinterpret_cast<NodeAVL<Key>*&>(nodo->GetLeftSonReferenced());
  nodo->SetLeftSon(reinterpret_cast<NodeAVL<Key>*&>(nodo1->GetRightSonReferenced()));
  nodo1->SetRightSon(nodo);
  if (nodo1->GetBalance() == 1) {
    nodo->SetBal(0);
    nodo1->SetBal(0);
  } else { ///< nodo1->GetBalance() == 0
    nodo->SetBal(1);
    nodo1->SetBal(-1);
  }
  nodo = nodo1;
}

/**
 * @brief metodo encargado de realizar la Rotation derecha derecha al nodo
 * que se le pase
 * 
 * @tparam Key es el tipo de dato de los datos del arbol
 * @param nodo es el nodo a realizarle la Rotation derecha derecha
 */
template<typename Key>
void AVL<Key>::Rotation_DD(NodeAVL<Key>* &nodo) {
  NodeAVL<Key>* nodo1 = reinterpret_cast<NodeAVL<Key>*&>(nodo->GetRightSonReferenced());
  nodo->SetRightSon(reinterpret_cast<NodeAVL<Key>*&>(nodo1->GetLeftSonReferenced()));
  nodo1->SetLeftSon(nodo);
  if (nodo1->GetBalance() == -1) {
    nodo->SetBal(0);
    nodo1->SetBal(0);
  } else { ///< nodo1->GetBalance() == 0
    nodo->SetBal(-1);
    nodo1->SetBal(1);
  }
  nodo = nodo1;
}

/**
 * @brief metodo encargado de realizar la Rotation izquierda derecha al nodo
 * que se le pase
 * 
 * @tparam Key es el tipo de dato de los datos del arbol
 * @param nodo es el nodo a realizarle la Rotation izquierda derecha
 */
template<typename Key>
void AVL<Key>::Rotation_ID(NodeAVL<Key>* &nodo) {
  NodeAVL<Key>* nodo1 = reinterpret_cast<NodeAVL<Key>*&>(nodo->GetLeftSonReferenced());
  NodeAVL<Key>* nodo2 = reinterpret_cast<NodeAVL<Key>*&>(nodo1->GetRightSonReferenced());
  nodo->SetLeftSon(reinterpret_cast<NodeAVL<Key>*&>(nodo2->GetRightSonReferenced()));
  nodo2->SetRightSon(nodo);
  nodo1->SetRightSon(reinterpret_cast<NodeAVL<Key>*&>(nodo2->GetLeftSonReferenced()));
  reinterpret_cast<NodeAVL<Key>*&>(nodo2->GetLeftSonReferenced()) = nodo1;
  if (nodo2->GetBalance() == -1) nodo1->SetBal(1);
  else nodo1->SetBal(0);
  if (nodo2->GetBalance() == 1) nodo->SetBal(-1);
  else nodo->SetBal(0);
  nodo2->SetBal(0);
  nodo = nodo2;
}

/**
 * @brief metodo encargado de realizar la Rotation derecha izquierda al nodo
 * que se le pase
 * 
 * @tparam Key es el tipo de dato de los datos del arbol
 * @param nodo es el nodo a realizarle la Rotation derecha izquierda
 */
template<typename Key>
void AVL<Key>::Rotation_DI(NodeAVL<Key>* &nodo) {
  NodeAVL<Key>* nodo1 = reinterpret_cast<NodeAVL<Key>*&>(nodo->GetRightSonReferenced());
  NodeAVL<Key>* nodo2 = reinterpret_cast<NodeAVL<Key>*&>(nodo1->GetLeftSonReferenced());
  nodo->SetRightSon(reinterpret_cast<NodeAVL<Key>*&>(nodo2->GetLeftSonReferenced()));
  nodo2->SetLeftSon(nodo);
  nodo1->SetLeftSon(reinterpret_cast<NodeAVL<Key>*&>(nodo2->GetRightSonReferenced()));
  nodo2->SetRightSon(nodo1);
  if (nodo2->GetBalance() == 1) nodo1->SetBal(-1);
  else nodo1->SetBal(-1);
  if (nodo2->GetBalance() == -1) nodo->SetBal(1);
  else nodo->SetBal(0);
  nodo2->SetBal(0);
  nodo = nodo2;
}

/**
 * @brief Metodo que inserta un nodo y si el arbol se desequilibra, lo rebalancea
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param root es el nodo root del arbol
 * @param nuevo es el nodo a insertar
 * @param crece nos dice si el nodo se ha insertado correctamente
 */
template<typename Key>
void AVL<Key>::InsertBalance(NodeAVL<Key>* &root, NodeAVL<Key>* &nuevo,
                          bool& crece) {
  if (root == nullptr) {
    root = nuevo;
    crece = true;
  } else if (nuevo->GetData() < root->GetData()) {
    this->InsertBalance(reinterpret_cast<NodeAVL<Key>*&>(root->GetLeftSonReferenced()), nuevo, crece);
    if (crece) this->InsertBalanceLeft(root);
  } else if (nuevo->GetData() > root->GetData()) {
    this->InsertBalance(reinterpret_cast<NodeAVL<Key>*&>(root->GetRightSonReferenced()), nuevo, crece);
    if (crece) this->InsertBlanceRight(root);
  } else { ///< nuevo->GetData() == root->GetData()
    crece = false;
  }
}

/**
 * @brief metodo que rebalancea un nodo AVL y sus ramas a la izquierda
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo a rebalancear
 */
template<typename Key>
void AVL<Key>::InsertBalanceLeft(NodeAVL<Key>* &nodo) {
  switch (nodo->GetBalance()) {
    case -1: 
      nodo->SetBal(0);
      break;
    case 0:
      nodo->SetBal(1);
      break;
    case 1:
      if (this->traza_) {
        std::cout << "Desbalanceo:\n";
        AB<Key>* aux{this};
        std::cout << aux << "\n";
      }
      NodeAVL<Key>* nodo1 = reinterpret_cast<NodeAVL<Key>*&>(nodo->GetLeftSonReferenced());
      if (nodo1->GetBalance() == 1) {
        if (this->traza_) std::cout << "Rotation II en [" << nodo->GetData() << "]\n";
        this->Rotation_II(nodo);
      } else {
        if (this->traza_) std::cout << "Rotation ID en [" << nodo->GetData() << "]\n";
        this->Rotation_ID(nodo);
      }
  }
}

/**
 * @brief metodo que rebalancea un nodo AVL y sus ramas a la derecha
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo a rebalancear
 */
template<typename Key>
void AVL<Key>::InsertBlanceRight(NodeAVL<Key>* &nodo) {
  switch (nodo->GetBalance()) {
    case 1:
      nodo->SetBal(0);
      break;
    case 0:
      nodo->SetBal(-1);
      break;
    case -1:
      if (this->traza_) {
        std::cout << "Desbalanceo:\n";
        AB<Key>* aux{this};
        std::cout << aux << "\n";
      }
      NodeAVL<Key>* nodo1 = reinterpret_cast<NodeAVL<Key>*&>(nodo->GetRightSonReferenced());
      if (nodo1->GetBalance() == -1) {
        if (this->traza_) std::cout << "Rotation DD en [" << nodo->GetData() << "]\n";
        this->Rotation_DD(nodo);
      } else {
        if (this->traza_) std::cout << "Rotation DI en [" << nodo->GetData() << "]\n";
        this->Rotation_DI(nodo);
      }
  }
}

/**
 * @brief Metodo qu se encarga de buscar un valor concreto dentro de todos los
 * nodos del arbol AVL que cuelga del nodo "nodo" y si lo encuentra, lo borra
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es la root del arbol a comprobar el dato a borrar
 * @param data es el dato que queremos encontrar en un nodo y ese nodo lo borraremos
 * @param decrece nos dice si se ha eliminado el nodo correctamente
 */
template<typename Key>
void AVL<Key>::DeleteBranch(NodeAVL<Key>* &nodo, const Key& data, bool& decrece) {
  if (nodo == nullptr) return;
  if (data < nodo->GetData()) {
    this->DeleteBranch(reinterpret_cast<NodeAVL<Key>*&>(nodo->GetLeftSonReferenced()), data, decrece);
    if (decrece) this->DeleteReBalanceaIzda(nodo);
  } else if (data > nodo->GetData()) {
    this->DeleteBranch(reinterpret_cast<NodeAVL<Key>*&>(nodo->GetRightSonReferenced()), data, decrece);
    if (decrece) this->DeleteReBalanceaDcha(nodo);
  } else { ///< data == nodo->GetData() (encontrado)
    NodeAVL<Key>* eliminado{nodo};
    if (nodo->GetLeftSon() == nullptr) {
      nodo = reinterpret_cast<NodeAVL<Key>*&>(nodo->GetRightSonReferenced());
      decrece = true;
    } else if (nodo->GetRightSon() == nullptr) {
      nodo = reinterpret_cast<NodeAVL<Key>*&>(nodo->GetLeftSonReferenced());
      decrece = true;
    } else {
      this->Replace(eliminado, reinterpret_cast<NodeAVL<Key>*&>(nodo->GetLeftSonReferenced()), decrece);
      if (decrece) this->DeleteReBalanceaIzda(nodo);
    }
    eliminado->~NodeAVL();
    eliminado = nullptr;
  }
}

/**
 * @brief metodo encargado de reemplazar un nodo eliminado en un arbol AVL
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param eliminado el nodo a eliminar
 * @param sust el nodo que lo sustituira
 * @param decrece true si se ha eliminado el nodo
 */
template<typename Key>
void AVL<Key>::Replace(NodeAVL<Key>* &eliminado, NodeAVL<Key>* &sust, bool& decrece) {
  if (sust->GetRightSon() != nullptr) {
    this->Replace(eliminado, reinterpret_cast<NodeAVL<Key>*&>(sust->GetRightSonReferenced()), decrece);
    if (decrece) this->DeleteReBalanceaDcha(sust);
  } else {
    eliminado->SetData(sust->GetData());
    eliminado = sust;
    sust = reinterpret_cast<NodeAVL<Key>*&>(sust->GetLeftSonReferenced());
    decrece = true;
  }
}

/**
 * @brief metodo que rebalancea hacia la izquierda al borrar un nodo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo desde donde parte el rebalanceo
 * @param decrece nos dice si el arbol ha decrecido a causa del borrado del nodo
 */
template<typename Key>
void AVL<Key>::DeleteReBalanceaIzda(NodeAVL<Key>* &nodo) {
  NodeAVL<Key>* nodo1{reinterpret_cast<NodeAVL<Key>*&>(nodo->GetRightSonReferenced())};
  switch (nodo->GetBalance()) {
    case -1:
      if (nodo1->GetBalance() > 0) this->Rotation_DI(nodo);
      else {
        this->Rotation_DD(nodo);
      }
      break;
    case 0:
      nodo->SetBal(-1);
      break;
    case 1:
      nodo->SetBal(0);
      break;
  }
}

/**
 * @brief metodo que rebalancea hacia la derecha al borrar un nodo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo desde donde parte el rebalanceo
 * @param decrece nos dice si el arbol ha decrecido a causa del borrado del nodo
 */
template<typename Key>
void AVL<Key>::DeleteReBalanceaDcha(NodeAVL<Key>* &nodo) {
  NodeAVL<Key>* nodo1{reinterpret_cast<NodeAVL<Key>*&>(nodo->GetLeftSonReferenced())};
  switch (nodo->GetBalance()) {
    case 1:
      if (nodo1->GetBalance() < 0) this->Rotation_ID(nodo);
      else {
        this->Rotation_II(nodo);
      }
      break;
    case 0:
      nodo->SetBal(1);
      break;
    case -1:
      nodo->SetBal(0);
      break;
  }
}

#endif // _AVL_H_