// Clase teórica de AyED (20/02/2025)

// Ejemplo con herencia
/*
#include "vector.h"
#include <cassert>

class matrix_h : private vector{
private:
    size_t m_;
    size_t n_;
private:
    size_t pos_(const size_t i, const size_t j) const {
        assert((i >= 1) && (i <= m_) && (j >= 1) && (j <= n_));
        return (i - 1) * n_ + j - 1;
    }
    public:
    matrix_h(const size_t n, const size_t m) : vector(m*n), m_(m), n_(n) {}
    
    // Para obtener un elemento de una posición (i,j)
    double at(const size_t i, const size_t j) const {
        return vector::at(pos(i, j));
    }
    // Para modificar un elemento de una posición (i,j)
    double &at(const size_t i, const size_t j) {
        return vector::at(pos(i, j));
    }
};
*/

#include "vector.h"
#include <cassert>

namespace AyED{
    class matrix{
    private:
        vector v_;
        size_t m_;
        size_t n_;
    
    private:
        size_t pos_(const size_t i, const size_t j) const {
            assert((i >= 1) && (i <= m_) && (j >= 1) && (j <= n_));
            return (i - 1) * n_ + j - 1;
        }
    
    public:
        // Constructor por tamaño
        matrix(const size_t n, const size_t j) : v_(m*n), m_(m), n_(n) {}
        
        // Para obtener un elemento de una posición (i,j)
        double at(const size_t i, const size_t j) const {
            return v_.at(pos(i, j));
        }
        // Para modificar por referencia un elemento de una posición (i,j)
        double &at(const size_t i, const size_t j) {
            return v_.at(pos(i, j));
        
        // Método para saber si una matriz m*n es cuadrada o no 
        bool es_cuadrada() const {
            return (m_ == n_);
        }
            
        // Método para calcular la suma de los elementos de 
        // la diagonal principal de la matriz
        double suma_diagonal_principal() const {
            assert(es_cuadrada());
            double suma{0.0};
            for (size_t i{1}; i <= m*n; i++) {
                suma += at(i,i);
            }
            return suma;
        }
        
        // Método para calcular la suma de los elementos de 
        // la diagonal secundaria de la matriz
        double suma_diagonal_secundaria() const {
            assert(es_cuadrada());
            double suma{0.0};
            for (size_t i{1}; i <= m*n; i++) {
                suma += at(i, n_ - i + 1);
            }
            return suma;
        } 
    };
}

int main() {
    AyED::matrix A(5,5)
    AyED::matrix B(5,5);
    A.at(2,2) = 6.3; // A(2,2) = 6.3;
    B.at (3,2) = 3.4; // B(3,2) = 8.4;
} 
