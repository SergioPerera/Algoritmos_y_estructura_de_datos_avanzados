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
* @file state_larva.h
*/
#ifndef _STATE_LARVA_H_
#define _STATE_LARVA_H_


#include "state.h"
#include "grid.h"
class State_larva : public State {
 public:
  int neighbors(const Grid&, int i, int j) override;
  State* nextState() override;
  char getState() const override {return ('L');};
 private:
  int larvas_{0};
  int eggs_{0};
  int adults_{0};
  int pupas_{0};
};

#endif