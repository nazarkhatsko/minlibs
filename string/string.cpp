#include "string.hpp"

using namespace nk;

string::string() {
    this->m_size = 0;
    this->m_data = nullptr;
};

string::string(const char *str) {
    if (str) {
        this->m_data = new char[this->m_size + 1];
        this->append(str);
    } else {
        string();
    };
};

string::string(const string &str) {
    if (this != &str) {
        this->m_data = new char[str.m_size + 1];
        this->append(str.m_data);
    } else {
        string();
    };
};

string::~string() {
    delete[] this->m_data;
};

string & string::operator=(const char *str) {
    if (str) {
        delete[] this->m_data;
        this->m_data = new char[this->m_size + 1];
        this->append(str);
    };
    return *this;
};

string & string::operator=(const string &str) {
    if (this != &str) {
        delete[] this->m_data;
        this->m_data = new char[this->m_size + 1];
        this->append(str.m_data);
    };
    return *this;
};

string string::operator+(const char *str) {
    string s;
    s.append(this->m_data);
    s.append(str);
    return s;
};

string string::operator+(const string &str) {
    string s;
    s.append(this->m_data);
    s.append(str.m_data);
    return s;
};

string & string::operator+=(const char *str) {
    this->append(str);
    return *this;
};

string & string::operator+=(const string &str) {
    this->append(str);
    return *this;
};

char & string::operator[](int index) {
    return this->m_data[index];
};

bool string::operator>(const char *str) {
    return (this->m_size > strlen(str));
};

bool string::operator>(const string &str) {
    return (this->m_size > str.m_size);
};

bool string::operator<(const char *str) {
    return (this->m_size < strlen(str));
};

bool string::operator<(const string &str) {
    return (this->m_size < str.m_size);
};

bool string::operator>=(const char *str) {
    return (this->m_size >= strlen(str));
};

bool string::operator>=(const string &str) {
    return (this->m_size >= str.m_size);
};

bool string::operator<=(const char *str) {
    return (this->m_size <= strlen(str));
};

bool string::operator<=(const string &str) {
    return (this->m_size <= str.m_size);
};

bool string::operator==(const char *str) {
    if (this->m_size == strlen(str)) {
        for (int i = 0; i < this->m_size; i++) {
            if (this->m_data[i] != str[i]) {
                return false;
            };
        };
        return true;
    };
    return false;
};

bool string::operator==(const string &str) {
    return (operator==(str.m_data));
};

bool string::operator!=(const char *str) {
    return !(operator==(str));
};

bool string::operator!=(const string &str) {
    return !(operator==(str));
};

inline const char * string::c_str() const {
    return this->m_data;
};

inline const size_t string::length() const {
    return this->m_size;
};

inline const bool string::empty() const {
    return (this->m_size == 0);
};

char & string::front() {
    return this->m_data[0];
};

char & string::back() {
    return this->m_data[m_size - 1];
};

void string::append(const char *str) {
    if (str) {
        this->m_size += strlen(str);
        strcat(this->m_data, str);
    };
};

void string::append(const string &str) {
    if (str.m_data != nullptr) {
        this->m_size += str.m_size;
        strcat(this->m_data, str.m_data);
    };
};

void string::remove(int index) {
    char *n_data = new char[this->m_size];
    for (int m = 0, n = 0; n < this->m_size; m++) {
        if (m != index) {
            n_data[n] = this->m_data[m];
            n++;
        };
    };
    n_data[this->m_size - 1] = '\0';

    this->m_size--;
    delete[] this->m_data;
    this->m_data = n_data;
};

void string::remove(char ch) {
    for (int i = 0; i < this->m_size; i++) {
        if (this->m_data[i] == ch) {
            this->remove(i);
        };
    };
};

void string::insert(int index, char ch) {
    char *n_data = new char[this->m_size + 2];
    for (int m = 0, n = 0; n < this->m_size; n++) {
        if (n != index) {
            n_data[n] = this->m_data[m];
            m++;
        };
    };
    n_data[index] = ch;
    n_data[this->m_size + 1] = '\0';

    this->m_size++;
    delete[] this->m_data;
    this->m_data = n_data;
};

void string::swap(int first, int second) {
    char ch = this->m_data[first];
    this->m_data[first] = this->m_data[second];
    this->m_data[second] = ch;
};

void string::clear() {
    this->m_size = 0;
    delete[] this->m_data;
    this->m_data = nullptr;
};

void string::sort(int begin, int end) {
    for (int i = begin; i < end; i++) {
        for (int n = i; n < end; n++) {
            if (this->m_data[i] > this->m_data[n]) {
                char el = this->m_data[i];
                this->m_data[i] = this->m_data[n];
                this->m_data[n] = el;
            };
        };
    };
};

void string::erase(int begin, int end) {
    int n_size = this->m_size - end - begin;
    char *n_data = new char[n_size + 1];
    for (int m = 0, n = 0; m < this->m_size; m++) {
        if (m < begin || m >= end) {
            n_data[n] = this->m_data[m];
            n++;
        };
    };
    n_data[n_size] = '\0';

    this->m_size = n_size;
    delete[] this->m_data;
    this->m_data = n_data;
};

void string::reverse(int begin, int end) {
    for (int i = begin; i < end / 2; i++) {
        char el = this->m_data[i];
        this->m_data[i] = this->m_data[end - i - 1];
        this->m_data[end - i - 1] = el;
    };
};

void string::print() {
    std::cout << this->m_data << std::endl;
};