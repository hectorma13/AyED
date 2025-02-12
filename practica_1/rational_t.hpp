// AUTOR: Héctor Martín Álvarez 
// FECHA: 10/02/2025
// EMAIL: alu0101714059@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1); // Constructor con parámetros
  ~rational_t() {} // Destructor
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  int get_num() const; // Método (constante) que devuelve numerador (entero)
  int get_den() const; // Método (constante) que devuelve denominador (entero)
  
  // setters
  void set_num(const int); // Método para cambiar el numerador (entero)
  void set_den(const int); // Método para cambiar el denominador (entero)

  double value(void) const; // Método que retorna el valor decimal del número racional

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const;  // Método que imprime el número racional en salida estándar
  void read(istream& = cin);          // Método que lee un número racional por entrada estándar     
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_; // Atributos (privados) de la clase, que son: numerador y denominador
};
