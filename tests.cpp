/** Dumb testing */

#include <iostream>
#include <string>

#include "middlesquare.hpp"


// Global counter for failures
int failures = 0;


template <typename T> void assert_equals(std::string test, T first, T second) {
    if (first != second) {
        std::cerr << "In test " << test << ": " << first << " != " << second << std::endl;
        failures++;
    }
}

void test_pad() {
    assert_equals("test_pad", middlesquare::pad(123456, 4), 123456);
    assert_equals("test_pad", middlesquare::pad(12345, 4), 12345);
    assert_equals("test_pad", middlesquare::pad(1234, 4), 1234);
    assert_equals("test_pad", middlesquare::pad(123, 4), 1230);
    assert_equals("test_pad", middlesquare::pad(12, 4), 1200);
    assert_equals("test_pad", middlesquare::pad(1, 4), 1000);
    assert_equals("test_pad", middlesquare::pad(0, 4), 0);
}

void run_tests() {
    test_pad();
    std::cout << "Total failures reported: " << failures << std::endl;
}

int main() {
    run_tests();
}