/**
 * @file main.cpp
 * @brief Programa principal para demostrar el uso de la lista enlazada simple (SLL).
 * 
 * Este programa utiliza la clase plantilla sll_t y sll_node_t para crear y manipular
 * una lista enlazada simple de enteros. Se muestran todos los métodos disponibles:
 * - push_front
 * - pop_front
 * - insert_after
 * - erase_after
 * - search
 * - write
 *
 * Se asume que los métodos definidos en sll_t y sll_node_t funcionan correctamente.
 *
 * @author Héctor Martín Álvarez
 * @date 2025-03-12
 */

 #include <iostream>
 #include <cassert>
 #include "sll_node_t.h"
 #include "sll_t.h"
 
 int main() {
   // Crear una lista enlazada simple de enteros
   sll_t<int> lista;
   
   // Comprobar que la lista está vacía
   assert(lista.empty());
 
   // Inserción de nodos con push_front: 
   // La lista será: 10 -> 20 -> 30 (cabeza apunta al 10)
   lista.push_front(new sll_node_t<int>(30));
   lista.push_front(new sll_node_t<int>(20));
   lista.push_front(new sll_node_t<int>(10));
 
   // Mostrar la lista completa mediante write
   std::cout << "Lista después de push_front (10 -> 20 -> 30): ";
   lista.write(std::cout);
 
   // Buscar un nodo (se busca el dato 20)
   sll_node_t<int>* nodoBuscado = lista.search(20);
   if (nodoBuscado != nullptr) {
     std::cout << "Se encontró el nodo con dato 20: ";
     nodoBuscado->write(std::cout);
     std::cout << std::endl;
   } else {
     std::cout << "No se encontró el nodo con dato 20." << std::endl;
   }
 
   // Insertar un nodo después del nodo con dato 20
   // Se insertará el número 25, quedando la lista: 10 -> 20 -> 25 -> 30
   sll_node_t<int>* nodoNuevo = new sll_node_t<int>(25);
   lista.insert_after(nodoBuscado, nodoNuevo);
   std::cout << "Lista después de insertar 25 después del nodo con dato 20: ";
   lista.write(std::cout);
 
   // Eliminar el nodo que está después del nodo con dato 20 (el nodo con 25)
   sll_node_t<int>* nodoEliminado = lista.erase_after(nodoBuscado);
   std::cout << "Nodo eliminado (debe ser 25): ";
   nodoEliminado->write(std::cout);
   std::cout << std::endl;
   // Liberar la memoria del nodo eliminado
   delete nodoEliminado;
 
   std::cout << "Lista después de eliminar el nodo que sigue al 20: ";
   lista.write(std::cout);
 
   // Extraer el nodo frontal mediante pop_front (se extrae el nodo con 10)
   sll_node_t<int>* nodoExtraido = lista.pop_front();
   std::cout << "Nodo extraído del frente (debe ser 10): ";
   nodoExtraido->write(std::cout);
   std::cout << std::endl;
   // Liberar la memoria del nodo extraído
   delete nodoExtraido;
 
   std::cout << "Lista final tras pop_front (debe ser 20 -> 30): ";
   lista.write(std::cout);
 
   // La memoria de los nodos restantes se libera en el destructor de sll_t.
   return 0;
 }
