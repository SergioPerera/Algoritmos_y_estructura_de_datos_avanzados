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
* @file state_dead.cc
*/

#include "../include/state_dead.h"
#include "../include/grid.h"
#include "../include/state.h"
#include "../include/state_egg.h"
#include "../include/state_larva.h"
#include "../include/state_adult.h"
#include "../include/state_dead.h"
#include "../include/state_pupa.h"


int State_dead::neighbors(const Grid& grid, int x, int y) {
  // for (int i : {-1, 0, 1}) {
  //   for (int j : {-1, 0, 1}) {
  //     if ((x != x + i) || (y != y + j)) {
  //       if (grid.GetCell(x,y).GetState()->getState() == 'A'){
  //         dead_adyacent_cells_++;
  //       }
  //     }
  //   }
  // }
}
