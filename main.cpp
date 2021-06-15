#include <iostream>
#include <ctime>

#include "middlesquare.hpp"


/**
 * Demostration of the generator
 */
int main() {
    auto generator = middlesquare::Generator(int(std::time(nullptr)));

    for (int i = 0; i < 100; i++) {
        std::cout << generator.next() << std::endl;
    }
}