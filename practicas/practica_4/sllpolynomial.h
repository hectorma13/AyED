// AUTOR: Héctor Martín Álvarez
// FECHA: 01/04/2025
// EMAIL: alu0101714059@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

// Es simplemente un par de dobles: {double, double}
typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial

// Es un nodo qué, cómo dato, almacena un par de dobles
// Es sll_node_t<pair_t<double>>
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);

  // Modificación
  SllPolynomial GetOddDegreeTerms() const;
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) { 

  //Recorro el vector v desde atrás hacia adelante completamente
  // El motivo de que vaya de mayor a menor es porque insertaremos los nodos
  // en la SLL por el frente, entonces los coeficientes de mayor grado
  // deben ir más alejados del principio de la SLL para seguir el orden
  // natural de un polinomio (de izq. a derecha)
  for (int i{v.get_size() - 1}; i >= 0 ; i--) {
    // Si alguno de sus elementos es != 0, hago lo siguiente
    if (IsNotZero(v.at(i))) {
      // Creo un par de dobles que contenga el coeficiente (!= 0) y su grado
      pair_double_t par(v.at(i), i);
      // Creo, mediante memoria dinámica, un objeto SllPolyNode que creará
      // un nodo con los datos del par que he creado antes
      SllPolyNode* nuevo = new SllPolyNode(par);
      // Inserto en el frente de la lista enlazada el nodo que acabo de crear
      push_front(nuevo);
    }
  }
}


// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  
  // Creo la variable que almacenará el resultado
  double result{0.0};
  // Creo un puntero que apunta a donde lo hace head_
  SllPolyNode* aux = this->get_head();
  // Mientras el nodo auxiliar sea diferente de un puntero nulo:
  while (aux != nullptr) {
    // Añado al resultado la evaluación para el nodo al que apunta aux
    // Para ello, utilizo la expresión: coeficiente * x ^ grado
    result += (aux->get_data().get_val() * pow(x, aux->get_data().get_inx()));
    // Actualizo el nodo auxiliar, apuntando ahora al siguiente
    aux = aux->get_next();
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
			    const double eps) const {

  // Creo la variable que nos dirá si los polinomios son iguales o no
  bool differents = false;
  
  // Creo dos punteros que apuntan a los primeros nodos de ambas SLL
  SllPolyNode* this_node = this->get_head();
  SllPolyNode* sllpol_node = sllpol.get_head();

  // Mientras sean iguales y ambos nodos sean diferentes de uno nulo:
  while (differents == false && this_node != nullptr && sllpol_node != nullptr) {
    // Creo 4 variables para simplificar luego las condiciones, estas son:
    // Dos variables que contienen el coeficiente de su respectivo nodo
    // Dos variables que contienen el grado de su respectivo nodo
    double this_val = this_node->get_data().get_val();
    double sllpol_val = sllpol_node->get_data().get_val();
    double this_inx = this_node->get_data().get_inx();
    double sllpol_inx = sllpol_node->get_data().get_inx();

    // Ahora, compruebo si, tanto los coeficientes cómo los grados son iguales
    // Utilizo eps cómo "error permitido" para comparar doubles (prec. doble)
    if (fabs(this_val - sllpol_val) > eps || fabs(this_inx - sllpol_inx) > eps) {
      // Si alguna de las operaciones es mayor que eps, entonces tenemos que
      // los polinomios son diferentes
      differents = true;
    }

    // Si differents = true; este paso no importa
    // Actualizo los nodos, haciendo que se apunte a los siguientes de los que
    // había evaluado (hasta llegar a nullptr, que es condición del while)
    this_node = this_node->get_next();
    sllpol_node = sllpol_node->get_next();
  }
  // Devuelvo lo contrario a differents, porque el método responde a la pregunta:
  // ¿Son estos dos polinomios iguales? Si la respuesta es sí, no son diferentes
  return !differents; 
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol,
			SllPolynomial& sllpolsum,
			const double eps) {

  // Creo dos objetos para recorrer los dos polinomios desde head_ hasta null
  SllPolyNode* this_node = this->get_head();
  SllPolyNode* sllpol_node = sllpol.get_head();

  int this_max_grado{0};
  int sllpol_max_grado{0};

  while (this_node != nullptr) {
    this_max_grado = this_node->get_data().get_inx();
    this_node = this_node->get_next();
  }
  while (sllpol_node != nullptr) {
    sllpol_max_grado = sllpol_node->get_data().get_inx();
    sllpol_node = sllpol_node->get_next();
  }

  this_node = this->get_head();
  sllpol_node = sllpol.get_head();
  int max_grado = this_max_grado > sllpol_max_grado ? this_max_grado : sllpol_max_grado;
  vector_t<double> suma_coeficientes(max_grado + 1);

  while (this_node != nullptr) {
    suma_coeficientes[int(this_node->get_data().get_inx())] = this_node->get_data().get_val();
    this_node = this_node->get_next();
  }
  while (sllpol_node != nullptr) {
    suma_coeficientes[sllpol_node->get_data().get_inx()] = (
      suma_coeficientes[int(sllpol_node->get_data().get_inx())] + sllpol_node->get_data().get_val());

    sllpol_node = sllpol_node->get_next();
  }

  for (int i{suma_coeficientes.get_size() - 1}; i >= 0; i--) {
    if (IsNotZero(suma_coeficientes.at(i), eps)) {
      pair_double_t par(suma_coeficientes.at(i), i);
      sllpolsum.push_front(new SllPolyNode(par));
    }
  }
}

// Modificación
SllPolynomial SllPolynomial::GetOddDegreeTerms() const {
  
  // Creo el polinomio que contendrá el resultado del método
  SllPolynomial resultado;

  // Creo dos nodos para polinomios
  SllPolyNode* actual = this->get_head();
  SllPolyNode* ultimo;

  // Itero el polinomio actual (el invocante) desde su inicio hasta su fin
  while (actual != nullptr) {

    // Si el grado del nodo actual es impar:
    if (actual->get_data().get_inx() % 2 != 0) {
    
      pair_double_t par(actual->get_data().get_val(), actual->get_data().get_inx());
      SllPolyNode* nuevo = new SllPolyNode(par);
      
      if (resultado.get_head() == nullptr) {
        resultado.push_front(nuevo);
      } else {
        resultado.insert_after(ultimo, nuevo);
      }

      ultimo = nuevo;
    } 

    actual = actual->get_next();
  }

  // Devuelvo el resultado
  return resultado;
}

#endif  // SLLPOLYNOMIAL_H_
