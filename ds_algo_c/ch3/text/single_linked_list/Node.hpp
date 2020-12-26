/*
 * Node.hpp
 * */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>

template<typename E>
class LinkedList;

template<typename E>
class Node;

template<typename E>
std::ostream& operator<< (std::ostream& os, const Node<E>& n);

template<typename E>
class Node
{
public:
  explicit Node(const E& e);
  Node<E>* getNext() const;

private:
  E data_;
  Node<E>* next_;

  friend class LinkedList<E>;

  friend std::ostream& operator<< <> (std::ostream& os, const Node<E>& n);
};

#endif // NODE_HPP
