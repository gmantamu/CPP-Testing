#include <iostream>
#include <vector>

int main() {
    std::vector<int> testvec = {1,2,3,4,5};

    for(int i = 0; i < testvec.size(); i++) {
        std::cout << testvec[i] << std::endl;
    }

    //slightly cleaner code, but it still is limited in the type of lists that if can iterate through
    for(int value : testvec) {
        std::cout << value << std::endl;
    }

    //        defining the iterator                  making the loop run until this
    for(std::vector<int>::iterator it = testvec.begin(); it != testvec.end(); it++) {
        std::cout << *it << std::endl;
    }
    
}