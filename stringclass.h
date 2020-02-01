#ifndef DNA_STRINGCLASS_H
#define DNA_STRINGCLASS_H

#include <cstring>
#endif


#include <cstddef>
#include <iostream>

class String{

private:
    char* data;
    //size_t str_len;

public:
    String(): data(NULL){}
    String(const char* str );
    String(const String& str);
    ~String();

    size_t getLen() const;
    size_t getSize() const;
    String& operator = (const String& str);
    String& operator += (const String& str);

    bool operator == (const String& str2);
    bool operator != (const String& str2);
    bool operator < (const String& str2);
    bool operator <= (const String& str2);
    bool operator > (const String& str2);
    bool operator >= (const String& str2);
    friend int my_strcmp(const String& str1, const String& str2);
    friend std::ostream& operator << (std::ostream& os, const String& str);
    const char &operator[](size_t n)const;

};

inline size_t String::getLen() const {
    return sizeof(data);
}

inline size_t String::getSize() const{
    return strlen(data);
}


inline bool String::operator == (const String& str2){
    return !(my_strcmp(*this, str2));
}

inline bool String::operator != (const String& str2){
    return (my_strcmp(*this, str2));
}

inline bool String::operator < (const String& str2){
    return (my_strcmp(*this, str2) < 0);
}

inline bool String::operator <= (const String& str2){
    return (my_strcmp(*this, str2) <= 0);
}

inline bool String::operator > (const String& str2){
    return (my_strcmp(*this, str2) > 0);
}

inline bool String::operator >= (const String& str2){
    return (my_strcmp(*this, str2) >= 0);
}

inline const char &String::operator[](size_t n) const {
    return this->data[n];
}



inline int my_strcmp(const String& str1, const String& str2){
    size_t i =0, j = 0, l = str1.getLen();
    int n = 0;
    while(i < l && 0 == n){
        n =  str1.data[i++] - str2.data[j++];
    }
    return n;
}
std::ostream& operator << (std::ostream& os, const String& t);