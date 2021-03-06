/* Test case for class vector.
 *
 * (C) Copyright Sascha Peilicke 2010.
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * 28 April 2010 - Initial Revision (Sascha Peilicke)
 */

#include "utility.hpp"

#include <boost/self_healing/vector.hpp>

#include <iostream>

using namespace boost;
using namespace std;

int main()
{
    cout << "testing class boost::self_healing::vector<> fault injection" << endl;

    // bit flip tests
    for (size_t bit_flips = 1; bit_flips <= 4; bit_flips++) {
        size_t still_valid = 0;
        for (size_t i = 0; i < utility::AMOUNT_OF_TESTS; i++) {
            self_healing::vector<int> tmp(utility::AMOUNT_OF_ELEMENTS);
            utility::flip_bits(&tmp, sizeof(tmp), bit_flips);
            try {
                if (tmp.is_valid()) { still_valid++; }
            } catch (...) {}
        }
        cout << "vector<int>(" << utility::AMOUNT_OF_ELEMENTS << "): " << still_valid << " out of "
             << utility::AMOUNT_OF_TESTS << " are still valid for " << bit_flips << " bit flip(s)." << endl;
    }
    for (size_t bit_flips = 1; bit_flips <= 4; bit_flips++) {
        size_t still_valid = 0;
        for (size_t i = 0; i < utility::AMOUNT_OF_TESTS; i++) {
            self_healing::vector<int> tmp(utility::AMOUNT_OF_ELEMENTS);
            utility::flip_bits(&tmp, sizeof(tmp), bit_flips);
            try {
                if (tmp.is_valid()) { still_valid++; }
            } catch (...) {}
        }
        cout << "vector<int>(" << utility::AMOUNT_OF_ELEMENTS << "): " << still_valid << " out of "
             << utility::AMOUNT_OF_TESTS << " are still valid for " << bit_flips << " bit flip(s)." << endl;
    }

    // burst tests
    for (size_t burst_length = 4; burst_length <= 16; burst_length *= 2) {
        size_t still_valid = 0;
        for (size_t i = 0; i < utility::AMOUNT_OF_TESTS; i++) {
            self_healing::vector<int> tmp(utility::AMOUNT_OF_ELEMENTS);
            utility::burst_flip_bits(&tmp, sizeof(tmp), burst_length);
            try {
                if (tmp.is_valid()) { still_valid++; }
            } catch (...) {}
        }
        cout << "vector<int>(" << utility::AMOUNT_OF_ELEMENTS << "): " << still_valid << " out of "
             << utility::AMOUNT_OF_TESTS << " are still valid for burst of length " << burst_length << endl;
    }
    for (size_t burst_length = 4; burst_length <= 16; burst_length *= 2) {
        size_t still_valid = 0;
        for (size_t i = 0; i < utility::AMOUNT_OF_TESTS; i++) {
            self_healing::vector<int> tmp(utility::AMOUNT_OF_ELEMENTS);
            utility::burst_flip_bits(&tmp, sizeof(tmp), burst_length);
            try {
                if (tmp.is_valid()) { still_valid++; }
            } catch (...) {}
        }
        cout << "vector<int>(" << utility::AMOUNT_OF_ELEMENTS << "): " << still_valid << " out of "
             << utility::AMOUNT_OF_TESTS << " are still valid for burst of length " << burst_length << endl;
    }

    return 0;
}
