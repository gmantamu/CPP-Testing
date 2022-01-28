// The goal here is to get more comfortable with the Rule of Three when it comes to classes and overall implication in C++
// 1: Deconstructor   (make sure there is no memory leak at the end)
// 2: Copy Constructor  (Foo g = i;  Foo g(i);)
// 3: Copy assignment Constructor (Foo i; Foo g; i = g)

// Working with a class that points to a dynamically allocated array

#include <iostream>

class testy {
    private:
        int* p;
        int size;

    public:
    // Just the basic parameters of the class
    testy(int s, int f) {
        size = s;
        p = new int[size];

        for(int i = 0; i < size; i++){
            p[i] = f;
        } 
    }

    // Deconstructor (just to delete any dynamically allocated memory when we leave the scope with the object)
    ~testy() { delete [] p; }

    // Copy COnstructor
    // Foo g = i;   or    Foo g(i);
    testy(const testy& other) {
        size = other.size;
        p = new int[size];

        for(int i = 0; i < size; i++) {
            p[i] = other.p[i];
        }
    }

    // Copy assignment constructor
    // Foo i; Foo g; i = g;
    // i = j = g = f;
    // j = j;
    testy& operator=(const testy& other) {
        if (this == &other) {
            return *this;
        }

        if (size >= other.size) {
            for(int i = 0; i < other.size; i++) {
                p[i] = other.p[i];
            }
        }
        else {
            for(int i = 0; i < size; i++) {
                p[i] = other.p[i];
            }
        }

        return *this;
    }

    void print() const {
        for(int i = 0; i < size; i++) {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }

};

int main() {
    testy f(5,9);
    f.print();
}