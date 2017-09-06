#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "IntArray.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            IntArray DUT(array, 10);
            TS_ASSERT_EQUALS(DUT.get(0), 1);
            TS_ASSERT_EQUALS(DUT.get(5), 6);
            /* Fill in some test cases here for cxx test gen */
        }
};

