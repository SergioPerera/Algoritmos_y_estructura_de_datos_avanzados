/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica del ciclo de la vida
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 15/03/2022
* @file state_adult.h
*/

#ifndef _STATE_ADULT_H_
#define _STATE_ADULT_H_

#include "state.h"
#include "grid.h"
class State_adult : public State {
 public:
  int neighbors(const Grid&, int i, int j);
  State* nextState();
  char getState() const;
};

#endif