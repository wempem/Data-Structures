#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "IntArray.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int a[] = {0, 1, 2, 3, 4, 5};
            IntArray ary1(a, 6);
            TS_ASSERT(ary1.getLength() == 6);
            /* Fill in some test cases here for cxx test gen */
        }
};

