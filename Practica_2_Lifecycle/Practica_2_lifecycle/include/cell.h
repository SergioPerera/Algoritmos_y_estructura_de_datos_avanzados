/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica del juego de la vida
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 24/02/2022
* @file cell.h
*/

#ifndef _CELL_H_
#define _CELL_H_

#include "grid.h"
#include "state.h"
#include <fstream> /// ofstream

class Grid;
/**
 * @brief Clase encargada de crear objetos cell que tienen distintos estados y 
 * distintas posiciones iniciales. Estos objetos tienen la propiedad de cambiar
 * en función de los objetos alrededor de ellos
 */
class Cell {

 public:

  /// Constructor
  Cell(){};
  Cell(State* initial_state, std::pair<int, int>& initial_position);

  /// Getters y setters
  State* GetState() const {return state_;};
  void SetState(State* new_state) {state_ = new_state;};
  std::pair<int,int> GetPosition() {return position_;};

  ///Métodos
  void UpdateState();
  int NeighborsAlive(const Grid& grid);

  /// Operadores
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

 private:
  /*
  * Variable que indica el estado de la célula
  * ' ': célula muerta
  * H : Huevo
  * L : Larva
  * P : Pupa
  * A : Adulta
  */
  State* state_;
  std::pair<int,int> position_{0,0}; /// Posición de la célula dentro de la matriz
  int neighbours_{0}; /// Número de células adyacentes a esta que están vivas
};
#endif