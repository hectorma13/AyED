/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2024-2025
  *
  * @file matrices.cpp
  * @author Héctor Martín Álvarez alu0101714059@ull.edu.es
  * @date 20/02/2025
  * @brief Desarrollo de la clase matriz a partir de una clase vector,
  *        pues una matriz puede ser expresada como un vector unidimensional.  
  * @bug No hay bugs conocidos
  * @see https://github.com/RieraULL/AyED/tree/main/Temario/Tema2/matrices
  */

#include <cassert>
#include <iostream>
#include <iomanip>

namespace AyED {

  // Clase vector
  /**
   * @brief Clase que representa un vector dinámico de enteros.
   * 
   * Esta clase permite crear un vector de enteros de tamaño dinámico,
   * acceder a sus elementos y gestionar la memoria de manera adecuada.
   */
  class vector {
   public:
    /**
     * @brief Constructor de la clase vector.
     * 
     * Este constructor inicializa el vector con un tamaño dado y
     * llama al método `build()` para asignar memoria para el array.
     * 
     * @param sz Tamaño del vector.
     */
    vector(const int sz) : v_{nullptr}, sz_{sz} {
      build();
    }

    /**
     * @brief Destructor de la clase vector.
     * 
     * Este destructor llama al método `destroy()` para liberar la
     * memoria asignada al array de enteros.
     */
    ~vector() {
      destroy();
    }

    /**
     * @brief Obtiene el tamaño del vector.
     * 
     * @return El tamaño del vector.
     */
    int get_size() const { return sz_; }

    /**
     * @brief Accede a un elemento del vector (no constante).
     * 
     * Este método permite acceder y modificar un elemento del vector
     * en la posición especificada. Se asegura de que la posición sea
     * válida mediante una aserción.
     * 
     * @param pos Posición del elemento a acceder.
     * @return Referencia al elemento en la posición especificada.
     */
    int &at(const int pos) {
      assert(pos >= 0 && pos < sz_);
      return v_[pos];
    }

    /**
     * @brief Accede a un elemento del vector (constante).
     * 
     * Este método permite acceder a un elemento del vector en la
     * posición especificada sin modificarlo. Se asegura de que la
     * posición sea válida mediante una aserción.
     * 
     * @param pos Posición del elemento a acceder.
     * @return El elemento en la posición especificada.
     */
    int at(const int pos) const {
      assert(pos >= 0 && pos < sz_);
      return v_[pos];
    }
   
   private:
   /**
    * @brief Asigna memoria para un array de enteros.
    * 
    * Este método inicializa la variable miembro `v_` asignando
    * un array de enteros del tamaño `sz_`. Debe ser llamado antes
    * de usar el array para asegurar que la memoria esté correctamente
    * asignada.
    */
   void build() {
       v_ = new int[sz_];
   }

   /**
    * @brief Libera la memoria del array de enteros.
    * 
    * Este método verifica si la variable miembro `v_` no es un puntero nulo,
    * y si es así, libera la memoria asignada para el array. Después
    * de la liberación, establece `v_` a nullptr para evitar punteros colgantes.
    */
   void destroy() {
       if (v_ != nullptr) {
           delete[] v_;
           v_ = nullptr;
       } 
   }

   /// Puntero a un array de enteros.
   int *v_;

   /// Tamaño del array de enteros.
   int sz_;
  };

  // Clase matrix
  /**
   * @brief Clase que representa una matriz de enteros.
   * 
   * Esta clase permite crear una matriz de enteros de tamaño dinámico,
   * acceder a sus elementos y realizar operaciones básicas como suma y producto.
   */
  class matrix {
   public:
    /**
     * @brief Constructor de la clase matrix.
     * 
     * Este constructor inicializa la matriz con un número de filas y columnas dado.
     * 
     * @param m Número de filas.
     * @param n Número de columnas.
     */
    matrix(int m, int n) : v_{m * n}, m_{m}, n_{n} {}

    /**
     * @brief Destructor de la clase matrix.
     */
    ~matrix() {};

    /**
     * @brief Obtiene el número de filas de la matriz.
     * 
     * @return El número de filas.
     */
    int get_m() const { return m_; }

    /**
     * @brief Obtiene el número de columnas de la matriz.
     * 
     * @return El número de columnas.
     */
    int get_n() const { return n_; }

