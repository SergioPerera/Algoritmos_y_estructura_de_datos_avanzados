/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoitmos y estructura de datos avanzadas
* Curso: 2º
* Práctica hashtable
* @author Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* @date 26/04/2022
* @file function_templates.h
*/

template<typename T>
T Selection(std::vector<T>& v) {
  int min;
  int x;
  for (int i = 0; i < v.size()-1; i++){
    min = i ;
    for (int j = i+1; j < v.size(); j++) 
    if (v[j] < v[min]) {
      min = j ;
      x = v[min] ;
    }
    v[min] = v[i] ;
    v[i] = x ;
  }
}
