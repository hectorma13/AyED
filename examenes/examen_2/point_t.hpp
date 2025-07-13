/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2024-2025
  *
  * @file point_h.hpp
  * @author Héctor Martín Álvarez alu0101714059@ull.edu.es
  * @date Feb 8 2025
  * @brief a class that represents a 2D point.
  * @bug There are no known bugs
  * @see https://github.com/RieraULL/AyED/blob/main/problemas/Problemas2.md#enunciado
  */
#pragma once
#include <iostream>
#include <cmath>

namespace AyED {

  /**
   * @brief Represents a 2D point.
   */
  class point_t {
    public:
      /**
       * @brief Default constructor. Initializes the point to (0, 0).
       */
      point_t() : x_{0}, y_{0} {}
      /**
       * @brief Constructs a point with the given coordinates.
       * @param x The x-coordinate of the point.
       * @param y The y-coordinate of the point.
       */
      point_t(double x, double y) : x_{x}, y_{y} {}
      /**
       * @brief Destructor.
       */
      ~point_t() {}
      /**
       * @brief Gets the x-coordinate of the point.
       * @return The x-coordinate of the point.
       */
      double get_x() const { return x_; }

      /**
       * @brief Gets the y-coordinate of the point.
       * @return The y-coordinate of the point.
       */
      double get_y() const { return y_; }
      /**
       * @brief Sets the coordinates of the point.
       * @param x The new x-coordinate of the point.
       * @param y The new y-coordinate of the point.
       */
      void set_point(double x, double y) {
        this->x_ = x;
        this->y_ = y;
      }
      /**
       * @brief Writes the point to the given output stream.
       * @param os The output stream to write the point to.
       */
      void write(std::ostream& os) const {
        os << "(" << x_ << ", " << y_ << ")";
      }
      /**
       * @brief Calculates the Euclidean distance between this point and another point.
       * @param point The other point to calculate the distance to.
       * @return The Euclidean distance between this point and the other point.
       */
      double euclidean_distance(const point_t& point) {
        return sqrt((point.x_ - this->x_) * (point.x_ - this->x_)
                  + (point.y_ - this->y_) * (point.y_ - this->y_));
      }
      /**
       * @brief Calculates the Manhattan distance between this point and another point.
       * @param point The other point to calculate the distance to.
       * @return The Manhattan distance between this point and the other point.
       */
      double manhattan_distance(const point_t& point) {
        return fabs(point.x_ - this->x_) + fabs(point.y_ - this->y_);
      }
    private:
      double x_;
      double y_;
  };
}