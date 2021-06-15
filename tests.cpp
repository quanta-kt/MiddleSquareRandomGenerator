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

void test_trim() {
    assert_equals("test_trim", middlesquare::trim_middle(123456, 4), 2345);
    assert_equals("test_trim", middlesquare::trim_middle(12345, 4), 1234);
    assert_equals("test_trim", middlesquare::trim_middle(12345678, 4), 3456);
    assert_equals("test_trim", middlesquare::trim_middle(123456789, 4), 3456);
    assert_equals("test_trim", middlesquare::trim_middle(12, 4), 12);
    assert_equals("test_trim", middlesquare::trim_middle(1, 4), 1);
    assert_equals("test_trim", middlesquare::trim_middle(0, 4), 0);

    assert_equals("test_trim", middlesquare::trim_middle(12345678, 6), 234567);
    assert_equals("test_trim", middlesquare::trim_middle(123456780, 6), 234567);
    assert_equals("test_trim", middlesquare::trim_middle(123456789, 3), 456);
    assert_equals("test_trim", middlesquare::trim_middle(1234567890, 3), 456);
}

void run_tests() {
    test_trim();
    std::cout << "Total failures reported: " << failures << std::endl;
}

int main() {
    run_tests();
}