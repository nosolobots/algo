/*
 * Node.cpp
 * */

#include "Node.hpp"

template<typename E>
Node<E>::Node(const E& e)
  : data_(e)
  , next_(nullptr)
{}

template<typename E>
Node<E>*
Node<E>::getNext() const
{
  return next_;
}

template<typename E>
std::ostream&
operator<<(std::ostream& os, const Node<E>& n)
{
  os << n.data_;

  return os;
}

template class Node<int>;
template class Node<std::string>;
template std::ostream& operator<< (std::ostream& os, const Node<int>& n);
template std::ostream& operator<< (std::ostream& os, const Node<std::string>& n);
