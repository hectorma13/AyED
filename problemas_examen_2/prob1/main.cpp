/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2024-2025
  *
  * @file line_eq_t.hpp
  * @author Jorge Riera-Ledesma jriera@ull.es
  * @date Feb 8 2025
  * @brief main program to test both point_h and line_eq_t classes.
  * @bug There are no known bugs
  * @see https://github.com/RieraULL/AyED/blob/main/problemas/Problemas2.md#enunciado
  */
#include "point_t.hpp"
#include "line_eq_t.hpp"

int main(void) {
	AyED::point_t p1(3, 4);
	AyED::point_t p2(4, 3);

	AyED::line_eq_t l1(1, -1);

	std::cout << "Distancia entre la recta ";
	l1.write(std::cout);
	std::cout << " y el punto ";
	p1.write(std::cout);
	std::cout << " es ";
	std::cout << l1.distance(p1) << std::endl;

	std::cout << "Distancia entre la recta ";
	l1.write(std::cout);
	std::cout << " y el punto ";
	p2.write(std::cout);
	std::cout << " es ";
	std::cout << l1.distance(p2) << std::endl;

	return 0;
}