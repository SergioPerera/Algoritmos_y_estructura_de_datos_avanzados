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
#include <fstream> /// ofstream
typedef int state;
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
  Cell(state& initial_state, std::pair<int, int>& initial_position);

  /// Getters y setters
  state GetState() const {return state_;};
  void SetState(state& new_state) {state_ = new_state;};
  std::pair<int,int> GetPosition() {return position_;};
  
  ///Métodos
  void UpdateState(const Grid& grid);
  int NeighborsAlive(const Grid& grid);

  /// Operadores
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

 private:
  /*
  * Variable que indica el estado de la célula
  * 0: célula muerta
  * 1: célula viva
  */
  state state_{0}; 
  std::pair<int,int> position_{0,0}; /// Posición de la célula dentro de la matriz
  int neighbours_{0}; /// Número de células adyacentes a esta que están vivas
};
#endif