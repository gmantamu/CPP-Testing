// The goal here is to get more comfortable with the Rule of Three when it comes to classes and overall implication in C++
// 1: Deconstructor   (make sure there is no memory leak at the end)
// 2: Copy Constructor  (Foo g = i;  Foo g(i);)
// 3: Copy assignment Constructor (Foo i; Foo g; i = g)

class testy {
    private:
        int* p;
        int size;

    public:
    testy(int s, int f) {
        size = s;
        p = new int[size];

        for(int i = 0; i < size; i++){
            p[i] = f;
        } 
    }

    // Deconstructor
    ~testy() { delete [] p; }

    //
};