    /**
     * @brief Accede a un elemento de la matriz (no constante).
     * 
     * Este método permite acceder y modificar un elemento de la matriz
     * en la posición especificada.
     * 
     * @param i Fila del elemento a acceder.
     * @param j Columna del elemento a acceder.
     * @return Referencia al elemento en la posición especificada.
     */
    int &at(const int i, const int j) {
      return v_.at(pos(i,j));
    }

    /**
     * @brief Accede a un elemento de la matriz (constante).
     * 
     * Este método permite acceder a un elemento de la matriz en la
     * posición especificada sin modificarlo.
     * 
     * @param i Fila del elemento a acceder.
     * @param j Columna del elemento a acceder.
     * @return El elemento en la posición especificada.
     */
    int at(const int i, const int j) const {
      return v_.at(pos(i,j));
    }
    
    /**
     * @brief Escribe la matriz en un flujo de salida.
     * 
     * Este método imprime la matriz en el flujo de salida proporcionado.
     * 
     * @param os Flujo de salida.
     */
    void write(std::ostream& os) const {
      for (int i{1}; i <= m_; i++) {
        for (int j{1}; j <= n_; j++) {
          os << at(i, j) << " ";   
        }
        os << '\n';
      }
    }

    /**
     * @brief Inicializa la matriz con valores aleatorios.
     * 
     * Este método inicializa la matriz con valores aleatorios entre 0 y 1.
     * 
     * @param seed Semilla para la generación de números aleatorios.
     */
    void init_random(int seed) {
      srand(seed);
      for (int i{1}; i <= m_; i++) {
        for (int j{1}; j <= n_; j++) {
          at(i, j) = rand() % 2;
        }
      }
    }

    /**
     * @brief Calcula la suma total de los elementos de la matriz.
     * 
     * @return La suma total de los elementos.
     */
    int suma_total() const {
      int sum{0};
      for (int i{1}; i <= m_; i++) {
        for (int j{1}; j <= n_; j++) {
          sum += at(i, j);
        }
      }
      return sum;
    }

    /**
     * @brief Calcula la suma de los elementos en posiciones con índices pares.
     * 
     * @return La suma de los elementos en posiciones con índices pares.
     */
    int suma_indice_par() const {
      int sum{0};
      for (int i{1}; i <= m_; i++) {
        for (int j{1}; j <= n_; j++) {
          if ((i + j) % 2 == 0) sum += at(i, j);
        }
      }
      return sum;
    }

    /**
     * @brief Calcula la suma de los elementos en la diagonal principal.
     * 
     * @return La suma de los elementos en la diagonal principal.
     */
    int suma_diagonal_principal() const {
      assert(m_ == n_);
      int sum{0};
      for (int i{1}; i <= m_; i++) {
        sum += at(i,i);
      }
      return sum;
    }

    /**
     * @brief Calcula la suma de los elementos en la diagonal secundaria.
     * 
     * @return La suma de los elementos en la diagonal secundaria.
     */
    int suma_diagonal_secundaria() const {
      assert(m_ == n_);
      int sum{0};
      for (int i{1}; i <= m_; i++) {
        sum += at(i, n_ - i + 1);
      }
      return sum;
    }

    /**
     * @brief Calcula la suma de los elementos en la triangular inferior incluyendo la diagonal.
     * 
     * @return La suma de los elementos en la triangular inferior incluyendo la diagonal.
     */
    int suma_triangular_inferior_diagonal() const {
      assert(m_ == n_);
      int sum{0};
      for (int i{1}; i <= m_; i++) {
        for (int j{1}; j <= i; j++) {
          sum += at(i,j);
        }
      }
      return sum;
    }

    /**
     * @brief Calcula la suma de los elementos en la triangular inferior sin incluir la diagonal.
     * 
     * @return La suma de los elementos en la triangular inferior sin incluir la diagonal.
     */
    int suma_triangular_inferior() const {
      assert(m_ == n_);
      int sum{0};
      for (int i{2}; i <= m_; i++) {
        for (int j{1}; j <= i; j++) {
          sum += at(i,j);
        }
      }
      return sum;
    }

    /**
     * @brief Calcula la suma de los elementos en la triangular superior incluyendo la diagonal.
     * 
     * @return La suma de los elementos en la triangular superior incluyendo la diagonal.
     */
    int suma_triangular_superior_diagonal() const {
      assert(m_ == n_);
      int sum{0};
      for (int i{1}; i <= m_; i++) {
        for (int j{i}; j <= m_; j++) {
          sum += at(i,j);
        }
      }
      return sum;
    }

