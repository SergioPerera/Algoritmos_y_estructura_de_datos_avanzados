/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica hashtable
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 7/04/2022
* @file sequence.cc
*/

#ifndef _VEHICLE_
#define _VEHICLE_
#include <string>

class Vehicle {
  public:
  Vehicle() {};
  void SetMatNum(int n) {matricule_num_ = n;}
  void SetMatLet(std::string letters) {matricule_let_ = letters;}
  int GetMatNum() {return matricule_num_;};
  std::string GetMatLet() {return matricule_let_;};
  private:
  int matricule_num_{0};
  std::string matricule_let_;
};

#endif
