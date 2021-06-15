#include <cmath>
#include <algorithm>

#include "middlesquare.hpp"

namespace middlesquare {
    Generator::Generator(const int seed): seed{seed} {}

    /**
     * Generates and returns the next random number.
     */
    int Generator::next() {
        int squared = seed * seed;

        seed = trim_middle(squared, 4);

        // Seed is the next random number.
        return seed;
    }

    /**
     * Trim the source number to given digits, from the middle of the source number.
     * Examples:
     * trim(12345678, 4) => 3456
     * trim(1234567, 4) => 2345
     */
    int trim_middle(const int source, const int to_digits) {

        int digits = (floor(log10(source)) + 1); // Counting digits in the number. See: https://stackoverflow.com/questions/10886413/get-number-of-digits-of-a-number

        // Pointless case
        if (to_digits >= digits) {
            return source;
        }

        // Digits to remove from both the right
        int bonds = std::ceil(float(digits - to_digits) / 2);
        
        // Discard digits from right
        int t = source / pow(10, bonds);

        // Get the required digits
        return t % int(std::pow(10, to_digits));
    }
}