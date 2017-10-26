#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "binarytree.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            BinaryTree bt;
            bt.insert(12);
            bt.insert(4);
            bt.insert(8);
            bt.insert(9000);
            TS_ASSERT(bt.exists(12));
            TS_ASSERT(!bt.exists(-100));
        }
};

