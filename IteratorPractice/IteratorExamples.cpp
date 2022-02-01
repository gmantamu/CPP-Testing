#include <iostream>
#include <vector>

int main() {
    std::vector<int> testvec = {1,2,3,4,5};

    for(int i = 0; i < testvec.size(); i++) {
        std::cout << testvec[i] << std::endl;
    }
}