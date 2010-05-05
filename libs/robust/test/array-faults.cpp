/* Test case for class array.
 *
 * The original author site is at: http://saschpe.wordpress.com/
 *
 * (C) Copyright Sascha Peilicke 2010.
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * 27 April 2010 - Initial Revision (Sascha Peilicke)
 *
 * May 4th, 2010
 */

#include <boost/robust/array.hpp>

#include <iostream>
#include <cassert>

int main()
{
    robust::array<int, 64> a1;
    std::cout << "array 1: " << a1 << std::endl;

    // Insert faults and check

    return -1;
}
