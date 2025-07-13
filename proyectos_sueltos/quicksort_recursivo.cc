#include "vector_t.hpp"
#include <iostream>

int partir(vector_t<int>& vec, int ini, int fin) {
  // Inicialización
  int i = ini + 1;
  int d = fin;
  int p = vec[ini];

  while (i <= d) {
    while (i <= d && vec[i] <= p) {
      i++;
    }
    while (i <= d && vec[d] >= p) {
      d--;
    }

    if (i < d) {
      swap(vec[i], vec[d]);
      i++; d--;
    }
  }

  swap(vec[ini], vec[d]);
  return d;
}

void OR(vector_t<int>& vec, int i, int d) {
  if (i < d) {
    int pivote = partir(vec, i, d);
    OR(vec, i, pivote - 1);
    OR(vec, pivote + 1, d);
  }
}

void print_vector_t(const vector_t<int>& vec) {
  for (int i{0}; i < vec.get_size(); i++) {
    std::cout << vec.at(i) << " ";
  }
  std::cout << std::endl;
}

int main() {
  vector_t<int> vec(10);
  
  // Asignar valores
  vec.set_val(0, 4);
  vec.set_val(1, 2);
  vec.set_val(2, 5);
  vec.set_val(3, 2);
  vec.set_val(4, 6);
  vec.set_val(5, 10);
  vec.set_val(6, 3);
  vec.set_val(7, 7);
  vec.set_val(8, 6);
  vec.set_val(9, 4);

  std::cout << "Vector original: ";
  print_vector_t(vec);
  OR(vec, 0, vec.get_size() - 1);
  std::cout << std::endl;
  std::cout << "Vector ordenador (OR): ";
  print_vector_t(vec);
  
  return 0;
}
