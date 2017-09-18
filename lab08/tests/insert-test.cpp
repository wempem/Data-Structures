#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "array.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            /* Fill in some test cases here for cxx test gen */
            int ary1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            int ary2[] = {};
            Array<int> iary1(ary1, 10);
            Array<int> iary2(ary2, 0);
            for (int i = 0; i < 10; i++) {
                iary2.insert(i, i);
            }
            for (int i = 0; i < 10; i++) {
                TS_ASSERT(iary1.get(i) == i);
            }
        }
        void test2(void) {
            int ary1[] = {0, -1, 2, 3, 4, 5, 6, 7, 8, 9};
            Array<int> iary1(ary1, 10);
            iary1.insert(0, 100);
            TS_ASSERT(iary1.get(0) == 100);
            TS_ASSERT(iary1.get(1) == 0);
        }

};

