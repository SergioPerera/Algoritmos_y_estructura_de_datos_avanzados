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

/**
 * @brief Clase encargada de crear objetos cell que tienen distintos estados y 
 * distintas posiciones iniciales. Estos objetos tienen la propiedad de cambiar
 * en función de los objetos alrededor de ellos
 */
class Cell {

 public:

  /// Constructor
  Cell(state& initial_state, std::pair<int, int> initial_position);

  /// Getters y setters
  state GetState() const {return state_;};
  void SetState(state& new_state) {state_ = new_state;};

  ///Métodos
  void UpdateState(const Grid& grid);
  int NeighborsAlive(const Grid& grid);

  /// Operadores
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

 private:
  state state_{0}; /// Variable que indica el estado de la célula
  std::pair<int,int> position_; /// Posición de la célula dentro de la matriz
  int neighbours{0}; /// Número de células adyacentes a esta que están vivas
};
#endif