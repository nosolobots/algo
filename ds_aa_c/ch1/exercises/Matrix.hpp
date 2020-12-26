/*
 * Simple Matrix class
 * */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <ostream>
#include <vector>

template <typename T>
class Matrix {
   public:
    Matrix(int r = 0, int c = 0) : m_(r) {
        for (auto& row : m_) row.resize(c);
    }

    Matrix(std::vector<std::vector<T>> v) : m_{v} {}

    Matrix(std::vector<std::vector<T>>&& v) : m_{std::move(v)} {}

    const std::vector<T>& operator[](int r) const { return m_[r]; }

    std::vector<T>& operator[](int r) { return m_[r]; }

    int rows() const { return m_.size(); }
    int cols() const { return m_.size() ? m_[0].size() : 0; }

    void print(std::ostream& os = std::cout) const;

   private:
    std::vector<std::vector<T>> m_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T> m) {
    m.print(os);
    return os;
}

template <typename T>
void Matrix<T>::print(std::ostream& os) const {
    int n = 0;
    os << "[";
    for (auto& row : m_) {
        if (n++) os << "\n ";
        os << "[";
        for (auto& val : row) {
            os << val << ", ";
        }
        os << "\b\b]";
    }
    os << "]";
}

#endif  // MATRIX_HPP
