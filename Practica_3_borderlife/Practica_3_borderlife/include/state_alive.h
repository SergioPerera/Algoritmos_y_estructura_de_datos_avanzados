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
* @file state_alive.h
*/
#ifndef _STATE_ALIVE_H_
#define _STATE_ALIVE_H_

#include "../include/state.h"

class State_alive : public State {
 public:
  int neighbors(const Grid& grid, int i, int j) override;
  State* nextState() override;
  char getState() const override {return ('X');};
 private:
  int adult_adyacent_cells_{0};
};

#endif