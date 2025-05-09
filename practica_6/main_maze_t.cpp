// AUTOR: Héctor Martín Álvarez
// FECHA: 05/05/2025
// EMAIL: alu0101714059@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// Se compila con:
// g++ main_maze_t.cpp maze_t.cpp -o main_maze_t

#include <iostream>
#include "maze_t.hpp"

using namespace std;

int main()
{ 
  maze_t M;
  queue_l_t<pair_t<int>> solucion;

  cin >> M;
  
  cout << M << endl;
  
  if (M.solve(solucion)) { 
    cout << "¡¡ Se ha encontrado una salida al laberinto !!" << endl;
    cout << M << endl;
    cout << solucion << endl;
    cout << "Se han realizado " << M.south_movements(solucion) << " movimientos al sur." << endl;
  }
  else
    cout << "No se ha podido encontrar la salida del laberinto..." << endl;
  
  return 1;
}