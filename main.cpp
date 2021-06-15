#include <iostream>
#include <ctime>
#include <unordered_set>
#include <string>
#include <algorithm>

#include "middlesquare.hpp"


/**
 * Tests the probabolity of occurances of the digits 0 and 1 in the generated number
 */
void test_probability() {
    size_t one_ocuurances = 0;
    size_t zero_ocuurances = 0;

    int start_seed;

    std::cout << "Enter a start seed: ";
    std::cin >> start_seed;

    auto generated_values = std::unordered_set<int> {};
    auto gen = middlesquare::Generator {start_seed};

    int curr = 0;
    while (!generated_values.count(curr = gen.next())) {
        generated_values.insert(curr);

        auto str = std::to_string(curr);
        one_ocuurances += std::count(str.begin(), str.end(), '1');
        zero_ocuurances += std::count(str.begin(), str.end(), '0');
    }

    std::cout << "Ones: "  << one_ocuurances  << std::endl
              << "Zeros: " << zero_ocuurances << std::endl;
}

/**
 * Demostration of the generator
 */
int main() {
    test_probability();
}