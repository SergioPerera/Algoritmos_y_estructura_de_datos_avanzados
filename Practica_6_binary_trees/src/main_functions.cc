/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica: Árbol binario equilibrado
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 10/05/2022
* @file main_functions.cc
*/

#include "../include/main_functions.h"

#include <iostream>
void PrintMenu() {
  std::cout << "\n[0] Salir" 
            << "\n[1] Insertar"
            << "\n[2] Buscar clave"
            << "\n[3] Mostrar árbol inorden"
            << GREEN << "\n>>>>> ";
}