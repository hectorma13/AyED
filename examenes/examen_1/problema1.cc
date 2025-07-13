/*
 Universidad de La Laguna
 Escuela Superior de Ingeniería y Tecnología
 Grado en Ingeniería Informática
 Algoritmos y Estructuras de Datos 2024-2025

 @file ejercicio1.cc
 @author Héctor Martín Álvarez alu0101714059@ull.edu.es
 @date 05/02/2025
 @brief A program that computes the scalar product of two randomly generated vectors and 
        displays the result with formatted output.
 @bug There are no bugs
 @see https://github.com/RieraULL/AyED/tree/main
*/
#include <iostream> // Input/Output stream library
#include <cstdlib> // To generate random numbers
#include <iomanip> // Output formatting library

// Preprocessor directives
#define MAX_SZ 10
#define MAX_VAL 50

// Function that computes scalar product
int scal_prod(int v1[], int v2[], int sz) {
  int result{0};
  for (int i{0}; i < sz; ++i) {
    result += (v1[i] * v2[i]);
  }
  return result;
}
// Our main function
int main(void) {
  int v1[MAX_SZ], v2[MAX_SZ]; // Create the vectors we're going to use

  // We fill the vectors with random values
  srand(time(0));
  for (int i{0}; i < MAX_SZ; i++) {
    v1[i] = rand() % (2 * (MAX_VAL + 1)) - MAX_VAL;
    v2[i] = rand() % (2 * (MAX_VAL + 1)) - MAX_VAL;
  }
  // Show the elements of the vectors
  for (int i{0}; i < MAX_SZ; i++) {
    std::cout << std::setw(4) << v1[i];
  }
  std::cout << "\n";
  for (int i{0}; i < MAX_SZ; i++) {
    std::cout << std::setw(4) << v2[i];
  }
  std::cout << "\n";
  // Compute and show the scalar product
  std::cout << "v1 * v2 = " << scal_prod(v1, v2, MAX_SZ) << std::endl;
}
