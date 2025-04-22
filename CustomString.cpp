// CustomString.cpp
// Library by MUHAMMAD ABDULLAH ( @abdullah2k05 )
// https://github.com/abdullah2k05/
#include "CustomString.h"

CustomString::CustomString(const char* string) {
    int input_size = 0;
    while (string[input_size] != '\0') {
        input_size++;
    }

    if (input_size < 32) {
        isheap = false;
        heap_memory = nullptr;
        for (int i = 0; i <= input_size; i++) {
            stack_memory[i] = string[i];
        }
    } else {
        isheap = true;
        heap_memory = new char[input_size + 1];
        for (int i = 0; i <= input_size; i++) {
            heap_memory[i] = string[i];
        }
    }
}

CustomString::~CustomString() {
    if (isheap) {
        delete[] heap_memory;
    }
}

CustomString::CustomString(const CustomString& other) {
    isheap = other.isheap;
    if (isheap) {
        int size = other.check_length_();
        heap_memory = new char[size + 1];
        for (int i = 0; i <= size; i++) {
            heap_memory[i] = other.heap_memory[i];
        }
    } else {
        heap_memory = nullptr;
        int size = other.check_length_();
        for (int i = 0; i <= size; i++) {
            stack_memory[i] = other.stack_memory[i];
        }
    }
}

CustomString& CustomString::operator=(const CustomString rhs) {
    if (this == &rhs) {
        return *this;
    }

    if (rhs.isheap) {
        if (isheap) {
            delete[] heap_memory;
            heap_memory = nullptr;
        }

        isheap = true;
        int size = rhs.check_length_();
        heap_memory = new char[size + 1];
        for (int i = 0; i <= size; i++) {
            heap_memory[i] = rhs.heap_memory[i];
        }
    } else {
        if (isheap) {
            delete[] heap_memory;
            heap_memory = nullptr;
        }

        isheap = false;
        int size = rhs.check_length_();
        for (int i = 0; i <= size; i++) {
            stack_memory[i] = rhs.stack_memory[i];
        }
    }

    return *this;
}

int CustomString::check_length_() const {
    int length = 0;
    if (isheap) {
        while (heap_memory[length] != '\0') {
            length++;
        }
    } else {
        while (stack_memory[length] != '\0') {
            length++;
        }
    }
    return length;
}

ostream& operator<<(ostream& os, CustomString& rhs) {
    if (rhs.isheap) {
        os << rhs.heap_memory;
        return os;
    } else {
        os << rhs.stack_memory;
        return os;
    }
}

istream& operator>>(istream& is, CustomString& rhs) {
    char temp[200];
    is.getline(temp, 200);
    return is;
}

CustomString CustomString::operator+(CustomString rhs) {
    CustomString temp;
    int rhs_index = rhs.check_length_();
    int original_index = check_length_();

    if (isheap || rhs.isheap || original_index + rhs_index > 32) {
        int next_index = 0;
        temp.isheap = true;
        temp.heap_memory = new char[original_index + rhs_index + 1];

        for (int i = 0; i < original_index; i++) {
            temp.heap_memory[i] = heap_memory[i];
            next_index++;
        }

        for (int i = 0, next_index; i <= rhs_index; next_index++, i++) {
            temp.heap_memory[next_index] = rhs.heap_memory[i];
        }
        temp.heap_memory[next_index] = '\0';
    } else {
        int next_index = 0;
        temp.isheap = false;
        temp.heap_memory = nullptr;

        for (int i = 0; i < original_index; i++) {
            temp.stack_memory[i] = stack_memory[i];
            next_index = i + 1;
        }

        for (int i = 0; i <= rhs_index; next_index++, i++) {
            temp.stack_memory[next_index] = rhs.stack_memory[i];
        }
        temp.stack_memory[next_index] = '\0';
    }
    return temp;
}