    /**
     * @brief Calcula la suma de los elementos en la triangular superior sin incluir la diagonal.
     * 
     * @return La suma de los elementos en la triangular superior sin incluir la diagonal.
     */
    int suma_triangular_superior() const {
      assert(m_ == n_);
      int sum{0};
      for (int i{1}; i < m_; i++) {
        for (int j{i + 1}; j <= m_; j++) {
          sum += at(i,j);
        }
      }
      return sum;
    }

    /**
     * @brief Suma dos matrices y almacena el resultado en la matriz actual.
     * 
     * @param A Primera matriz a sumar.
     * @param B Segunda matriz a sumar.
     */
    void suma(const matrix& A, const matrix& B) {
      assert(n_ == A.n_ && m_ == A.m_);
      assert(n_ == B.n_ && m_ == B.m_);
      for (int i{1}; i <= m_; i++) {
        for (int j{1}; j <= n_; j++) {
          at(i,j) = A.at(i,j) + B.at(i,j);
        }
      }
    }

    /**
     * @brief Multiplica dos matrices y almacena el resultado en la matriz actual.
     * 
     * @param A Primera matriz a multiplicar.
     * @param B Segunda matriz a multiplicar.
     */
    void producto(const matrix& A, const matrix& B) {
      assert(m_ == A.m_ && n_ == B.n_);
      assert(A.n_ == B.m_);
      for (int i{1}; i <= m_; i++) {
        for (int j{1}; j <= n_; j++) {
          at(i,j) = 0;
          for (int k{1}; k <= A.n_; k++) {
            at(i,j) += A.at(i, k) * B.at(k, j);
          }
        }
      }
    }

   private:
    /**
     * @brief Calcula la posición lineal en el vector de un elemento de la matriz.
     * 
     * @param i Fila del elemento.
     * @param j Columna del elemento.
     * @return La posición lineal en el vector.
     */
    int pos(const int i, const int j) const {
      assert(i >= 1 && j >= 1 && i <= m_ && j <= n_);
      return (i - 1) * n_ + (j - 1);
    } 

    vector v_;
    int m_;
    int n_;
  };
}

// Loop principal propuesto por el profesor Jorge Riera Ledesma
int main(void)
{
    AyED::matrix A(5, 5);

    A.init_random(1);

    A.write(std::cout);

    std::cout << "Suma total                        : " << std::setw(5) << A.suma_total() << std::endl;
    std::cout << "Suma índice par                   : " << std::setw(5) << A.suma_indice_par() << std::endl;
    std::cout << "Suma diagonal principal           : " << std::setw(5) << A.suma_diagonal_principal() << std::endl;
    std::cout << "Suma diagonal secundaria          : " << std::setw(5) << A.suma_diagonal_secundaria() << std::endl;
    std::cout << "Suma triangular inf. con diagonal : " << std::setw(5) << A.suma_triangular_inferior_diagonal() << std::endl;
    std::cout << "Suma triangular inf. sin diagonal : " << std::setw(5) << A.suma_triangular_inferior() << std::endl;
    std::cout << "Suma triangular sup. con diagonal : " << std::setw(5) << A.suma_triangular_superior_diagonal() << std::endl;
    std::cout << "Suma triangular sup. sin diagonal : " << std::setw(5) << A.suma_triangular_superior() << std::endl;
    std::cout << std::endl;

    AyED::matrix B(3, 4);
    AyED::matrix C(3, 4);
    AyED::matrix D(3, 4);

    B.init_random(2);
    C.init_random(3);

    D.suma(B, C);

    std::cout << "B" << std::endl;
    B.write(std::cout);
    std::cout << std::endl;
    std::cout << "C" << std::endl;
    C.write(std::cout);
    std::cout << std::endl;
    std::cout << "D = B + C" << std::endl;
    D.write(std::cout);
    std::cout << std::endl;

    AyED::matrix E(3, 4);
    AyED::matrix F(4, 5);
    AyED::matrix G(3, 5);

    E.init_random(2);
    F.init_random(3);

    G.producto(E, F);

    std::cout << "E" << std::endl;
    E.write(std::cout);
    std::cout << std::endl;
    std::cout << "F" << std::endl;
    F.write(std::cout);
    std::cout << std::endl;
    std::cout << "G = E x F" << std::endl;
    G.write(std::cout);
    std::cout << std::endl;

    return 0;
}
