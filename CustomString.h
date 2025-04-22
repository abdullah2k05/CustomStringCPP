// customstring.h
//  Library by MUHAMMAD ABDULLAH ( @abdullah2k05 )
//https://github.com/abdullah2k05/


#ifndef custom_string_by_MUHAMMAD_ABDULLAH_abdullah2k05
#define custom_string_by_MUHAMMAD_ABDULLAH_abdullah2k05

#include <iostream>
using namespace std;

class CustomString {
protected:
    char stack_memory[32];
    char* heap_memory;
    bool isheap;

public:
    CustomString(const char* string = "");
    ~CustomString();
    CustomString(const CustomString& other);
    CustomString& operator=(const CustomString rhs);
    int check_length_() const;

    friend ostream& operator<<(ostream& os, CustomString& rhs);
    friend istream& operator>>(istream& is, CustomString& rhs);
    CustomString operator+(CustomString rhs);
};

#endif
