/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2024-2025
  *
  * @file line_eq_t.hpp
  * @author Héctor Martín Álvarez alu0101714059@ull.edu.es
  * @date Feb 8 2025
  * @brief a class that represents a linear equation in the Cartesian plane.
  * @bug There are no known bugs
  * @see https://github.com/RieraULL/AyED/blob/main/problemas/Problemas2.md#enunciado
  */
#pragma once

#include "point_t.hpp"
#include <iostream>

namespace AyED {
  /**
   * @brief Represents a linear equation in the Cartesian plane.
   */
  class line_eq_t {
    public:
      /**
       * @brief Default constructor.
       * Initializes the y-intercept (b_term_) and slope (slope_) to 0.
       */
      line_eq_t() : b_term_{0}, slope_{0} {}
      /**
       * @brief Constructs a line equation with the given y-intercept and slope.
       * @param b_term The y-intercept of the line.
       * @param slope The slope of the line.
       */
      line_eq_t(double b_term, double slope) {
        this->b_term_ = b_term;
        this->slope_ = slope;
      }
      /**
       * @brief Constructs a line equation from two points in the Cartesian plane.
       * @param point_1 The first point.
       * @param point_2 The second point.
       */
      line_eq_t(const point_t& point_1, const point_t& point_2) : 
        b_term_{0}, slope_{0} {
          slope_ = (point_2.get_y() - point_1.get_y()) - (point_2.get_x() - point_1.get_x());
          b_term_ = - slope_ * point_1.get_x() + point_1.get_y();
        }
      /**
       * @brief Destructor.
       */
      ~line_eq_t(void) {}
      /**
       * @brief Gets the y-intercept of the line.
       * @return The y-intercept of the line.
       */
      double get_b_term() const { return b_term_; }
      /**
       * @brief Gets the slope of the line.
       * @return The slope of the line.
       */
      double get_slope() const { return slope_; }
      /**
       * @brief Sets the y-intercept and slope of the line.
       * @param b_term The new y-intercept of the line.
       * @param slope The new slope of the line.
       */
      void set(double b_term, double slope) {
        this->b_term_ = b_term;
        this->slope_ = slope;
      }
      /**
       * @brief Writes the equation of the line to the given output stream.
       * @param os The output stream to write the equation to.
       */
      void write(std::ostream& os) {
        os << "y = " << this->slope_ << "x + " << this->b_term_;
      }
      /**
       * @brief Calculates the distance from a point to the line.
       * @param point The point to calculate the distance from.
       * @return The distance from the point to the line.
       */
      double distance(const point_t& point) const {
        return fabs(slope_ * point.get_x() - point.get_y() + b_term_)/ 
               sqrt(slope_ * slope_ + 1);
      }
    private:
      double b_term_;
      double slope_;
  };
}
