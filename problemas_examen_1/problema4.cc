/*
 Universidad de La Laguna
 Escuela Superior de Ingeniería y Tecnología
 Grado en Ingeniería Informática
 Algoritmos y Estructuras de Datos 2024-2025

 @file problema4.cc
 @author Héctor Martín Álvarez alu0101714059@ull.edu.es
 @date 05/02/2025
 @brief a program that sum elements and count even/odd numbers in an array
 @bug There are no known bugs.
 @see https://github.com/RieraULL/AyED/blob/main/problemas/Problemas1.md
*/
#include <iostream>
#define MAX_SZ 10

int suma(int v[], int sz) {
  int suma{0};
  for (int i{0}; i < sz; ++i) {
    suma += v[i]; 
  }
  return suma;
}
int cont_pair(int v[], int sz) {
  int counter{0};
  for (int i{0}; i < sz; ++i) {
    if (v[i] % 2 == 0) { ++counter; }
  }
  return counter;
}
int cont_odd(int v[], int sz) {
  int counter{0};
  for (int i{0}; i < sz; ++i) {
    if (v[i] % 2 != 0) { ++counter; }
  }
  return counter;
}
int main() {
  int v[MAX_SZ] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << "Suma: " << suma(v, MAX_SZ) << "\n";
	std::cout << "Pares: " << cont_pair(v, MAX_SZ) << "\n";
	std::cout << "Impares: " << cont_odd(v, MAX_SZ) << "\n";
}
