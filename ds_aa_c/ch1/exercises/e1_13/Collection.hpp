/*
 * class Collection
 * */

#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <iostream>
#include <stdexcept>
#include <utility>

template <typename Object>
class Collection {
   public:
    // Constructor
    explicit Collection(int size = 10) : size_(size), len_(0), data_(nullptr) {
        std::cout << "Constructor" << std::endl;

        if (size) data_ = new Object[size];
    }

    // Destructor
    ~Collection() {
        std::cout << "Destructor" << std::endl;

        if (data_ != nullptr) delete[] data_;
    }

    // Copy constructor
    Collection(const Collection& other) : size_(other.size_), len_(other.len_) {
        std::cout << "Copy Constructor" << std::endl;

        if (size_) data_ = new Object[size_];
        for (int i = 0; i < len_; i++) data_[i] = other.data_[i];
    }

    // Move constructor
    Collection(Collection&& other) : size_(other.size_), len_(other.len_) {
        std::cout << "Move Constructor" << std::endl;

        data_ = std::move(other.data_);

        other.data_ = nullptr;
        other.len_ = 0;
    }

    // Copy assignment
    Collection& operator=(const Collection& other) {
        std::cout << "Copy Assignment" << std::endl;

        if (this == &other) return *this;

        delete[] data_;
        data_ = new Object[other.size_];
        for (int i = 0; i < other.len_; i++) data_[i] = other.data_[i];

        size_ = other.size_;
        len_ = other.len_;

        return *this;
    }

    // Move assignment
    Collection& operator=(Collection&& other) {
        std::cout << "Move assignment" << std::endl;

        if (this == &other) return *this;

        delete[] data_;
        data_ = std::move(other.data_);

        size_ = other.size_;
        len_ = other.len_;

        other.data_ = nullptr;
        other.len_ = 0;

        return *this;
    }

    bool isEmpty() const { return (len_ == 0); }

    void makeEmpty() { len_ = 0; }

    void insert(Object obj) {
        if (len_ == size_)
            throw std::out_of_range("There is not room for more objects");

        data_[len_++] = obj;
    }

    Object remove() { return data_[--len_]; }

    bool contains(const Object& obj) const {
        bool founded = false;

        for (int i = 0; i < len_; i++) {
            if (data_[i] == obj) {
                founded = true;
                break;
            }
        }

        return founded;
    }

   private:
    Object* data_;
    int len_;       // array occupation
    int size_;      // array capacity
};

#endif  // COLLECTION_HPP
