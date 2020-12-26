/*
 * LinkedList.hpp
 * */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
#include "Node.hpp"

template<typename E>
std::ostream& operator<< (std::ostream& os, const LinkedList<E>& list);

template<typename E>
class LinkedList
{
public:
  LinkedList();
  ~LinkedList();
  inline bool empty() const;
  const E& front() const;
  void add(const E& e);
  void remove();

private:
  Node<E>* head_;

  friend std::ostream& operator<< <> (std::ostream& os, const LinkedList<E>& list);
};

#endif // LINKED_LIST_HPP
