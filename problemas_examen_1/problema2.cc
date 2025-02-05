/*
 Universidad de La Laguna
 Escuela Superior de Ingeniería y Tecnología
 Grado en Ingeniería Informática
 Algoritmos y Estructuras de Datos 2024-2025

 @file ejercicio2.cc
 @author Héctor Martín Álvarez alu0101714059@ull.edu.es
 @date 05/02/2025
 @brief a program that counts values close to a value within specified tolerances.
 @bug There are no known bugs.
 @see https://github.com/RieraULL/AyED/blob/main/problemas/Problemas1.md#problema-2
*/
#include <iostream>
#include <cmath>
// Preprocessor directives
#define MAX_SZ 9
#define MAX_VAL 2

// Function to count ocurrences based on a tolerance value
int count_eq(double v[], int sz, double val, double tol) {
  int count{0};
  for (int i{0}; i < sz; i++) {
    if ((fabs(v[i] - val)) < tol) {
      count++;
    }
  }
  return count;
}
// Program main function
int main() {
  // Solution test case
  double v1[MAX_SZ] = {0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1};
  // Multiple function test cases
  std::cout << "1E-4 Tolerance: " << count_eq(v1, MAX_SZ, 1.0, 1E-4) << std::endl;
  std::cout << "1E-3 Tolerance: " << count_eq(v1, MAX_SZ, 1.0, 1E-3) << std::endl;
  std::cout << "1E-2 Tolerance: " << count_eq(v1, MAX_SZ, 1.0, 1E-2) << std::endl;
  std::cout << "1E-1 Tolerance: " << count_eq(v1, MAX_SZ, 1.0, 1E-1) << std::endl;
  return 0;
}
