/*
 * LinkedListDemo.cpp
 *
 * */

#include "LinkedList.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int
main()
{
  LinkedList<int> lista1;
  LinkedList<std::string> lista2;

  lista1.add(5);
  lista1.add(4);
  lista1.add(1);
  lista2.add(std::string("Hola"));
  lista2.add("qué");
  lista2.add("tal?");

  std::cout << "lista1: " << lista1 << "\n";
  std::cout << "lista2: " << lista2 << "\n";

  lista1.remove();
  lista2.remove();

  std::cout << "lista1: " << lista1 << "\n";
  std::cout << "lista2: " << lista2 << "\n";

  return EXIT_SUCCESS;
}
