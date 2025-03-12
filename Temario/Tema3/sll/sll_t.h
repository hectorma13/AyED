#ifndef SLLT_H_
#define SLLT_H_

#include "sll_node_t.h"
#include <cassert>


template <class T> class sll_t{
 public:
  // Constructor
  sll_t() : head_{nullptr} {}

  // Destructor
  ~sll_t();

  // Getter
  sll_node_t<T>* get_head() const { return head_; }

  // Verificar si la lista está vacía
  bool empty() const;

  // Operaciones con SLL's
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front();
  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);
  sll_node_t<T>* search(const T&) const;

  // Salida
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  // Cabeza de nuestra lista enlazada simple
  // Da inicio a nuestra lista, apunta al primer nodo
  sll_node_t<T>* head_;
};

// Destructor
template <class T> sll_t<T>::~sll_t() {
  while (!empty()) { // Hacemos lo siguiente hasta que la lista esté vacía (head_ = nullptr)
    sll_node_t<T>* aux = head_; // Guardamos en aux el nodo al que apunta head_ ahora
    head_ = head_->get_next(); // Ahora, actualizamos head_ y hacemos que apunte al siguiente de donde apuntaba antes
    delete aux; // Eliminamos el nodo al que head_ apuntaba en origen
  }
}

// Verificar si la lista está vacía
template <class T> bool sll_t<T>::empty() const {
  return head_ == nullptr;
}

// Operaciones con SLL's

/*template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != nullptr); 
  sll_node_t<T>* aux{head_};
  head_ = n;
  n->set_next(aux);
}*/
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_); // Ahora, n apunta al nodo al que apunta head_
  head_ = n; // Ahora, head apunta al nodo n que queríamos introducir
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front() {
  assert(!empty());
  // Primero, creamos un auxiliar que apunte al primer nodo (al que apunta _head)
  sll_node_t<T>* aux = head_;
  // Lo segundo, es hacer que head_ apunte al nodo siguiente del que está apuntando
  head_ = head_->get_next();
  // Ahora, tenemos que hacer que aux apunte a nullptr para sacarlo de la lista
  aux->set_next(nullptr);
  // Hacemos que el método retorne el nodo extraído
  return aux;
}

// Necesitamos un nodo previo (prev es un puntero hacia ese nodo), es decir, para saber donde introduciremos el nuevo nodo
// Y también necesitamos el nuevo nodo a introducir (está fuera de la SLL)
// El método sería: necesito introducir el nodo n después del nodo al que apunta prev
template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev, sll_node_t<T>* n) {
  // NOS ASEGURAMOS DE QUE LOS NODOS NO SON NULOS
  assert(prev != NULL && n != NULL);
  // Primero, n tiene que apuntar al nodo siguiente al que prev apunta
  n->set_next(prev->get_next());
  // Ahora, el nodo al que prev apunta ha de apuntar a nuestro nodo n
  prev->set_next(n);
}

template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) {
  // Primero, necesitamos definir el nodo que eliminaremos (el siguiente a prev)
  sll_node_t<T>* aux = prev->get_next();
  // Después, debemos hacer que el nodo previo apunte al siguiente de aux
  prev->set_next(aux->get_next());
  // Por último, debemos hacer que el nodo aux (el que eliminaremos) apunte a nullptr
  aux->set_next(nullptr);
  // Retornamos el nodo eliminado
  return aux;
}

template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {
  // Creamos un nodo (resultado) que será igual al primer nodo de todos
  sll_node_t<T>* aux = head_;
  // Mientras que el dato del nodo y el dato dado no coincidan y, mientras el auxiliar no sea nulo, hacemos:
  while (aux->get_data() != d && aux != nullptr) {
    // Actualizamos aux, cambiando de nodo en nodo (linealmente hacía adelante) para comparar el dato del nodo con d
    // hasta encontrarlo (si es que está)
    aux = aux->get_next();
  }
  // Devolvemos aux, pues ya hemos encontrado el dato en el nodo al que apunta
  // Si aux = nullptr, es porque el dato no está en la lista simplemente enlazada
  return aux;
}

template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  // Partimos desde el primer nodo de todos
  sll_node_t<T>* aux = head_;
  // Hacemos unas determinadas instrucciones hasta llegar al final (aux = nullptr)
  while (aux != nullptr) {
    // Escribimos el dato del nodo actual en la salida
    aux->write(os);
    os << " ";
    // Actualizamos aux, para pasar al siguiente nodo
    aux = aux->get_next();
  }
  // Añadimos un salto de línea después de imprimir todo
  os << "\n";
  return os;
}

#endif
