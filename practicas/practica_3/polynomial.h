// AUTOR: Héctor Martín Álvarez
// FECHA: 18/03/2025
// EMAIL: alu0101714059@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:


#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  // Modificación Lunes
  Polynomial IsGreaterThan(const double value) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  // MODIFICACIÓN
  int SumOfDegrees() const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  //double result{0.0};
  //for (int i{0}; i < get_size(); i++) {
  //  if (IsNotZero(at(i))) {
  //    result = result + at(i) * pow(x, i);
  //  }
  //}
  //return result;

  // Convertimos a polinomio disperso y usamos dicho método Eval()
  SparsePolynomial polinomio_disperso(*this);
  return polinomio_disperso.Eval(x);
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  // Convertimos el polinomio actual a polinomio disperso
  SparsePolynomial this_polynomial(*this);
  // Lo mismo con el polinomio que pasamos cómo argumento
  SparsePolynomial arg_polynomial(pol);
  // Utilizamos el método IsEqual que compara polinomios dispersos
  // Así eliminamos ceros, los cuáles pueden crear fallos al compararlos
  return (this_polynomial.IsEqual(arg_polynomial, eps));
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int i{0}; i < get_nz(); i++) {
    result = result + at(i).get_val() * pow(x, at(i).get_inx());
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol
			       , const double eps) const {
  bool differents = false;
  // Si los tamaños de los polinomios dispersos no coinciden, son distintos
  if (get_nz() != spol.get_nz()) {
    return false;
  }
  // Recorremos los dos polinomios (tienen igual tamaño) de delante a atrás
  for (int i{0}; i < get_nz(); i++) {
    // Siendo {valor, posicion_original} nuestro polinomio:
    // Si el valor o la posición original de ambos son diferentes, no son iguales
    if (at(i).get_inx() != spol.at(i).get_inx() ||
        fabs(at(i).get_val() - spol.at(i).get_val()) > eps) {
      differents = true;
      break;
    }
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  // Convertimos nuestro polinomio a polinomio disperso y utilizamos
  // el método de comparación entre polinomios dispersos
  SparsePolynomial polinomio_convertido(pol);
  return IsEqual(polinomio_convertido, eps);
}

// MODIFICACIÓN
int SparsePolynomial::SumOfDegrees() const {
  // Inicializo la variable que contendrá la suma de los
  // grados de los monomios que cumplan la condición
  int resultado{0};
  // Recorro el polinomio disperso desde su inicio hasta
  // su final (nz_)
  for (int i{0}; i < get_nz(); i++) {
    // Comprueba si el coeficiente es mayor que 5 y menor que 9
    if (at(i).get_val() > 5 && at(i).get_val() < 9) {
      // En caso afirmativo, lo que hace el programa es
      // sumar el grado de dicho monomio
      resultado += at(i).get_inx();
    }
  }
  // Devuelve, por último, la suma de todos los grados de los monomios
  // que cumplen la condición dada
  return resultado;
}

#endif  // POLYNOMIAL_H_
