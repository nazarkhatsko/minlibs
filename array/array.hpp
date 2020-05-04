#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <initializer_list>

namespace nk {
    template<typename T, size_t N>
    class array {
    public: // CONSTRUCTORS AND DESTRUCTOR
        array();
        array(std::initializer_list<T>);
        array(const array<T, N> &);
        ~array();
        
    public: // OPERATORS
        array & operator=(std::initializer_list<T>);
        array & operator=(const array<T, N> &);
        
        T & operator[](int);

        bool operator==(const array<T, N> &);
        bool operator!=(const array<T, N> &);
        
    public: // METHODS
        inline const size_t count() const;

        T & front();
        T & back();
        
        void fill(T);

        void swap(int, int);
        void sort(int, int);
        void reverse(int, int);

        void print();

    private: // DATA
        size_t m_size;
        T m_data[N];
    };
};

#endif // ARRAY_H
