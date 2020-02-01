#include "stringclass.h"

#include <cstring>
#include <cstdlib>

String::String(const char *str) {
    size_t size = strlen(str);
    data = new char[size +1];
    strcpy(data, str);
}

String::String(const String &str) {
    size_t size = str.getLen(), i =0;
    data = new char[size+1];

    for(; i < size + 1; i++){
        data[i] = str.data[i];
    }
}

String::~String() {}

String &String::operator=(const String &str) {
    size_t size = str.getLen(), i = 0;
    delete[] data;
    data = new char[size+1];

    for(; i < size + 1; i++){
        data[i] = str.data[i];
    }
    return *this;
}


String &String::operator+=(const String& str) {
    size_t i = this->getLen();
    size_t size = i + str.getLen() + 1, s = i;
    char* temp = (char*) realloc((void *) data, size);

    for(; i < size; i++){
        temp[i] = str.data[i - s];
    }
    temp[size-1] = '\0';
    return *this;
}

std::ostream &operator<<(std::ostream &os, const String &str) {
    return (os << str.data);
}