/*
 * LinkedList.cpp
 * */

#include "LinkedList.hpp"

template<typename E>
LinkedList<E>::LinkedList()
  : head_(nullptr)
{}

template<typename E>
LinkedList<E>::~LinkedList()
{
  while (!empty())
    remove();
}

template<typename E>
void
LinkedList<E>::remove()
{
  if (head_ != nullptr) {
    Node<E>* old = head_;
    head_ = old->next_;
    delete old;
  }
}

template<typename E>
inline bool
LinkedList<E>::empty() const
{
  return head_ == nullptr;
}

template<typename E>
const E&
LinkedList<E>::front() const
{
  return head_->data_;
}

template<typename E>
void
LinkedList<E>::add(const E& e)
{
  Node<E>* n = new Node<E>(e);
  n->next_ = head_;
  head_ = n;
}

template<typename E>
std::ostream&
operator<<(std::ostream& os, const LinkedList<E>& list)
{
  if (list.head_ == nullptr) {
    os << "[]";
  } else {
    os << "[";

    Node<E>* n = list.head_;
    while (n != nullptr) {
      os << *n << ", ";
      n = n->getNext();
    }

    os << "\b\b]";
  }

  return os;
}

template class LinkedList<int>;
template class LinkedList<std::string>;
template std::ostream& operator<< (std::ostream& os, const LinkedList<int>& list);
template std::ostream& operator<< (std::ostream& os, const LinkedList<std::string>& list);


