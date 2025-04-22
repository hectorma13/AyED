// AUTOR: Héctor Martín Álvarez
// FECHA: 22/04/2025
// EMAIL: alu0101714059@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

  // MODIFICACIÓN
  int no_conmutativos() const;

 private: 
  T stack_;
  void operate_(const char operador);
  int no_conmutativos_{0};
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/'||
         c == '^' || c == 'r' || c == 'l' || c == 'c');

  int op1{0}, op2{0}, resultado{0};

  // Operadores de ARIDAD DOS
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    op2 = stack_.top();
    stack_.pop();
    std::cout << "Sacamos de la pila un operando: " << op2 << std::endl;

    op1 = stack_.top();
    stack_.pop();
    std::cout << "Sacamos de la pila otro operando: " << op1 << std::endl;
  
    // Operadores de ARIDAD UNO (UNARIOS)
  } else {
    op1 = stack_.top();
    stack_.pop();
    std::cout << "Sacamos de la pila un operando: " << op2 << std::endl;
  }
  
  switch (c) {
    case '+':
      resultado = op1 + op2;
      break;
    case '-':
      ++no_conmutativos_;
      resultado = op1 - op2;
      break;
    case '*':
      resultado = op1 * op2;
      break;
    case '/':
      ++no_conmutativos_;
      resultado = op1 / op2;
      break;
    case '^':
      ++no_conmutativos_;
      resultado = pow(op1, op2);
      break;
    case 'r':
      resultado = sqrt(op1);
      break;
    case 'l':
      resultado = log2(op1);
      break;
    case 'c':
      resultado = pow(op1, 2);
      break;
  }

  stack_.push(resultado);
  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
}

// No conmutativos (- / ^)
template <class T> int rpn_t<T>::no_conmutativos() const {
  return no_conmutativos_;
}

 
#endif  // RPNT_H_
