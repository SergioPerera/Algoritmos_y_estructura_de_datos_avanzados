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
* @file state.h
*/
#ifndef _STATE_H_
#define _STATE_H_

#include "grid.h"
#include <set> /// std::set
class Grid;
/*
* Esta clase abstracta la vamos a usar para poder invocar los métodos comunes
* a las demas clases hijas
*/
class State {
 public:
  virtual int neighbors(const Grid&, int i, int j)=0;
  virtual State* nextState()=0;
  virtual char getState() const =0;
};

#endif /// _STATE_H_