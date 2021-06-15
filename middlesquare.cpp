#include <cmath>
#include <algorithm>

#include "middlesquare.hpp"

namespace middlesquare {
    Generator::Generator(const int seed): seed{seed} {
        this->invalidate_seed();
    }

    /**
     * Generates and returns the next random number.
     */
    int Generator::next() {
        int squared = pad(seed * seed, 8);

        seed = (squared / 100) % 10000; // Save xx(xxxx)xx of the squared as new seed
        invalidate_seed();

        // Seed is the next random number.
        return seed;
    }

    /**
     * Invalidates seed by-
     * - Making sure it's not negative.
     * - Making sure it takes exactly 4 decimal digits.
     */
    void Generator::invalidate_seed() {
        // Make sure seed > 0
        seed = abs(seed);

        // Make sure seed does not exceed 4 digits
        seed = std::min(seed % 10000, 9999);

        // Pad with zeros
        seed = pad(seed, 4);
    }

    /**
     * Pads the source number with zeros to makes sure it contains atleast `digit` digits
     */
    int pad(const int source, const int digits) {

        // Calculate zeros to pad
        int zeros =
            digits -
            (floor(log10(source)) + 1); // Counting digits in the number. See: https://stackoverflow.com/questions/10886413/get-number-of-digits-of-a-number

        if (zeros > 0) {
            return source * (std::pow(10, zeros));
        }

        return source;
    }
}