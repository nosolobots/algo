/*
 * LinkedList.hpp
 * */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>

#include "Node.hpp"

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedList<E>& list);

template <typename E>
class LinkedList {
   public:
    LinkedList() : head_(nullptr) {}
    ~LinkedList();
    bool empty() const { return head_ == nullptr; }
    const E& front() const { return head_->data_; }
    void add(const E& e);
    void remove();

   private:
    Node<E>* head_;

    friend std::ostream& operator<<<>(std::ostream& os,
                                      const LinkedList<E>& list);
};

template <typename E>
LinkedList<E>::~LinkedList() {
    while (!empty()) remove();
}

template <typename E>
void LinkedList<E>::add(const E& e) {
    Node<E>* n = new Node<E>(e);
    n->next_ = head_;
    head_ = n;
}

template <typename E>
void LinkedList<E>::remove() {
    if (head_ != nullptr) {
        Node<E>* old = head_;
        head_ = old->next_;
        delete old;
    }
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedList<E>& list) {
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

#endif  // LINKED_LIST_HPP
