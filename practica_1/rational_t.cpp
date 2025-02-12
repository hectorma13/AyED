// AUTOR: Héctor Martín Álvarez 
// FECHA: 10/02/2025
// EMAIL: alu0101714059@ull.edu.es
// VERSION: 1.0 
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método

// Getter que retorna el valor del numerador del objeto (atributo num_)
int
rational_t::get_num() const
{
  return num_;
}


// Getter que retorna el valor del denominador del objeto (atributo den_)
int
rational_t::get_den() const
{
  return den_;
}


// Getter que establece un nuevo valor del numerador del objeto sin retornar nada  
void
rational_t::set_num(const int n)
{
  num_ = n;
}


// Getter que establece un nuevo valor del denominador del objeto sin retornar nada  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}


// Método que devuelve el valor decimal de la fracción (num_/den_)
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{
  return fabs(value() - r.value()) < precision;
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return value() - r.value() > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return r.value() - value() > precision;
}


// operaciones
rational_t
rational_t::add(const rational_t& r)
{
  // Aplico las operaciones de la suma de fracciones directamente en el return
  // Devuelve un objeto de nuestra clase rational_t
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(),
                    get_den() * r.get_den());
}



rational_t
rational_t::substract(const rational_t& r)
{
  // Aplico las operaciones de la resta de fracciones directamente en el return
  // Devuelve un objeto de nuestra clase rational_t
  return rational_t(get_num() * r.get_den() + get_den() * (-r.get_num()),
                    get_den() * r.get_den());
}



rational_t
rational_t::multiply(const rational_t& r)
{
  // Aplico las operaciones del producto de fracciones directamente en el return
  // Devuelve un objeto de nuestra clase rational_t
  return rational_t(get_num() * r.get_num(),
                    get_den() * r.get_den());
}



rational_t
rational_t::divide(const rational_t& r)
{
  // Aplico las operaciones de la división de fracciones directamente en el return
  // Devuelve un objeto de nuestra clase rational_t
  return rational_t(get_num() * r.get_den(),
                    get_den() * r.get_num());
}



// E/S

// Imprime el objeto (fracción) por salida estándar (cout)
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


// Lee el objeto (fracción) por entrada estándar (cin)
void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
