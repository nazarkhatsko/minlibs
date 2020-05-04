#include "array.hpp"

using namespace nk;

template<typename T, size_t N>
array<T, N>::array() {
    this->m_size = N;
    for (int i = 0; i < this->m_size; i++) {
        this->m_data[i] = T();
    };
};

template<typename T, size_t N>
array<T, N>::array(const array<T, N> &arr) {
    this->m_size = arr.m_size;
    for (int i = 0; i < this->m_size; i++) {
        this->m_data[i] = arr.m_data[i];
    };
};

template<typename T, size_t N>
array<T, N>::array(std::initializer_list<T> list) : array() {
    int i = 0;
    for (auto &el : list) {
        this->m_data[i] = el;

        i++;
        if (i == this->m_size) {
            break;
        };
    };
};

template<typename T, size_t N>
array<T, N>::~array() {};

template<typename T, size_t N>
array<T, N> & array<T, N>::operator=(std::initializer_list<T> list) {
    int i = 0;
    for (auto &el : list) {
        this->m_data[i] = el;

        i++;
        if (this->m_size == i) {
            break;
        };
    };
    return *this;
};

template<typename T, size_t N>
array<T, N> & array<T, N>::operator=(const array<T, N> &arr) {
    for (int i = 0; i < this->m_size; i++) {
        this->m_data[i] = arr.m_data[i];
    }
    return *this;
};

template<typename T, size_t N>
T & array<T, N>::operator[](int index) {
    return this->m_data[index];
};

template<typename T, size_t N>
bool array<T, N>::operator==(const array<T, N> &arr) {
    if (this->m_size == arr.m_size) {
        for (int i = 0; i < this->m_size; i++) {
            if (this->m_data[i] != arr.m_data[i]) {
                return false;
            };
        };
        return true;
    };
    return false;
};

template<typename T, size_t N>
bool array<T, N>::operator!=(const array<T, N> &arr) {
    return !(operator==(arr));
};

template<typename T, size_t N>
inline const size_t array<T, N>::count() const {
    return this->m_size;
};

template<typename T, size_t N>
T & array<T, N>::front() {
    return this->m_data[0];
};

template<typename T, size_t N>
T & array<T, N>::back() {
    return this->m_data[this->m_size - 1];
};

template<typename T, size_t N>
void array<T, N>::fill(T el) {
    for (int i = 0; i < this->m_size; i++) {
        this->m_data[i] = el;
    };
};

template<typename T, size_t N>
void array<T, N>::swap(int first, int second) {
    T el = this->m_data[first];
    this->m_data[first] = this->m_data[second];
    this->m_data[second] = el;
};

template<typename T, size_t N>
void array<T, N>::sort(int begin, int end) {
    for (int i = begin; i < end; i++) {
        for (int n = i; n < end; n++) {
            if (this->m_data[i] > this->m_data[n]) {
                T el = this->m_data[i];
                this->m_data[i] = this->m_data[n];
                this->m_data[n] = el;
            };
        };
    };
};

template<typename T, size_t N>
void array<T, N>::reverse(int begin, int end) {
    for (int i = begin; i < end / 2; i++) {
        T el = this->m_data[i];
        this->m_data[i] = this->m_data[end - i - 1];
        this->m_data[end - i - 1] = el;
    };
};

template<typename T, size_t N>
void array<T, N>::print() {
    std::cout << '[' << ' ';
    for (int i = 0; i < this->m_size; i++) {
        std::cout << this->m_data[i] << ' ';
    }
    std::cout << ']' << '\n';
};