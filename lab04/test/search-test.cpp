#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "arrays.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void testFirst(void) {
            const int iarray[] = {0, 1, 2, 3, 4, 5};
            TS_ASSERT(search(iarray, 6, 1) == 1);
            /* Fill in some test cases here for cxx test gen */
        }
        void testSecond(void) {
            const int iarray[] = {0, 11, 2, 3, 4, 5};
            TS_ASSERT(search(iarray, 6, 3) == 3);
            /* Fill in some test cases here for cxx test gen */
        }
};

