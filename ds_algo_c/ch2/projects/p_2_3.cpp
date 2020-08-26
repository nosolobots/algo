/*
Implement a templated C++ class Vector that manipulates a numeric vec-
tor. Your class should be templated with any numerical scalar type T ,
which supports the operations + (addition), − (subtraction), and * (mul-
tiplication). In addition, type T should have constructors T (0), which
produces the additive identity element (typically 0) and T (1), which pro-
duces the multiplicative identity (typically 1). Your class should provide a
constructor, which is given the size of the vector as an argument. It should
provide member functions (or operators) for vector addition, vector sub-
traction, multiplication of a scalar and a vector, and vector dot product.
*/

#include<iostream>
#include<type_traits>
#include<vector>
#include<string>
#include<exception>

using namespace std;

template <typename T>
class Vector
{
public:
    Vector(size_t n, T val): data_(vector<T>(n, val)) {}
    Vector(const Vector<T>& v): data_(v.data_.begin(), v.data_.end()) {}
    Vector<T>& operator=(const Vector<T> &v);
    
    vector<T> &data() { return data_; }
    size_t size() { return data_.size(); }
    
    Vector<T> operator+(Vector<T>& v);
    Vector<T> operator-(Vector<T> &v);
    Vector<T> operator*(T s);
    T operator*(Vector<T> &v);
    T& operator[](size_t i);

    template <typename V>
    friend ostream &operator<<(ostream &os, const Vector<V> &v);

private:
    static_assert(is_arithmetic<T>::value, "No es un tipo válido");

    vector<T> data_;
};

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &v)
{
    data_(v.data_.begin(), v.data_.end());
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(Vector<T> &v)
{
    if(data_.size() != v.size())
        throw runtime_error("Can't sum vectors of different size");

    Vector<T> v_new(size(), 0);
        
    for(size_t i=0; i<data_.size(); i++)
        v_new[i] = data_[i] + v[i];

    return v_new;
}

template <typename T>
Vector<T> Vector<T>::operator-(Vector<T> &v)
{
    if (data_.size() != v.size())
        throw "Can't subtract vectors of different size";

    Vector<T> v_new(size(), 0);

    for (size_t i = 0; i < data_.size(); i++)
        v_new[i] -= v[i];

    return v_new;
}

template <typename T>
Vector<T> Vector<T>::operator*(T s)
{
    Vector<T> v_new(*this);

    for (size_t i = 0; i < data_.size(); i++)
        v_new[i] *= s;

    return v_new;
}

template <typename T>
T Vector<T>::operator*(Vector<T>& v)
{
    if (data_.size() != v.size())
        throw "Can't calculate dot product of vectors of different size";

    T val = 0;
    for (size_t i = 0; i < data_.size(); i++)
        val += data_[i]*v[i];

    return val;
}

template <typename T>
T& Vector<T>::operator[](size_t i)
{
    return data_[i];
}

template <typename T>
    ostream &operator<<(ostream &os, const Vector<T> &v)
{
    cout << "[";
    for(auto it=v.data_.begin(); it!=v.data_.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << "\b\b]";
    return os;
}

int main()
{
    Vector<int> v1(3, 0);
    v1.data()[1] = 1;
    v1.data()[2] = 2;

    Vector<int> v2(v1);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    Vector<double> v3(2, 1);
    v3.data()[0] = 1.5;
    v3.data()[1] = 2.5;

    cout << "v3: " << v3 << endl;

    cout << "v1+v2 =  " << (v1+v2) << endl;

    Vector<double> v4(4, 0);
    try
    {
        cout << "v3 + Vector<double>(4,0) =  " << (v3 + v4) << endl;
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "v3*3.0 =  " << (v3*3.0) << endl;

    Vector<double> v5 = v3*3.0;
    cout << "v3*(v3*3.0) =  " << (v3 * v5) << endl;

    return EXIT_SUCCESS;
}