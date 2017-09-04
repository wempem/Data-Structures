#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "arrays.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void testNoNegatives(void) {
            const int iarray[] = {0, 1, 2, 3, 4, 5};
            TS_ASSERT_EQUALS(countNegatives(iarray, 6), 0);
            /* Fill in some test cases here for cxx test gen */
        }
        void test1Negatives(void) {
            const int iarray[] = {0, 1, -2, 3, 4, 5};
            TS_ASSERT_EQUALS(countNegatives(iarray, 6), 1);
            /* Fill in some test cases here for cxx test gen */
        }
};

