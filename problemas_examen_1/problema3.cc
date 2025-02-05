/*
 Universidad de La Laguna
 Escuela Superior de Ingeniería y Tecnología
 Grado en Ingeniería Informática
 Algoritmos y Estructuras de Datos 2024-2025

 @file problema3.cc
 @author Héctor Martín Álvarez alu0101714059@ull.edu.es
 @date 05/02/2025
 @brief a program that count elements less or greater than a value with tolerance
 @bug There are no known bugs.
 @see https://github.com/RieraULL/AyED/blob/main/problemas/Problemas1.md
*/
#include <iostream>

#define MAX_SZ 9
#define MAX_VL 

int count_less(double v[], int sz, double val, double tol) {
  int counter{0};
  for (int i{0}; i < sz; ++i) {
    if (val - v[i] > tol) {
      ++counter;
    }
  }
  return counter;
}
int count_great(double v[], int sz, double val, double tol) {
  int counter{0};
  for (int i{0}; i < sz; ++i) {
    if (v[i] - val > tol) {
      ++counter;
    }
  }
  return counter;
}

int main() {
  double v[MAX_SZ] = {0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1};
  // We call the count_less() function
  std::cout << "LESS: " << "\n";
  std::cout << count_less(v, MAX_SZ, 1.0, 1E-4) << "\n";
  std::cout << count_less(v, MAX_SZ, 1.0, 1E-3) << "\n";
  std::cout << count_less(v, MAX_SZ, 1.0, 1E-2) << "\n";
  std::cout << count_less(v, MAX_SZ, 1.0, 1E-1) << "\n";
  std::cout << "\n";
  // We call the count_great() function
  std::cout << "GREAT: " << "\n";
  std::cout << count_great(v, MAX_SZ, 1.0, 1E-4) << "\n";
  std::cout << count_great(v, MAX_SZ, 1.0, 1E-3) << "\n";
  std::cout << count_great(v, MAX_SZ, 1.0, 1E-2) << "\n";
  std::cout << count_great(v, MAX_SZ, 1.0, 1E-1) << "\n";
}
