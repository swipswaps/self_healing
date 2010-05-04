
// Copyright Sascha Peilicke <sasch.pe@gmx.de> 2010.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "../array.h"

#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    robust::array<int> c1;
    cout << "array 1: " << c1 << endl;

    // Insert faults and check

    return -1;
}
