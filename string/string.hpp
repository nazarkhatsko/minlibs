#pragma once

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

namespace nk {
    class string {
    public: // CONSTRUCTORS AND DESTRUCTOR
        string();
        string(const char *);
        string(const string &);
        ~string();

    public: // OPERATORS
        string & operator=(const char *);
        string & operator=(const string &);

        string operator+(const char *);
        string operator+(const string &);

        string & operator+=(const char *);
        string & operator+=(const string &);

        char & operator[](int);

        bool operator>(const char *);
        bool operator>(const string &);
        bool operator<(const char *);
        bool operator<(const string &);
        
        bool operator>=(const char *);
        bool operator>=(const string &);
        bool operator<=(const char *);
        bool operator<=(const string &);
        
        bool operator==(const char *);
        bool operator==(const string &);
        bool operator!=(const char *);
        bool operator!=(const string &);

    public: // METHODS
        inline const char * c_str() const;
        inline const size_t length() const;
        inline const bool empty() const;

        char & front();
        char & back();

        void append(const char *);
        void append(const string &);

        void remove(int);
        void remove(char);
        
        void insert(int, char);
        void swap(int, int);
                
        void clear();
        
        void sort(int, int);
        void erase(int, int);
        void reverse(int, int);

        void print();

    private: // DATA
        size_t m_size;
        char *m_data;
    };
};

#endif // STRING_H
