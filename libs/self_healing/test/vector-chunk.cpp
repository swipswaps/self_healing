/* Test case for class chunk.
 *
 * The original author site is at: http://saschpe.wordpress.com/
 *
 * (C) Copyright Sascha Peilicke 2010.
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * 28 April 2010 - Initial Revision (Sascha Peilicke)
 */

#include <boost/self_healing/detail/vector_chunk.hpp>
#include <boost/self_healing/vector.hpp>

#include <iostream>

int main()
{
    std::cout << "testing class boost::self_healing::chunk" << std::endl;

    // create a chunk instance with whatever we want as parent
    boost::self_healing::vector<int, 4> parent;
    boost::self_healing::vector_chunk<int, 4> c(&parent, 43);

    std::cout << "parent: " << &parent << std::endl;
    std::cout << "chunk is valid: " << c.is_valid() << std::endl;
    std::cout << "chunk parent: " << c.parent() << std::endl;
    std::cout << "chunk is valid (with parent " << &parent << "): " << c.is_valid(&parent) << std::endl;

    std::cout << "setting a different parent" << std::endl;
    boost::self_healing::vector<int, 4> another_parent;
    c.setParent(&another_parent);

    std::cout << "parent: " << &another_parent << std::endl;
    std::cout << "chunk is valid: " << c.is_valid() << std::endl;
    std::cout << "chunk parent: " << c.parent() << std::endl;
    std::cout << "chunk is valid (with parent " << &another_parent << "): " << c.is_valid(&another_parent) << std::endl;

    std::cout << "chunk: " << c << std::endl;
    return 0;
}
