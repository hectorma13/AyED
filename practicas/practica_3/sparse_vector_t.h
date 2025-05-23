// AUTOR: Héctor Martín Álvarez
// FECHA: 18/03/2025
// EMAIL: alu0101714059@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t; // vector_t<pair_t<double>>

class sparse_vector_t {
 public:
  // constructores
  sparse_vector_t(const int = 0);
  sparse_vector_t(const vector_t<double>&,
		  const double = EPS); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia

  // operador de asignación
  sparse_vector_t& operator=(const sparse_vector_t&);

  // destructor
  ~sparse_vector_t();
  
  // getters
  int get_nz(void) const;
  int get_n(void) const;

  // getters-setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);
  
  // getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;

  // E/S
  void write(std::ostream& = std::cout) const;

 private:
  pair_vector_t pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  // bool IsNotZero(const double, const double = EPS) const;
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps)
    : pv_(), nz_(0), n_(0) {
  // Asigno a n_ el tamaño del vector original (el denso), cómo corresponde
  this->n_ = v.get_size();
  // Recorro el vector denso de principio a fin en busca de elementos
  // diferentes de cero para contar cuántos hay (lo almaceno en nz_)
  // iteración a iteración
  for (int i{0}; i < n_; i++) {
    if (IsNotZero(v[i])) {
      nz_++;
    }
  }
  // pv_ es al fin y al cabo un vector, entonces, cómo al principio está
  // nulo, ahora, cómo se sabe su tamaño, lo redimensiono
  pv_.resize(nz_);
  // Igualo el número de elementos distintos de cero (nz_) a cero para
  // utilizarlo cómo índice en el siguiente bucle for
  // pd: podría ser otra variable, pero volverá a valer lo mismo que
  // antes, así que utilizo la misma (eficiencia)
  nz_ = 0;
  // El bucle, de nuevo, recorrerá el vector denso de inicio a fin
  // Lo hace para añadir al vector de pares pv_ los valores != 0 y
  // sus índices en el vector original (segundo valor del par)
  // al que se accederá con get_inx() después;
  for (int i{0}; i < n_; i++) {
    if (IsNotZero(v[i])) {
      // Si el valor != 0, lo meto en el vector de pares
      // junto con su índice i
      // No se puede usar pv_[i] porque habrían posiciones vacías
      // por eso igualé nz_ a cero, aunque podría ser 
      pv_[nz_].set(v[i], i);
      nz_++;
    }
  }
}

// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // se invoca directamente al operator=
}

// operador de asignación
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}

sparse_vector_t::~sparse_vector_t() {}

inline int sparse_vector_t::get_nz() const {
  return nz_;
}

inline int sparse_vector_t::get_n() const {
  return n_;
}

pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

pair_double_t& sparse_vector_t::operator[](const int i) {
  return at(i);
}

const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

const pair_double_t& sparse_vector_t::operator[](const int i) const {
  return at(i);
}

// E/S
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_
